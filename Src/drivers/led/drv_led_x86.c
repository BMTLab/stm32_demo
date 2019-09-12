#include <stdio.h>
#include "drv_led_api.h"

void apiLED_Toggle_x86(tLedState_t *t)
{
	printf("\nLed (id = %u) switch (period = %u ms)", t->id, t->delay);
}
