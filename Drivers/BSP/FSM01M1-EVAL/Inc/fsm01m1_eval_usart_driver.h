///**
//  ******************************************************************************
//  * @file    fsm01m1_eval_usart_driver.h
//  * @author  ST Power Application Laboratory
//  * @version V1.0.0
//  * @brief   Provides functions for serial ST-LINK communication
//  ******************************************************************************
//  * @attention
//  *
//  * Copyright (c) 2023 STMicroelectronics.
//  * All rights reserved.
//  *
//  * This software is licensed under terms that can be found in the LICENSE file
//  * in the root directory of this software component.
//  * If no LICENSE file comes with this software, it is provided AS-IS.
//  *
//  ******************************************************************************
//  */
//
///* Define to prevent recursive inclusion -------------------------------------*/
//#ifndef BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_USART_DRIVER_H_
//#define BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_USART_DRIVER_H_
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
///* Includes ------------------------------------------------------------------*/
//#include "stm32f4xx_hal.h"
//
///* Exported constants --------------------------------------------------------*/
//#define USART_MAX_MSG_LEN 255
//
///* Exported types ------------------------------------------------------------*/
//typedef enum deprecated_USART_MsgFlag_t {
//	deprecated_idle,
//	deprecated_ready,
//	deprecated_wait,
//	deprecated_write,
//	deprecated_flush_write,
//} deprecated_USART_MsgFlagTypeDef;
//
//typedef struct deprecated_USART_Message_t {
//	char data[USART_MAX_MSG_LEN];
//	int length;
//	deprecated_USART_MsgFlagTypeDef flag;
//
//	// aliases to common functions
//	void (* AppendInt)(int i, struct deprecated_USART_Message_t * msg);
//	void (* AppendFloat)(float f, struct deprecated_USART_Message_t * msg);
//	void (* AppendStr)(char * str, struct deprecated_USART_Message_t * msg);
//	void (* Reset)(struct deprecated_USART_Message_t * msg);
//} deprecated_USART_MessageTypeDef;
//
///* Exported functions --------------------------------------------------------*/
//int FSM01M1_USART_vCOM_Config(UART_HandleTypeDef * huart);
//deprecated_USART_MessageTypeDef FSM01M1_USART_vCOM_CreateMessage();
//void FSM01M1_USART_vCOM_AppendInt(int i, deprecated_USART_MessageTypeDef * msg);
//void FSM01M1_USART_vCOM_AppendFloat(float f, deprecated_USART_MessageTypeDef * msg);
//void FSM01M1_USART_vCOM_AppendDouble(double d, deprecated_USART_MessageTypeDef * m);
//void FSM01M1_USART_vCOM_AppendStr(char * str, deprecated_USART_MessageTypeDef * msg);
//void FSM01M1_USART_vCOM_Reset(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_Clear();
//HAL_StatusTypeDef FSM01M1_USART_vCOM_Write(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_FlushWrite(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_FlushWriteLine(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_WriteLine(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_ReadLine(deprecated_USART_MessageTypeDef * msg);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_WriteChar(char c);
//HAL_StatusTypeDef FSM01M1_USART_vCOM_Status();
//
//#ifdef	 __cplusplus
//}
//#endif
//
//#endif /* BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_USART_DRIVER_H_ */
