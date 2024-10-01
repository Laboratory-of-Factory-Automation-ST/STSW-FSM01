/**
  ******************************************************************************
  * @file    nucleo_usart_driver.h
  * @author  ST Power Application Laboratory
  * @version V1.0.0
  * @brief   Provides functions for serial ST-LINK communication
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
#ifndef BSP_NUCLEO_INC_NUCLEO_USART_DRIVER_H_
#define BSP_NUCLEO_INC_NUCLEO_USART_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported constants --------------------------------------------------------*/
#define USART_MAX_MSG_LEN 255

/* Exported types ------------------------------------------------------------*/
typedef enum USART_MsgFlag_t {
	idle,
	ready,
	wait,
	write,
	flush_write,
} USART_MsgFlagTypeDef;

typedef struct USART_Message_t {
	char data[USART_MAX_MSG_LEN];
	int length;
	USART_MsgFlagTypeDef flag;

	// aliases to common functions
	void (* AppendInt)(int i, struct USART_Message_t * msg);
	void (* AppendFloat)(float f, struct USART_Message_t * msg);
	void (* AppendStr)(char * str, struct USART_Message_t * msg);
	void (* Reset)(struct USART_Message_t * msg);
} USART_MessageTypeDef;

/* Exported functions --------------------------------------------------------*/
int NUCLEO_USART_vCOM_Config(UART_HandleTypeDef * huart);
USART_MessageTypeDef NUCLEO_USART_vCOM_CreateMessage();
void NUCLEO_USART_vCOM_AppendInt(int i, USART_MessageTypeDef * msg);
void NUCLEO_USART_vCOM_AppendFloat(float f, USART_MessageTypeDef * msg);
void NUCLEO_USART_vCOM_AppendDouble(double d, USART_MessageTypeDef * m);
void NUCLEO_USART_vCOM_AppendStr(char * str, USART_MessageTypeDef * msg);
void NUCLEO_USART_vCOM_Reset(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_Clear();
HAL_StatusTypeDef NUCLEO_USART_vCOM_Write(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_FlushWrite(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_FlushWriteLine(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_WriteLine(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_ReadLine(USART_MessageTypeDef * msg);
HAL_StatusTypeDef NUCLEO_USART_vCOM_WriteChar(char c);
HAL_StatusTypeDef NUCLEO_USART_vCOM_QuickWrite(char * fmt_str);
HAL_StatusTypeDef NUCLEO_USART_vCOM_QuickWriteLine(char * fmt_str);
HAL_StatusTypeDef NUCLEO_USART_vCOM_Status();

#ifdef	 __cplusplus
}
#endif

#endif /* BSP_NUCLEO_INC_NUCLEO_USART_DRIVER_H_ */
