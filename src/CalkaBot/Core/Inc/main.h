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
#define LED_BUILTIN_Pin GPIO_PIN_13
#define LED_BUILTIN_GPIO_Port GPIOC
#define PWMA_Pin GPIO_PIN_1
#define PWMA_GPIO_Port GPIOA
#define Ma2_Pin GPIO_PIN_2
#define Ma2_GPIO_Port GPIOA
#define Ma1_Pin GPIO_PIN_3
#define Ma1_GPIO_Port GPIOA
#define STBY_Pin GPIO_PIN_4
#define STBY_GPIO_Port GPIOA
#define Mb1_Pin GPIO_PIN_5
#define Mb1_GPIO_Port GPIOA
#define Mb2_Pin GPIO_PIN_6
#define Mb2_GPIO_Port GPIOA
#define PWMB_Pin GPIO_PIN_7
#define PWMB_GPIO_Port GPIOA
#define DIS_R_Pin GPIO_PIN_10
#define DIS_R_GPIO_Port GPIOB
#define DIS_L_Pin GPIO_PIN_11
#define DIS_L_GPIO_Port GPIOB
#define INT_Pin GPIO_PIN_4
#define INT_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
