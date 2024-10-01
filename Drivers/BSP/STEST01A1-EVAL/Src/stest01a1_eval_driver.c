/**
  ******************************************************************************
  * @file    stest01a1_eval_driver.c
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

/* Includes ------------------------------------------------------------------*/
#include "stest01a1_eval_driver.h"

/* Private variables ---------------------------------------------------------*/

/** @defgroup Private Variables
 * @{
 */


/**
 * @}
 */

/* Exported variables --------------------------------------------------------*/
_Bool STEST01A1_FLT1 = 0;
_Bool STEST01A1_FLT2 = 0;
double DEMAG_TICKS = 0;

/* Exported functions --------------------------------------------------------*/

void STEST01A1_OUT_ON() {
	HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_SET);
}

void STEST01A1_OUT_OFF() {
	HAL_GPIO_WritePin(OUT_CTRL_GPIO_Port, OUT_CTRL_Pin, GPIO_PIN_RESET);
}

void STEST01A1_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	STEST01A1_FLT1 = 0;
	STEST01A1_FLT2 = 0;
	if (GPIO_Pin == OUT_FLT1_Pin) {
		STEST01A1_FLT1 = 1;
	} else if (GPIO_Pin == OUT_FLT2_Pin) {
		STEST01A1_FLT2 = 1;
	}
}

//void STEST01A1_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
//	if (htim->Instance == TIM2) {
//		HAL_TIM_IC_Stop_IT(htim, TIM_CHANNEL_2);
//		uint32_t ticks = __HAL_TIM_GET_COUNTER(htim);
//		__HAL_TIM_SET_COUNTER(htim, 0);
//		DEMAG_TICKS = ticks > DEMAG_TICKS ? ticks : DEMAG_TICKS;
//		HAL_TIM_IC_Start_IT(htim, TIM_CHANNEL_2);
//	}
//}
