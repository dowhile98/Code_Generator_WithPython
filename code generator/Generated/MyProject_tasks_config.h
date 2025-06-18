/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : MyProject_tasks_config.h
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
#ifndef __TASKS_CONFIG_H
#define __TASKS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tx_api.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* Exported functions prototypes ---------------------------------------------*/
/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
/* Definiciones para la tarea TaskOne */
#define MYPROJECT_TASKONE_STACK_SIZE    1024
#define MYPROJECT_TASKONE_PRIORITY      10
#define MYPROJECT_TASKONE_PARAMS        (ULONG)&data_sensor_instance
#define MYPROJECT_TASKONE_AUTO_START  TX_DONT_START
/* Definiciones para la tarea TaskTwo */
#define MYPROJECT_TASKTWO_STACK_SIZE    1024
#define MYPROJECT_TASKTWO_PRIORITY      5
#define MYPROJECT_TASKTWO_PARAMS        0
#define MYPROJECT_TASKTWO_AUTO_START  TX_DONT_START
/* Definiciones para la tarea TaskThree */
#define MYPROJECT_TASKTHREE_STACK_SIZE    1024
#define MYPROJECT_TASKTHREE_PRIORITY      10
#define MYPROJECT_TASKTHREE_PARAMS        0
#define MYPROJECT_TASKTHREE_AUTO_START  TX_DONT_START

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __TASKS_CONFIG_H */