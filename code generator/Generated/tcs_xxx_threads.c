/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tcs_xxx_threads.c
  * @brief   Código de inicialización de hilos para tcs_xxx.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 TECNA PERU S.A.C.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "tcs_xxx_threads.h"

/* USER CODE BEGIN 0 */

extern uint8_t osPoolInit(void *pointer);

  /* Declaración de handles ThreadX para cada tarea */
OsTaskId wifi_thread;
OsTaskId display_thread;
OsTaskId data_thread;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* threads tcs_xxx                                                     */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/**
  * @brief thread initialize function
  * @param memory: puntero a TX_BYTE_POOL u otro recurso para asignar pilas
  * @retval TX_SUCCESS si todo OK, error en otro caso
  */
error_t tcs_xxx_tasks_initialize(void *memory) {
    /* Local variables -------------------------------------------------------*/
    OsTaskParameters params = OS_TASK_DEFAULT_PARAMS;
    error_t ret = ERROR_NONE;

    /*ospool mem init*/
    osPoolInit(memory);

    /* Crear hilos según configuración */

    /* task wifi */
    params = OS_TASK_DEFAULT_PARAMS;
    params.priority = TCS_XXX_WIFI_PRIORITY;
    params.stackSize = TCS_XXX_WIFI_STACK_SIZE;

    wifi_thread = osCreateTask("wifi", 
                              tcs_xxx_wifi_entry, 
                              TCS_XXX_WIFI_PARAMS, 
                              &params);

    /* Check wifi thread creation */
    if(wifi_thread == NULL)
    {
      ret = ERROR_FAILURE;
      return ret;
    }
    

    /* task display */
    params = OS_TASK_DEFAULT_PARAMS;
    params.priority = TCS_XXX_DISPLAY_PRIORITY;
    params.stackSize = TCS_XXX_DISPLAY_STACK_SIZE;

    display_thread = osCreateTask("display", 
                              tcs_xxx_display_entry, 
                              TCS_XXX_DISPLAY_PARAMS, 
                              &params);

    /* Check display thread creation */
    if(display_thread == NULL)
    {
      ret = ERROR_FAILURE;
      return ret;
    }
    

    /* task data */
    params = OS_TASK_DEFAULT_PARAMS;
    params.priority = TCS_XXX_DATA_PRIORITY;
    params.stackSize = TCS_XXX_DATA_STACK_SIZE;

    data_thread = osCreateTask("data", 
                              tcs_xxx_data_entry, 
                              TCS_XXX_DATA_PARAMS, 
                              &params);

    /* Check data thread creation */
    if(data_thread == NULL)
    {
      ret = ERROR_FAILURE;
      return ret;
    }
    

    return ret;
}

/* Entry functions for cada tarea */
/**
  * @brief  Entry para la tarea wifi
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_WIFI_PARAMS
  * @retval none
  */
__weak void tcs_xxx_wifi_entry(void *param) {
    /* init o variables locales si se necesita */
    for (;;) {
        osDelayTask(1000);
    }
}
/**
  * @brief  Entry para la tarea display
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_DISPLAY_PARAMS
  * @retval none
  */
__weak void tcs_xxx_display_entry(void *param) {
    /* init o variables locales si se necesita */
    for (;;) {
        osDelayTask(1000);
    }
}
/**
  * @brief  Entry para la tarea data
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_DATA_PARAMS
  * @retval none
  */
__weak void tcs_xxx_data_entry(void *param) {
    /* init o variables locales si se necesita */
    for (;;) {
        osDelayTask(1000);
    }
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */