/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MyProject_tasks.h
  *
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TASKS_H
#define __TASKS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tx_api.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MyProject_tasks_config.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported variables --------------------------------------------------------*/
  /* Declaración de hilos ThreadX para cada tarea */
extern TX_THREAD TaskOne_thread;
extern TX_THREAD TaskTwo_thread;
extern TX_THREAD TaskThree_thread;

/* Exported functions prototypes ---------------------------------------------*/

/**
  * @brief MyProject thread create/init function
  * @param memory: puntero a área de memoria para control blocks u otros recursos necesarios
  * @retval TX_SUCCESS si la creación fue exitosa, otro código en caso de error
  */
UINT MyProject_threads_initialize(void *memory);

/**
  * @brief  Entry function para la tarea TaskOne
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKONE_PARAMS
  * @retval none
  */
void MyProject_TaskOne_entry(ULONG param);
/**
  * @brief  Entry function para la tarea TaskTwo
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKTWO_PARAMS
  * @retval none
  */
void MyProject_TaskTwo_entry(ULONG param);
/**
  * @brief  Entry function para la tarea TaskThree
  * @param  param: valor definido en MyProject_tasks_config.h como MYPROJECT_TASKTHREE_PARAMS
  * @retval none
  */
void MyProject_TaskThree_entry(ULONG param);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __TASKS_H */