/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define yellow_Pin GPIO_PIN_13
#define yellow_GPIO_Port GPIOC
#define blue_Pin GPIO_PIN_14
#define blue_GPIO_Port GPIOC
#define red_Pin GPIO_PIN_1
#define red_GPIO_Port GPIOA
#define F_Pin GPIO_PIN_12
#define F_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_13
#define E_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_14
#define D_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_15
#define C_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_8
#define B_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_11
#define A_GPIO_Port GPIOA
#define G_Pin GPIO_PIN_12
#define G_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_15
#define DOT_GPIO_Port GPIOA
#define COM3_Pin GPIO_PIN_3
#define COM3_GPIO_Port GPIOB
#define COM1_Pin GPIO_PIN_8
#define COM1_GPIO_Port GPIOB
#define COM2_Pin GPIO_PIN_9
#define COM2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
