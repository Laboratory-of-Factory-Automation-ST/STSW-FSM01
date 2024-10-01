/**
  ******************************************************************************
  * @file    fsm01m1_eval_driver.h
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
#ifndef BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DRIVER_H_
#define BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "adc120.h"

/** @addtogroup X_NUCLEO_OUT02A1_Private_Constants STEVAL-FSM01M1 Private Constants
  * @{
  */


/**
  * @}
  */

 /* Exported types -----------------------------------------------------------*/

/** @defgroup Relay_Exported_Types Relay Exported Types
  * @{
  */

typedef enum {
	FSM_MODE_DEFAULT = 0x00U,
	FSM_MODE_RESET = 0x01U,
	FSM_MODE_OUT1_OUT2_OFF = 0x02U,
	FSM_MODE_OUT1_OUT2_ON = 0x03U,
} FSM_OperationMode_TypeDef;

/**
 * @brief  Relay driver structure definition
 */
typedef struct
{
  /** Function pointer to GetADCvalue */
  uint8_t (*GetADCvalue)(void);

} fsm01M1Drv_t;

/**
 * @}
 */

/* Exported variables --------------------------------------------------------*/
extern SPI_HandleTypeDef hspi2;

extern float VCC_scan;
extern float VCC1_scan;
extern float VCC2_scan;

extern float OUT1_scan;
extern float OUT2_scan;

/* Exported constants --------------------------------------------------------*/
#define VCC1_ADC_CHANNEL_ID		(0)
#define OUT1_ADC_CHANNEL_ID		(1)
#define VCC2_ADC_CHANNEL_ID		(2)
#define OUT2_ADC_CHANNEL_ID		(3)
#define VCC_ADC_CHANNEL_ID		(4)
#define CH5_ADC_CHANNEL_ID		(5)
#define CH6_ADC_CHANNEL_ID		(6)
#define CH7_ADC_CHANNEL_ID		(7)


#define ADC120_CHANNELS_COUNT						(8)
#define ADC120_INVALID_CHANNEL_ID 					(0xFF)
#define ADC120_DEFAULT_CHANNEL_ID					(0x00)

#define FSM01M1_NOMINAL_VDD					(3.3f)

#define FSM01M1_MINIMUM_VCC					(21.6f)
#define FSM01M1_NOMINAL_VCC					(24.0f)
#define FSM01M1_MAXIMUM_VCC					(28.8f)

#define FSM01M1_UNDERVOLTAGE_ALERT_VCC		(17.0f)
#define FSM01M1_OVERVOLTAGE_ALERT_VCC		(40.0f)

#define FSM01M1_STPS_FORWARD_VOLTAGE			(0.3f)
#define	FSM01M1_VSENSE_RESCALE_FACTOR		((float) 65.6f/3.6f)

#define FSM01M1_ZERO_VOLTAGE_THRESHOLD		(5.0f)
#define FSM01M1_NOMINAL_VOLTAGE_THRESHOLD	(21.6f)

#define FSM01M1_ADC120_DEBOUNCE_TIME_MS		(1)



/* Exported functions --------------------------------------------------------*/

void FSM01M1_system_deactivation(void);
void FSM01M1_initialization(void);

/* LEDs */
void FSM01M1_LD2_USER_ON(void);
void FSM01M1_LD2_USER_OFF(void);

void FSM01M1_user_LED_green_ON(void);
void FSM01M1_user_LED_green_OFF(void);
void FSM01M1_user_LED_red_ON(void);
void FSM01M1_user_LED_red_OFF(void);

/* DIGITAL INPUT */
void FSM01M1_TP1_ON(void);
void FSM01M1_TP1_OFF(void);

void FSM01M1_TP2_ON(void);
void FSM01M1_TP2_OFF(void);

/* DIGITAL OUTPUT - channel 1 */
void FSM01M1_VCC1_ON(void);
void FSM01M1_VCC1_OFF(void);

void FSM01M1_VCC1_DSC_ON(void);
void FSM01M1_VCC1_DSC_OFF(void);

void FSM01M1_OUT1_CTRL_ON(void);
void FSM01M1_OUT1_CTRL_OFF(void);

void FSM01M1_OUT1_DSC_ON(void);
void FSM01M1_OUT1_DSC_OFF(void);

void FSM01M1_CUTOFF1_CTRL_ON(void);
void FSM01M1_CUTOFF1_CTRL_OFF(void);

/* DIGITAL OUTPUT - channel 2 */
void FSM01M1_VCC2_ON(void);
void FSM01M1_VCC2_OFF(void);

void FSM01M1_VCC2_DSC_ON(void);
void FSM01M1_VCC2_DSC_OFF(void);

void FSM01M1_OUT2_CTRL_ON(void);
void FSM01M1_OUT2_CTRL_OFF(void);

void FSM01M1_OUT2_DSC_ON(void);
void FSM01M1_OUT2_DSC_OFF(void);

void FSM01M1_CUTOFF2_CTRL_ON(void);
void FSM01M1_CUTOFF2_CTRL_OFF(void);

void FSM01M1_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void FSM01M1_B1_USER_activation_callback(void);
void FSM01M1_IN2_activation_callback(void);
void FSM01M1_OUT1_DIAG_alert_callback(void);
void FSM01M1_OUT2_DIAG_alert_callback(void);

/* ADC120 handling */
uint8_t FSM01M1_ADC120_control_register_assembler(uint8_t adc_channel_id);
uint16_t FSM01M1_SPI_ADC120_channel_read(SPI_HandleTypeDef *SpiHandle, uint8_t adc_channel_id);

float FSM01M1_ADC120_translate_to_analog(uint16_t adc_value);
float FSM01M1_ADC120_rescale_analog(float analog_val);

float FSM01M1_ADC120_read_blind(SPI_HandleTypeDef *SpiHandle);
float FSM01M1_ADC120_read_single_node(SPI_HandleTypeDef *SpiHandle, uint8_t voltage_channel);
uint8_t FSM01M1_scan_voltage_vector(SPI_HandleTypeDef *SpiHandle);

#ifdef	 __cplusplus
}
#endif

#endif /* BSP_FSM01M1_EVAL_INC_FSM01M1_EVAL_DRIVER_H_ */
