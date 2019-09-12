
#include "drv_led_api.h"
#include <stdint.h>
#include <stdio.h>
#include <conio.h>

#define LED_DECREMENT_VAL 50

#ifdef _MSC_VER
#define mainREGION_1_SIZE	7201
#define mainREGION_2_SIZE	29905
#define mainREGION_3_SIZE	6407

static void  prvInitialiseHeap(void)
{
	/* The xHeapRegions structure requires the regions to be defined in start address
	order, so this just creates one big array, then populates the structure with
	offsets into the array - with gaps in between and messy alignment just for test
	purposes. */
	static uint8_t ucHeap[configTOTAL_HEAP_SIZE];
	volatile uint32_t ulAdditionalOffset = 19; /* Just to prevent 'condition is always true' warnings in configASSERT(). */
	const HeapRegion_t xHeapRegions[] =
	{
		/* Start address with dummy offsets						Size */
		{ ucHeap + 1,											mainREGION_1_SIZE },
		{ ucHeap + 15 + mainREGION_1_SIZE,						mainREGION_2_SIZE },
		{ ucHeap + 19 + mainREGION_1_SIZE + mainREGION_2_SIZE,	mainREGION_3_SIZE },
		{ NULL, 0 }
	};

	/* Sanity check that the sizes and offsets defined actually fit into the
	array. */
	configASSERT((ulAdditionalOffset + mainREGION_1_SIZE + mainREGION_2_SIZE + mainREGION_3_SIZE) < configTOTAL_HEAP_SIZE);

	/* Prevent compiler warnings when configASSERT() is not defined. */
	(void)ulAdditionalOffset;

	vPortDefineHeapRegions(xHeapRegions);
}
#endif /*_MSC_VER*/



void StartTaskUT(void const *pvParameters) {
	tLedState_t* ledState = 0;
	int ret = 0;
	int32_t decVal = LED_DECREMENT_VAL;
	uint32_t delay = 400;

	// Test 1 - apiLED_Init()
	apiLED_Init(&ledState);
	if (ledState == NULL) {
		ret = -1;
		printf("Unable to allocate tLedState_t, return = %d", ret);
	}


	// Test 2 - apiLED_SendDecrementValue() apiLED_IsDecrementValueReceive()
	if (ret == 0) {
		uint32_t delay, i, delay_ref = 400;

		for (i = 0; i < 10; ++i) {
			delay_ref -= 50;
			if (delay_ref < 50) delay_ref = 50;

			apiLED_SendDecrementValue(ledState, &decVal);	// 'Button press'
			apiLED_UpdateDelayByButtonPress(ledState);		// Decrement delay
			if ((delay = apiLED_GetDelay(ledState)) != delay_ref) {
				ret = -2;
				printf("Bad delay value: %d, must be %d, return = %d", delay, delay_ref, ret);
			}
		}
	}

	apiLED_DeInit(ledState);

	if (ret == 0)
		printf("UT successful, return = %d", ret);

	_getch();

}

int main(void) {

#ifdef _MSC_VER
	prvInitialiseHeap();
#endif /*_MSC_VER*/

	xTaskCreate(StartTaskUT, "UT", configMINIMAL_STACK_SIZE * 8, NULL, 1, NULL);

	vTaskStartScheduler();

	for (;;);

	
	//return ret;
}