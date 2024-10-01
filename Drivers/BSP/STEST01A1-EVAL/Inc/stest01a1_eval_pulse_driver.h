/**
  ******************************************************************************
  * @file    stest01a1_eval_pulse_driver.h
  * @author  ST Power Application Laboratory
  * @version V1.0.0
  * @brief   Provides functions for programmable pulse generation
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

#ifndef BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_PULSE_DRIVER_H_
#define BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_PULSE_DRIVER_H_

#include "nucleo_exports.h"
#include "stm32f4xx_hal.h"

#define OUT_TIM_HANDLE &htim3

/* STEST01A1 specific timers */
#define OUT_TIM TIM3


/* STEST01A1 specific channels */
#define OUT_TIM_CHANNEL TIM_CHANNEL_2

typedef enum stest01a1_pulsegen_tmr {
	OUT_TMR
} STEST01A1_PulseGen_TMR;

HAL_StatusTypeDef STEST01A1_PULSE_PulseGen_TIM_Config(TIM_HandleTypeDef * htim, TIM_TypeDef * TIM, uint32_t Channel, uint32_t Time_Base, uint32_t Period_Ticks, uint32_t Pulse_Ticks);
void STEST01A1_PULSE_PulseGen_TIM_Start(TIM_HandleTypeDef * htim, uint32_t channel);
void STEST01A1_PULSE_PulseGen_TIM_Stop(TIM_HandleTypeDef *htim, uint32_t channel);
void STEST01A1_PULSE_PulseGen_TIM_Start_IT(TIM_HandleTypeDef * htim, uint32_t channel);
void STEST01A1_PULSE_PulseGen_TIM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t channel);
void STEST01A1_PULSE_PulseGen_TIM_High(STEST01A1_PulseGen_TMR tmr);
void STEST01A1_PULSE_PulseGen_TIM_Low(STEST01A1_PulseGen_TMR tmr);
void STEST01A1_PULSE_PulseGen_TIM_IT(TIM_HandleTypeDef * handle, TIM_TypeDef * tmr, uint32_t channel, uint32_t tick, uint32_t period_ticks, uint32_t pulse_ticks);
void STEST01A1_PULSE_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void STEST01A1_PULSE_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* BSP_STEST01A1_EVAL_INC_STEST01A1_EVAL_PULSE_DRIVER_H_ */
