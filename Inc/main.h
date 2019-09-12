#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "task.h"

#ifdef _MSC_VER
#include <stdio.h>
#endif /*_MSC_VER*/

#ifdef __UVISION_VERSION
#undef _MSC_VER

#include "cmsis_os.h"
#include "stm32l0xx_hal.h"

#define USERBUTTON_Pin GPIO_PIN_13
#define USERBUTTON_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#endif /*__UVISION_VERSION*/

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
