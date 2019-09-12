#include <stdint.h>
#include "led_internal.h"
#include "drv_led_api.h"

#ifdef _MSC_VER
#include "drv_led_x86.h"
#elif defined __UVISION_VERSION
#include "drv_led_arm.h"
#endif


void apiLED_Toggle(/*struct */tLedState_t* t)
{
#ifdef _MSC_VER
	apiLED_Toggle_x86(t);
#elif defined __UVISION_VERSION
	apiLED_Toggle_arm(t);
#endif
}

const TickType_t x10_ms = pdMS_TO_TICKS(10);
const TickType_t x100_ms = pdMS_TO_TICKS(100);

static uint32_t idLED = 0;

#define LED_INITIAL_DELAY		400

// Internal functions
static uint8_t isDecrementValueReceive(tLedState_t* t)
{
	uint32_t ucRxData_temp[1] = {0};
	if (xMessageBufferReceive(t->xMessageBuffer, (void*)ucRxData_temp, sizeof ucRxData_temp, x10_ms) > 0)
	{
		t->ucRxData[0] = ucRxData_temp[0];
		return 1;
	}
	t->ucRxData[0] = 0;
	return 0;
}


//API functions
void apiLED_Init(tLedState_t** t)
{
	//tLedState_t *t = t1;
	*t = (tLedState_t*)pvPortMalloc(sizeof(tLedState_t));

	(*t)->ucRxData[0] = 0;
	(*t)->xMessageBuffer = xMessageBufferCreate(configMESSAGE_BUFFER_SIZE);
	(*t)->delay = LED_INITIAL_DELAY;

	idLED++;
	(*t)->id = idLED;
}

void apiLED_DeInit(/*struct */tLedState_t* t)
{
	vPortFree((void*)t);
}

void apiLED_SendDecrementValue(tLedState_t* t, uint32_t* decValToSend)
{
	xMessageBufferSend(t->xMessageBuffer, (void*)decValToSend, sizeof(uint32_t), x100_ms);
}


void apiLED_UpdateDelayByButtonPress(tLedState_t* t)
{
	if (isDecrementValueReceive(t))
	{
		if (t->delay > 50)
			t->delay -= t->ucRxData[0];
	}
}

uint32_t apiLED_GetDelay(tLedState_t* t)
{
	return t->delay;
}
