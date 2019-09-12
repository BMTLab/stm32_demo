#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#ifdef __UVISION_VERSION
#undef _MSC_VER
#endif /*__UVISION_VERSION*/
/*----------------------------------------------------------*/
/* Ensure stdint is only used by the compiler, and not the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
    #include <stdint.h>
    extern uint32_t SystemCoreClock;
#endif

#define configUSE_PREEMPTION                    1
#define configSUPPORT_STATIC_ALLOCATION         0
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configUSE_IDLE_HOOK						0
#define configUSE_TICK_HOOK						0
#define configCPU_CLOCK_HZ                      ( SystemCoreClock )
#define configTICK_RATE_HZ                      ( ( TickType_t) 1000 )
#define configMAX_PRIORITIES                    ( 7 )

#ifdef _MSC_VER
#define configMINIMAL_STACK_SIZE				( ( uint16_t ) 70 ) 
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 45 * 1024 ) )
#define configQUEUE_REGISTRY_SIZE				20
#endif /*MSC_VER*/

#ifdef __UVISION_VERSION
#define configMINIMAL_STACK_SIZE                ( ( uint16_t  ) 128 )
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 3 * 1024 ) )
#define configQUEUE_REGISTRY_SIZE				8
#endif /*__UVISION_VERSION*/

#define configMAX_PRIORITIES					( 7 )
#define configMAX_TASK_NAME_LEN                 ( 16 )
#define configUSE_16_BIT_TICKS                   0
#define configUSE_MUTEXES                        1
#define configMESSAGE_BUFFER_SIZE				 8 /* Added manualy */

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                    0
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskCleanUpResources       0
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelayUntil             0
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_xTaskGetSchedulerState      1

#ifdef _MSC_VER
#define configUSE_STATS_FORMATTING_FUNCTIONS	1
#define INCLUDE_uxTaskGetStackHighWaterMark		1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle	1
#define INCLUDE_xTaskGetIdleTaskHandle			1
#define INCLUDE_xTaskGetHandle					1
#define INCLUDE_eTaskGetState					1
#define INCLUDE_xSemaphoreGetMutexHolder		1
#define INCLUDE_xTimerPendFunctionCall			1
#define INCLUDE_xTaskAbortDelay					1

#define configUSE_TIMERS						1
#define configTIMER_TASK_PRIORITY				( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH				20
#define configTIMER_TASK_STACK_DEPTH			( configMINIMAL_STACK_SIZE * 2 )
#endif /*MSC_VER*/

/* configASSERT definition */
#define configASSERT( x ) if ((x) == 0) {taskDISABLE_INTERRUPTS(); for( ;; );} 

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler    SVC_Handler
#define xPortPendSVHandler PendSV_Handler

/* IMPORTANT: This define is commented when used with STM32Cube firmware, when the timebase source is SysTick,
              to prevent overwriting SysTick_Handler defined within STM32Cube HAL */
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
