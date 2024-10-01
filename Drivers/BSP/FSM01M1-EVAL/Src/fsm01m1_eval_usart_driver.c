///**
//  ******************************************************************************
//  * @file    fsm01m1_eval_usart_driver.c
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
///* Includes ------------------------------------------------------------------*/
//#include "fsm01m1_eval_usart_driver.h"
//#include "stm32f4xx_hal_uart.h"
//#include "stdio.h"
//#include "string.h"
//
///* Private constants ---------------------------------------------------------*/
//#define USART_COM_TIMEOUT 100
//
///* Private variables ---------------------------------------------------------*/
//UART_HandleTypeDef vCOM;
//UART_HandleTypeDef * p_vCOM = NULL;
//deprecated_USART_MessageTypeDef * p_msg = NULL;
//char rx_buffer[USART_MAX_MSG_LEN];
//
///* Exported functions --------------------------------------------------------*/
//
///**
// * @brief Configuration of virtual COM
// * @param huart: initialized virtual COM Handle
// * @retval int
// */
//int FSM01M1_USART_vCOM_Config(UART_HandleTypeDef * huart) {
//	p_vCOM = huart;
//	p_vCOM->Init.BaudRate = 115200;
//	p_vCOM->Init.WordLength = UART_WORDLENGTH_8B;
//	p_vCOM->Init.StopBits = UART_STOPBITS_1;
//	p_vCOM->Init.Parity = UART_PARITY_NONE;
//	p_vCOM->Init.HwFlowCtl = UART_HWCONTROL_NONE;
//	if (HAL_UART_Init(p_vCOM) != HAL_OK)
//	{
//		return 1;
//	}
//	return 0;
//}
//
///**
// * @brief Initializes new USART message
// * @retval USART_MessageTypeDef
// */
//deprecated_USART_MessageTypeDef FSM01M1_USART_vCOM_CreateMessage() {
//	deprecated_USART_MessageTypeDef msg = {{0}, USART_MAX_MSG_LEN, deprecated_idle, FSM01M1_USART_vCOM_AppendInt,
//			FSM01M1_USART_vCOM_AppendFloat,
//			FSM01M1_USART_vCOM_AppendStr,
//			FSM01M1_USART_vCOM_Reset
//	};
//
//	return msg;
//}
//
///**
// * @brief Append integer to a message
// * @param i: integer
// * @param msg: message
// * @retval None
// */
//void FSM01M1_USART_vCOM_AppendInt(int i, deprecated_USART_MessageTypeDef * msg) {
//	char iStr[USART_MAX_MSG_LEN/2];
//	int len = sprintf(iStr, "%d", i);
//
//	strncat(msg->data, iStr, len);
//}
//
///**
// * @brief Append float to a message
// * @param f: float
// * @param msg: message
// * @retval None
// */
//void FSM01M1_USART_vCOM_AppendFloat(float f, deprecated_USART_MessageTypeDef * msg) {
//	char fStr[USART_MAX_MSG_LEN/2];
//	int len = sprintf(fStr, "%0.2f", (double) f);
//
//	strncat(msg->data, fStr, len);
//}
//
///*
// * @brief Append string to a message
// * @param str: string
// * @param msg: message
// * @retval None
// */
//void FSM01M1_USART_vCOM_AppendStr(char * str, deprecated_USART_MessageTypeDef * msg) {
//	int len = strlen(str);
//	strncat(msg->data, str, len);
//}
//
///*
// * @brief Clears message data
// * @param msg: message
// * @retval None
// */
//void FSM01M1_USART_vCOM_Reset(deprecated_USART_MessageTypeDef * msg) {
//	memset(msg->data, 0, USART_MAX_MSG_LEN);
//}
//
///*
// * @brief Clears console contents
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_Clear() {
//	char * clr_str = "\x1b[2J\x1b[1;1H";
//	int len = strlen(clr_str);
//	HAL_StatusTypeDef status = HAL_UART_Transmit(p_vCOM, (uint8_t *) clr_str, len, USART_COM_TIMEOUT);
//
//	return status;
//}
//
///*
// * @brief Write message to virtual COM port stream as is
// * @param msg: message
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_Write(deprecated_USART_MessageTypeDef * msg) {
//	HAL_StatusTypeDef status = HAL_UART_Transmit(p_vCOM, (uint8_t *) msg->data, USART_MAX_MSG_LEN, USART_COM_TIMEOUT);
//
//	return status;
//}
//
///*
// * @brief Write newline terminated message to virtual COM port stream
// * param msg: message
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_WriteLine(deprecated_USART_MessageTypeDef * msg) {
//	char msg_ln[USART_MAX_MSG_LEN + 2];
//	memcpy(msg_ln, msg->data, USART_MAX_MSG_LEN);
//	strncat(msg_ln, "\n", 2);
//
//	HAL_StatusTypeDef status = HAL_UART_Transmit(p_vCOM, (uint8_t *) msg_ln, USART_MAX_MSG_LEN, USART_COM_TIMEOUT);
//
//	return status;
//}
//
///**
// * @brief Flush and write newline terminated message to virtual COM port stream
// * @param msg: message
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_FlushWriteLine(deprecated_USART_MessageTypeDef * msg) {
//	if (msg->flag == deprecated_wait) {
//		msg->flag = deprecated_flush_write;
//		return HAL_BUSY;
//	}
//
//	char msg_ln[USART_MAX_MSG_LEN + 2];
//	memcpy(msg_ln, msg->data, USART_MAX_MSG_LEN);
//	strncat(msg_ln, "\n", 2);
//
//	HAL_StatusTypeDef status = HAL_UART_Transmit(p_vCOM, (uint8_t *) msg_ln, USART_MAX_MSG_LEN, USART_COM_TIMEOUT);
//	msg->Reset(msg);
//
//	return status;
//}
//
///**
// * @brief Write single character to virtual COM port stream
// * @param c: character
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_WriteChar(char c) {
//	return HAL_UART_Transmit(p_vCOM, (uint8_t *) &c, 1, USART_COM_TIMEOUT);
//}
//
///**
// * @brief Reads line of characters from virtual COM stream
// * @param msg: message
// * @retval HAL_StatusTypeDef
// */
//HAL_StatusTypeDef FSM01M1_USART_vCOM_ReadLine(deprecated_USART_MessageTypeDef * msg) {
//	if (msg->flag == deprecated_idle) msg->flag = deprecated_wait;
//	p_msg = msg;
//	return HAL_UARTEx_ReceiveToIdle_IT(p_vCOM, (uint8_t *) rx_buffer, USART_MAX_MSG_LEN);
//}
//
///**
// * @brief Overrides HAL_UARTEx_RxEventCallback
// * @param huart: uart handle
// * @param Size: size of received data
// * @retval None
// */
//void deprecated_HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
//	if (huart == p_vCOM) {
//		p_msg->AppendStr(rx_buffer, p_msg);
//		memset(rx_buffer, 0, USART_MAX_MSG_LEN);
//
//		switch (p_msg->flag) {
//			case deprecated_write:
//				FSM01M1_USART_vCOM_Write(p_msg);
//				break;
//			case deprecated_flush_write:
//				FSM01M1_USART_vCOM_FlushWriteLine(p_msg);
//				break;
//			case deprecated_wait:
//				p_msg->flag = deprecated_ready;
//				break;
//			case deprecated_ready:
//			default:
//				break;
//		}
//	}
//}
