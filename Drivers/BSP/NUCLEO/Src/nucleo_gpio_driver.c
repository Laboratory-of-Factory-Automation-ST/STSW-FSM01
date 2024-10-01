/*
 * nucleo_gpio_driver.c
 *
 *  Created on: 18. 6. 2024
 *      Author: marek novotny
 */
#include "fsm01m1_eval_driver.h"
#include "stest01a1_eval_driver.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	FSM01M1_GPIO_EXTI_Callback(GPIO_Pin);
	STEST01A1_GPIO_EXTI_Callback(GPIO_Pin);
}
