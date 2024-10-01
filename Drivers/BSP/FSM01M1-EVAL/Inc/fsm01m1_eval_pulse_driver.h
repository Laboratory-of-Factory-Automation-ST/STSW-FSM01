/**
  ******************************************************************************
  * @file    fsm01m1_eval_pulse_driver.h
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

#ifndef BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_PULSE_DRIVER_H_
#define BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_PULSE_DRIVER_H_

#include "nucleo_exports.h"
#include "stm32f4xx_hal.h"

#define OUT1_TIM_HANDLE &htim4
#define OUT2_TIM_HANDLE &htim1

/* FSM01M1 specific timers */
#define OUT1_TIM TIM4
#define OUT2_TIM TIM1

/* FSM01M1 specific channels */
#define OUT1_TIM_CHANNEL TIM_CHANNEL_3
#define OUT2_TIM_CHANNEL TIM_CHANNEL_4

typedef enum fsm01m1_pulsegen_tmr {
	OUT1_TMR,
	OUT2_TMR
} FSM01M1_PulseGen_TMR;

HAL_StatusTypeDef FSM01M1_PULSE_PulseGen_TIM_Config(TIM_HandleTypeDef * htim, TIM_TypeDef * TIM, uint32_t Channel, uint32_t Time_Base, uint32_t Period_Ticks, uint32_t Pulse_Ticks);
void FSM01M1_PULSE_PulseGen_TIM_Start(TIM_HandleTypeDef * htim, uint32_t channel);
void FSM01M1_PULSE_PulseGen_TIM_Stop(TIM_HandleTypeDef *htim, uint32_t channel);
void FSM01M1_PULSE_PulseGen_TIM_Start_IT(TIM_HandleTypeDef * htim, uint32_t channel);
void FSM01M1_PULSE_PulseGen_TIM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t channel);
void FSM01M1_PULSE_PulseGen_TIM_High(FSM01M1_PulseGen_TMR tmr);
void FSM01M1_PULSE_PulseGen_TIM_Low(FSM01M1_PulseGen_TMR tmr);
void FSM01M1_PULSE_PulseGen_TIM_IT(TIM_HandleTypeDef * handle, TIM_TypeDef * tmr, uint32_t channel, uint32_t tick, uint32_t period_ticks, uint32_t pulse_ticks);
void FSM01M1_PULSE_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void FSM01M1_PULSE_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_PULSE_DRIVER_H_ */
