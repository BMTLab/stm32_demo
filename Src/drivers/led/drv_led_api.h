#ifndef DRV_LED_API_H
#define DRV_LED_API_H

#include "led_internal.h"

typedef struct tLedState tLedState_t;

/*typedef struct tLedState
{
	MessageBufferHandle_t xMessageBuffer;
	uint32_t ucRxData[1];
	uint32_t id;
} tLedState_t;*/

void apiLED_Init(tLedState_t** t1);
void apiLED_DeInit(tLedState_t* t1);
void apiLED_Toggle(tLedState_t* t);
void apiLED_SendDecrementValue(tLedState_t* t, uint32_t* decValToSend);
void apiLED_UpdateDelayByButtonPress(tLedState_t* t1);
uint32_t apiLED_GetDelay(tLedState_t* t);

#endif /*DRV_LED_API_H*/
