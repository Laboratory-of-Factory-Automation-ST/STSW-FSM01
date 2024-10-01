/**
  ******************************************************************************
  * @file    stest01a1_eval_driver.h
  * @author  ST Power Application Laboratory
  * @version V1.0.0
  * @brief   Provides functions for programmable board control and measurement
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_DRIVER_H_
#define BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

 /* Exported types -----------------------------------------------------------*/


/* Exported variables --------------------------------------------------------*/
extern _Bool STEST01A1_FLT1;
extern _Bool STEST01A1_FLT2;
extern double DEMAG_TICKS;
//extern TIM_HandleTypeDef htim2;

/* Exported constants --------------------------------------------------------*/
#define STEST01A1_ZERO_VOLTAGE_THRESHOLD		(5.0f)
#define STEST01A1_NOMINAL_VOLTAGE_THRESHOLD	(21.6f)

/* Exported functions --------------------------------------------------------*/
void STEST01A1_OUT_ON();
void STEST01A1_OUT_OFF();
void STEST01A1_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
//void STEST01A1_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#ifdef	 __cplusplus
}
#endif

#endif /* BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_DRIVER_H_ */
