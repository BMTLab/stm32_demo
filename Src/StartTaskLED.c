#include "StartTaskLED.h"


/* Header_StartTaskLED */
/**
  * @brief  Function implementing the TaskButton thread.
  * @param  argument: Not used 
  * @retval None
  */
/* Header_StartTaskLED */

static tLedState_t *led1;

extern tLedState_t* getLEDObject(void)
{
	return led1;
}

void StartTaskLED(void const * argument)
{
	apiLED_Init(&led1);

	for (;;)
	{
		apiLED_UpdateDelayByButtonPress(led1);
		apiLED_Toggle(led1);
		vTaskDelay(apiLED_GetDelay(led1));
	}
}
