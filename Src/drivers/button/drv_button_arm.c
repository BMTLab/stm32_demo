#include "drv_button_arm.h"
#include "hwconfig_button.h"

uint8_t buttonIsPressed_arm(void)
{
	if (HAL_GPIO_ReadPin(USERBUTTON_GPIO_Port, USERBUTTON_Pin) == GPIO_PIN_RESET)
		return 1;
	else
		return 0;
}
