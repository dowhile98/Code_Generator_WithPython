/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : tcs_xxx_threads.h
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
#ifndef __THREADS_H
#define __THREADS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "os_port.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tcs_xxx_threads_config.h"
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
extern OsTaskId wifi_thread;
extern OsTaskId display_thread;
extern OsTaskId data_thread;

/* Exported functions prototypes ---------------------------------------------*/

/**
  * @brief tcs_xxx thread create/init function
  * @param memory: puntero a área de memoria para control blocks u otros recursos necesarios
  * @retval TX_SUCCESS si la creación fue exitosa, otro código en caso de error
  */
error_t tcs_xxx_tasks_initialize(void *memory);

/**
  * @brief  Entry function para la tarea wifi
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_WIFI_PARAMS
  * @retval none
  */
void tcs_xxx_wifi_entry(void *param);
/**
  * @brief  Entry function para la tarea display
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_DISPLAY_PARAMS
  * @retval none
  */
void tcs_xxx_display_entry(void *param);
/**
  * @brief  Entry function para la tarea data
  * @param  param: valor definido en tcs_xxx_threads_config.h como TCS_XXX_DATA_PARAMS
  * @retval none
  */
void tcs_xxx_data_entry(void *param);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __THREADS_H */