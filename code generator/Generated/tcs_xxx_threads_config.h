/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : tcs_xxx_threads_config.h
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
#ifndef __THREADS_CONFIG_H
#define __THREADS_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "os_port.h"
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
/* Definiciones para la tarea wifi */
#define TCS_XXX_WIFI_STACK_SIZE    1024
#define TCS_XXX_WIFI_PRIORITY      10
#define TCS_XXX_WIFI_PARAMS        (ULONG)&memory

/* Definiciones para la tarea display */
#define TCS_XXX_DISPLAY_STACK_SIZE    1024
#define TCS_XXX_DISPLAY_PRIORITY      11
#define TCS_XXX_DISPLAY_PARAMS        0

/* Definiciones para la tarea data */
#define TCS_XXX_DATA_STACK_SIZE    1024
#define TCS_XXX_DATA_PRIORITY      10
#define TCS_XXX_DATA_PARAMS        0


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __THREADS_CONFIG_H */