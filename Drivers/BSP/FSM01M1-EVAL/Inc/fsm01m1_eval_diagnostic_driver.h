/**
  ******************************************************************************
  * @file    fsm01m1_eval_diagnostic_driver.h
  * @author  ST Power Application Laboratory
  * @version V1.0.0
  * @brief   Provides functions for interactive board control and measurement
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
#ifndef BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DIAGNOSTIC_DRIVER_H_
#define BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DIAGNOSTIC_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "nucleo_usart_driver.h"
#include "stdbool.h"


/* Exported types ------------------------------------------------------------*/


/* Exported functions --------------------------------------------------------*/
void FSM01M1_DIAG_IO_Loop(UART_HandleTypeDef * huart);

#ifdef	 __cplusplus
}
#endif

#endif /* BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DIAGNOSTIC_DRIVER_H_ */
