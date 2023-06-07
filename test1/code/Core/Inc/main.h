/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"
#include "stm32f1xx.h"
#include "stm32f1xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ucos_ii.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

// armcc section utils

#define AT_SECTION(section_name)        __attribute__((section(#section_name))) __attribute__((used))
#define GET_SECTION_BEGIN(section_name) section_name##$$Base
#define GET_SECTION_END(section_name)   section_name##$$Limit
#define FOREACH_SECTION_VAR(var_type, section_name)                       \
                                                                          \
    extern uint32_t GET_SECTION_BEGIN(section_name);                      \
    extern uint32_t GET_SECTION_END(section_name);                        \
                                                                          \
    for (uint32_t var_ptr = (uint32_t)(&GET_SECTION_BEGIN(section_name)); \
         var_ptr < (uint32_t)(&GET_SECTION_END(section_name));            \
         var_ptr += sizeof(var_type))

#define FOREACH_SECTION_GET_VAR_PTR(var_type) ((var_type *)var_ptr)

// task utils

#define TASK_STK_SIZE_DEFAULT 128 // 128 words == 512 bytes

typedef void (*Task_Entry)(void *p_arg);

typedef struct {
    char       *name;
    Task_Entry  entry;
    void       *args;
    uint8_t     prio;
    OS_STK     *stack;
    uint32_t    stack_size;
    OS_STK     *stack_top;
} Task_DeclareInfo;

#define APP_SECT__TASKS_INFO sect__tasks_info

#define TaskDefineEx(task_name, entry_name, stk_size, task_prio, args_ptr)                \
    static OS_STK _app_task_stk__##entry_name[stk_size];                                  \
    void entry_name(void *);                                                              \
    static Task_DeclareInfo _app_task_info__##entry_name AT_SECTION(sect__tasks_info) = { \
        .name       = task_name,                                                          \
        .entry      = entry_name,                                                         \
        .args       = args_ptr,                                                           \
        .prio       = task_prio,                                                          \
        .stack      = _app_task_stk__##entry_name,                                        \
        .stack_size = stk_size,                                                           \
        .stack_top  = &_app_task_stk__##entry_name[stk_size - 1],                         \
    };                                                                                    \
    void entry_name(void *args)

#define TaskDefine(entry_name, task_prio, args_ptr) \
    TaskDefineEx(#entry_name, entry_name, TASK_STK_SIZE_DEFAULT, task_prio, args_ptr)

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

#define TASK_NUM 2

extern Task_DeclareInfo TASK_LIST[TASK_NUM];

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
