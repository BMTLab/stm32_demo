#ifndef LED_INTERNAL_H
#define LED_INTERNAL_H

#include "FreeRTOS.h"
#include "task.h"
#include "message_buffer.h"

struct tLedState
{
	uint32_t delay;
	MessageBufferHandle_t xMessageBuffer;
	uint32_t ucRxData[1];
	uint32_t id;
};

#endif //LED_INTERNAL_H


