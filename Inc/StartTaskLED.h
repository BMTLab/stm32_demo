#ifndef STARTTASKLED_H_INCLUDED
#define STARTTASKLED_H_INCLUDED

#include "drv_led_api.h"

#ifdef __cplusplus
extern "C" {
#endif

tLedState_t* getLEDObject(void);

// Prototypes for the thread
void StartTaskLED(void const * argument);

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif
