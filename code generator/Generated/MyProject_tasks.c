/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    MyProject_tasks.c
  * @brief   Código de inicialización de hilos para MyProject.
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
#include "MyProject_tasks.h"

/* USER CODE BEGIN 0 */
  /* Declaración de handles ThreadX para cada tarea */
TX_THREAD TaskOne_thread;
TX_THREAD TaskTwo_thread;
TX_THREAD TaskThree_thread;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* threads MyProject                                                     */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/**
  * @brief thread initialize function
  * @param memory: puntero a TX_BYTE_POOL u otro recurso para asignar pilas
  * @retval TX_SUCCESS si todo OK, error en otro caso
  */
UINT MyProject_threads_initialize(void *memory) {
    /* Local variables -------------------------------------------------------*/
    CHAR *pointer;
    TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL *)memory;
    UINT ret = TX_SUCCESS;

    /* Crear hilos según configuración */
    /* Allocate the stack for TaskOne thread */
    if (tx_byte_allocate(byte_pool, (VOID **)&pointer,
        MYPROJECT_TASKONE_STACK_SIZE,
        TX_NO_WAIT) != TX_SUCCESS)
    {
        return TX_POOL_ERROR;
    }

    /* Create TaskOne thread */
    if (tx_thread_create(
            &TaskOne_thread,
            "TaskOne",
            MyProject_TaskOne_entry,
            MYPROJECT_TASKONE_PARAMS,
            pointer,
            MYPROJECT_TASKONE_STACK_SIZE,
            MYPROJECT_TASKONE_PRIORITY,
            MYPROJECT_TASKONE_PRIORITY,
            TX_NO_TIME_SLICE,
            MYPROJECT_TASKONE_AUTO_START) != TX_SUCCESS)
    {
        return TX_THREAD_ERROR;
    }
    /* Allocate the stack for TaskTwo thread */
    if (tx_byte_allocate(byte_pool, (VOID **)&pointer,
        MYPROJECT_TASKTWO_STACK_SIZE,
        TX_NO_WAIT) != TX_SUCCESS)
    {
        return TX_POOL_ERROR;
    }

    /* Create TaskTwo thread */
    if (tx_thread_create(
            &TaskTwo_thread,
            "TaskTwo",
            MyProject_TaskTwo_entry,
            MYPROJECT_TASKTWO_PARAMS,
            pointer,
            MYPROJECT_TASKTWO_STACK_SIZE,
            MYPROJECT_TASKTWO_PRIORITY,
            MYPROJECT_TASKTWO_PRIORITY,
            TX_NO_TIME_SLICE,
            MYPROJECT_TASKTWO_AUTO_START) != TX_SUCCESS)
    {
        return TX_THREAD_ERROR;
    }
    /* Allocate the stack for TaskThree thread */
    if (tx_byte_allocate(byte_pool, (VOID **)&pointer,
        MYPROJECT_TASKTHREE_STACK_SIZE,
        TX_NO_WAIT) != TX_SUCCESS)
    {
        return TX_POOL_ERROR;
    }

    /* Create TaskThree thread */
    if (tx_thread_create(
            &TaskThree_thread,
            "TaskThree",
            MyProject_TaskThree_entry,
            MYPROJECT_TASKTHREE_PARAMS,
            pointer,
            MYPROJECT_TASKTHREE_STACK_SIZE,
            MYPROJECT_TASKTHREE_PRIORITY,
            MYPROJECT_TASKTHREE_PRIORITY,
            TX_NO_TIME_SLICE,
            MYPROJECT_TASKTHREE_AUTO_START) != TX_SUCCESS)
    {
        return TX_THREAD_ERROR;
    }

    return ret;
}

/* Entry functions for cada tarea */
/**
  * @brief  Entry para la tarea TaskOne
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKONE_PARAMS
  * @retval none
  */
__weak void MyProject_TaskOne_entry(ULONG param) {
    /* init o variables locales si se necesita */
    for (;;) {
        tx_thread_sleep(1000);
    }
}
/**
  * @brief  Entry para la tarea TaskTwo
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKTWO_PARAMS
  * @retval none
  */
__weak void MyProject_TaskTwo_entry(ULONG param) {
    /* init o variables locales si se necesita */
    for (;;) {
        tx_thread_sleep(1000);
    }
}
/**
  * @brief  Entry para la tarea TaskThree
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKTHREE_PARAMS
  * @retval none
  */
__weak void MyProject_TaskThree_entry(ULONG param) {
    /* init o variables locales si se necesita */
    for (;;) {
        tx_thread_sleep(1000);
    }
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */