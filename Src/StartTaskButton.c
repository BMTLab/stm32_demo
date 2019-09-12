#include "StartTaskButton.h"
#include "StartTaskLED.h"

#include "drv_button_api.h"
#include "drv_led_api.h"

/* Header_StartTaskButton */
/**
  * @brief  Function implementing the TaskButton thread.
  * @param  argument: Not used 
  * @retval None
  */
/* Header_StartTaskButton */

static uint32_t decValToSend = 50;

void StartTaskButton(void const * argument)
{
	for (;;)
	{
		if (buttonIsPressed())
		{
			apiLED_SendDecrementValue((tLedState_t*)getLEDObject(), &decValToSend);
			vTaskDelay(500);
		}
	}
}

