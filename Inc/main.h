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
#include "stm32f4xx_hal.h"

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
#define B1_USER_Pin GPIO_PIN_13
#define B1_USER_GPIO_Port GPIOC
#define B1_USER_EXTI_IRQn EXTI15_10_IRQn
#define OUTP2_Pin GPIO_PIN_1
#define OUTP2_GPIO_Port GPIOH
#define OUTP2_EXTI_IRQn EXTI1_IRQn
#define OUTP1_Pin GPIO_PIN_0
#define OUTP1_GPIO_Port GPIOC
#define OUTP1_EXTI_IRQn EXTI0_IRQn
#define D12_USER_LED_GREEN_Pin GPIO_PIN_2
#define D12_USER_LED_GREEN_GPIO_Port GPIOC
#define D13_USER_LED_RED_Pin GPIO_PIN_3
#define D13_USER_LED_RED_GPIO_Port GPIOC
#define LD2_USER_Pin GPIO_PIN_5
#define LD2_USER_GPIO_Port GPIOA
#define COFF2_CTRL_Pin GPIO_PIN_5
#define COFF2_CTRL_GPIO_Port GPIOC
#define SPI_NCS_Pin GPIO_PIN_12
#define SPI_NCS_GPIO_Port GPIOB
#define SPI_SCLK_Pin GPIO_PIN_13
#define SPI_SCLK_GPIO_Port GPIOB
#define OUT2_DIAG_Pin GPIO_PIN_6
#define OUT2_DIAG_GPIO_Port GPIOC
#define OUT2_DIAG_EXTI_IRQn EXTI9_5_IRQn
#define VCC1_DSC_Pin GPIO_PIN_8
#define VCC1_DSC_GPIO_Port GPIOC
#define OUT2_DSC_Pin GPIO_PIN_9
#define OUT2_DSC_GPIO_Port GPIOC
#define OUT2_CTRL_Pin GPIO_PIN_11
#define OUT2_CTRL_GPIO_Port GPIOA
#define VCC1_CTRL_Pin GPIO_PIN_12
#define VCC1_CTRL_GPIO_Port GPIOA
#define TP1_CTRL_Pin GPIO_PIN_15
#define TP1_CTRL_GPIO_Port GPIOA
#define OUT1_DSC_Pin GPIO_PIN_10
#define OUT1_DSC_GPIO_Port GPIOC
#define VCC2_DSC_Pin GPIO_PIN_11
#define VCC2_DSC_GPIO_Port GPIOC
#define OUT1_DIAG_Pin GPIO_PIN_12
#define OUT1_DIAG_GPIO_Port GPIOC
#define OUT1_DIAG_EXTI_IRQn EXTI15_10_IRQn
#define COFF1_CTRL_Pin GPIO_PIN_2
#define COFF1_CTRL_GPIO_Port GPIOD
#define TP2_CTRL_Pin GPIO_PIN_7
#define TP2_CTRL_GPIO_Port GPIOB
#define OUT1_CTRL_Pin GPIO_PIN_8
#define OUT1_CTRL_GPIO_Port GPIOB
#define VCC2_CTRL_Pin GPIO_PIN_9
#define VCC2_CTRL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
