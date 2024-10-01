/**
  ******************************************************************************
  * @file    fsm01m1_eval_pulse_driver.c
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

#include "nucleo_exports.h"
#include "fsm01m1_eval_pulse_driver.h"
#include "fsm01m1_eval_driver.h"

#define MICROS 1000000

//#define OUT1_TIM_HANDLE &htim4
//#define OUT2_TIM_HANDLE &htim1

void FSM01M1_PULSE_DSC_Reset(TIM_HandleTypeDef * htim);

/**
 * @brief Configures parameters of pulse generating timer
 * @param htim: configured PWM timer handle
 * @param TIM: timer struct
 * @param Channel: timer channel
 * @param Time_Base: duration of a tick in microseconds
 * @param Period_Ticks: duration of a period in ticks
 * @param Pulse_Ticks: duration of a pulse in ticks
 * @retval HAL_StatusTypeDef
 */
HAL_StatusTypeDef FSM01M1_PULSE_PulseGen_TIM_Config(TIM_HandleTypeDef * htim, TIM_TypeDef * TIM, uint32_t Channel, uint32_t Time_Base, uint32_t Period_Ticks, uint32_t Pulse_Ticks) {
	/* Clock section */
	uint32_t PCLK1Freq = HAL_RCC_GetPCLK1Freq();
	uint32_t PCLK2Freq = HAL_RCC_GetPCLK2Freq();
	if (PCLK1Freq != PCLK2Freq) Error_Handler();
	uint32_t BusFreq = PCLK1Freq;

	uint32_t Prescaler = (BusFreq/MICROS) * Time_Base;

	htim->Init.Prescaler = Prescaler;
	htim->Init.Period = Period_Ticks;
	if (HAL_TIM_PWM_Init(htim) != HAL_OK) Error_Handler();

	__HAL_LOCK(htim);
	switch (Channel) {
		case TIM_CHANNEL_1:
			TIM->CCR1 = Pulse_Ticks;
			break;
		case TIM_CHANNEL_2:
			TIM->CCR2 = Pulse_Ticks;
			break;
		case TIM_CHANNEL_3:
			TIM->CCR3 = Pulse_Ticks;
			break;
		case TIM_CHANNEL_4:
			TIM->CCR4 = Pulse_Ticks;
			break;
		default:
			Error_Handler();
			break;
	}
	__HAL_UNLOCK(htim);

	return HAL_OK;
}

/**
 * @brief starts pulse generating timer
 * @param htim: timer handle
 * @param channel: timer channel
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_Start(TIM_HandleTypeDef * htim, uint32_t channel) {
	FSM01M1_PULSE_DSC_Reset(htim);
	HAL_TIM_PWM_Start(htim, channel);
}

/**
 * @brief stops pulse generating timer
 * @param htim: timer handle
 * @param channel: timer channel
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_Stop(TIM_HandleTypeDef * htim, uint32_t channel) {
	HAL_TIM_PWM_Stop(htim, channel);
	FSM01M1_PULSE_DSC_Reset(htim);
}

/**
 * @brief starts pulse generating timer in interrupt mode
 * @param htim: timer handle
 * @param channel: timer channel
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_Start_IT(TIM_HandleTypeDef * htim, uint32_t channel) {
	FSM01M1_PULSE_DSC_Reset(htim);
	HAL_TIM_Base_Start_IT(htim);
	HAL_TIM_PWM_Start_IT(htim, channel);
}

/**
 * @brief sets pulse generating timer high
 * @param tmr: timer name
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_High(FSM01M1_PulseGen_TMR tmr) {
	switch (tmr) {
		case OUT1_TMR:
			FSM01M1_PULSE_PulseGen_TIM_Config(OUT1_TIM_HANDLE, OUT1_TIM, OUT1_TIM_CHANNEL, 1, 1, 1);
			FSM01M1_PULSE_PulseGen_TIM_Start(OUT1_TIM_HANDLE, OUT1_TIM_CHANNEL);
			break;
		case OUT2_TMR:
			FSM01M1_PULSE_PulseGen_TIM_Config(OUT2_TIM_HANDLE, OUT2_TIM, OUT2_TIM_CHANNEL, 1, 1, 1);
			FSM01M1_PULSE_PulseGen_TIM_Start(OUT2_TIM_HANDLE, OUT2_TIM_CHANNEL);
			break;
		default:
			// informative message
			break;
	}
}

/**
 * @brief sets pulse generating timer low
 * @param tmr: timer name
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_Low(FSM01M1_PulseGen_TMR tmr) {
	switch (tmr) {
		case OUT1_TMR:
			FSM01M1_PULSE_PulseGen_TIM_Config(OUT1_TIM_HANDLE, OUT1_TIM, OUT1_TIM_CHANNEL, 1, 1, 0);
			FSM01M1_PULSE_PulseGen_TIM_Start(OUT1_TIM_HANDLE, OUT1_TIM_CHANNEL);
			break;
		case OUT2_TMR:
			FSM01M1_PULSE_PulseGen_TIM_Config(OUT2_TIM_HANDLE, OUT2_TIM, OUT2_TIM_CHANNEL, 1, 1, 0);
			FSM01M1_PULSE_PulseGen_TIM_Start(OUT2_TIM_HANDLE, OUT2_TIM_CHANNEL);
			break;
		default:
			// informative message
			break;
	}
}

/**
 * @brief sets custom pulse generating timer
 * @param handle: timer handle
 * @param tmr: timer designator
 * @param channel: timer channel
 * @param tick: tick duration in microseconds
 * @param period_ticks: number of ticks in a period
 * @param pulse ticks: number of ticks in a pulse
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_IT(TIM_HandleTypeDef * handle, TIM_TypeDef * tmr, uint32_t channel, uint32_t tick, uint32_t period_ticks, uint32_t pulse_ticks) {
	FSM01M1_PULSE_PulseGen_TIM_Config(handle, tmr, channel, tick, period_ticks,
			pulse_ticks);
	FSM01M1_PULSE_PulseGen_TIM_Start_IT(handle, channel);
}

/**
 * @brief stops pulse generating timer in interrupt mode
 * @param htim: timer handle
 * @param channel: timer channel
 * @retval None
 */
void FSM01M1_PULSE_PulseGen_TIM_Stop_IT(TIM_HandleTypeDef * htim, uint32_t channel) {
	HAL_TIM_PWM_Stop_IT(htim, channel);
	HAL_TIM_Base_Stop_IT(htim);
	FSM01M1_PULSE_DSC_Reset(htim);
}

/**
 * @brief resets discharging circuits
 * @param htim: timer handle
 * @retval None
 */
void FSM01M1_PULSE_DSC_Reset(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM4) FSM01M1_OUT1_DSC_OFF();
	else if (htim->Instance == TIM1) FSM01M1_OUT2_DSC_OFF();
}

/**
 * @brief Callback triggered by end of PWM pulse
 * @param htim: timer handle
 * @retval None
 */
void FSM01M1_PULSE_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	/* turn on discharge path as soon as pulse finishes */
	if (htim->Instance == TIM4) FSM01M1_OUT1_DSC_ON();
	else if (htim->Instance == TIM1) FSM01M1_OUT2_DSC_ON();
}

/**
 * @brief Callback triggered by elapsed period
 * @param htim: timer handle
 * @retval None
 */
void FSM01M1_PULSE_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* turn off discharge path for new period */
	if (htim->Instance == TIM4) FSM01M1_OUT1_DSC_OFF();
	else if (htim->Instance == TIM1) FSM01M1_OUT2_DSC_OFF();
}
