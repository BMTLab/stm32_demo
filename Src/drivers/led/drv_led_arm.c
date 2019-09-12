#ifndef DRV_LED_ARM_H
#define DRV_LED_ARM_H

#include "hwconfig_led.h"
#include "drv_led_api.h"

void apiLED_Toggle_arm(tLedState_t* t)
{
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}

#endif /*DRV_LED_ARM_H*/
