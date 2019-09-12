#include "drv_button_api.h"

#ifdef _MSC_VER
#include "drv_button_x86.h"
#elif defined __UVISION_VERSION
#include "drv_button_arm.h"
#endif

uint8_t buttonIsPressed(void){
#ifdef _MSC_VER
    return buttonIsPressed_x86();
#elif defined __UVISION_VERSION
    return buttonIsPressed_arm();
#endif
}