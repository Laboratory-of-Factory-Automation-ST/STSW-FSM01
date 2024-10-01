/**
 ******************************************************************************
 * @file    fsm01m1_eval_tests.c
 * @author  ST Power Application Lab Prague
 * @version V1.0.0
 * @date    Jan 1, 2023
 * @brief   PCB test routines and procedures
 ******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "fsm01m1_eval_tests.h"
#include "fsm01m1_eval_driver.h"
//#include "fsm01m1_eval_usart_driver.h"
#include "nucleo_usart_driver.h"
/* Private types -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
float VCC_ADC;
float VCC1_ADC;
float VCC2_ADC;
float OUT1_ADC;
float OUT2_ADC;

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void TimeLoop_test_pulse() {
	uint16_t i;

	for(i = 0; i<0x3FFF; i++);
}

/**
 *
 */
void FSM01M1_TEST_CASE_SFTY_OFF() {

	/* Switch-OFF cut-OFF feature on both channels*/
	FSM01M1_CUTOFF1_CTRL_OFF();
	FSM01M1_CUTOFF2_CTRL_OFF();

	/* Activate VCCx */
	FSM01M1_VCC1_ON();
	FSM01M1_VCC2_ON();
	FSM01M1_TimeLoop_Short();

	/* Activate OUT1 and OUT2 */
	FSM01M1_OUT1_CTRL_ON();
	FSM01M1_OUT2_CTRL_ON();
	FSM01M1_TimeLoop_Short();

	/* periodically turn OFF and ON VCCx */
	while(1) {

		FSM01M1_VCC1_OFF();
		FSM01M1_VCC2_OFF();
		FSM01M1_TimeLoop_Short();

		FSM01M1_VCC1_ON();
		FSM01M1_VCC2_ON();
		FSM01M1_TimeLoop_Default();
	}
}

void FSM01M1_TEST_CASE_loss_off_GND() {

	/* Switch-OFF cut-OFF feature on both channels*/
	FSM01M1_CUTOFF1_CTRL_OFF();
	FSM01M1_CUTOFF2_CTRL_OFF();

	/* Activate VCCx */
	FSM01M1_VCC1_ON();
	FSM01M1_VCC2_ON();

	/* Activate OUT1 and OUT2 */
	FSM01M1_OUT1_CTRL_ON();
	FSM01M1_OUT2_CTRL_ON();

	/* infinite loop */
	while(1);
}

void FSM01M1_TEST_CASE_simultaneous_demagnetization() {

	/* Switch-OFF cut-OFF feature on both channels*/
	//STEVAL_FSM01M1_CUTOFF1_OFF();
	//STEVAL_FSM01M1_CUTOFF2_OFF();

	FSM01M1_VCC1_ON();
	FSM01M1_OUT1_CTRL_OFF();

	FSM01M1_VCC2_ON();
	FSM01M1_OUT2_CTRL_OFF();

	FSM01M1_TimeLoop_Short();

	/* periodically turn ON and OFF OUTx */
	while(1) {

		FSM01M1_OUT1_CTRL_ON();
		FSM01M1_OUT2_CTRL_ON();
		FSM01M1_TimeLoop_Short();

		FSM01M1_OUT1_CTRL_OFF();
		FSM01M1_OUT2_CTRL_OFF();
		FSM01M1_TimeLoop_Default();
	}
}

void FSM01M1_TEST_CASE_overcurrent_cutoff_test() {

	static uint8_t cutoff_gate = 0;

	/* Switch-OFF cut-OFF feature on both channels*/
	FSM01M1_CUTOFF1_CTRL_OFF();
	FSM01M1_CUTOFF2_CTRL_OFF();

	FSM01M1_VCC1_ON();
	FSM01M1_OUT1_CTRL_OFF();

	FSM01M1_VCC2_ON();
	FSM01M1_OUT2_CTRL_OFF();

	FSM01M1_TimeLoop_Short();

	/* periodically turn ON and OFF OUTx and CoD */
/*	while(1) {

		if(cutoff_gate) {
			STEVAL_FSM01M1_CUTOFF1_CTRL_ON();
			STEVAL_FSM01M1_CUTOFF2_CTRL_ON();
			cutoff_gate = 0;
		}
		else {
			STEVAL_FSM01M1_CUTOFF1_CTRL_OFF();
			STEVAL_FSM01M1_CUTOFF2_CTRL_OFF();
			cutoff_gate = 1;
		}

		STEVAL_FSM01M1_OUT1_CTRL_ON();
		STEVAL_FSM01M1_OUT2_CTRL_ON();
		TimeLoop_Short();

		STEVAL_FSM01M1_OUT1_CTRL_OFF();
		STEVAL_FSM01M1_OUT2_CTRL_OFF();
		TimeLoop_Short();
	}*/

	/* Mixed CoD */
	while(1) {

		/* Enable Cut-OFF */
		FSM01M1_CUTOFF1_CTRL_ON();
		FSM01M1_CUTOFF2_CTRL_ON();
		cutoff_gate = 0;

		FSM01M1_OUT1_CTRL_ON();
		FSM01M1_OUT2_CTRL_ON();
		FSM01M1_TimeLoop_Short_div2();

		/* Disable Cut-OFF */
		FSM01M1_CUTOFF1_CTRL_OFF();
		FSM01M1_CUTOFF2_CTRL_OFF();
		cutoff_gate = 1;

		FSM01M1_TimeLoop_Short_div2();

		FSM01M1_OUT1_CTRL_OFF();
		FSM01M1_OUT2_CTRL_OFF();
		FSM01M1_TimeLoop_Short();

	}
}

void FSM01M1_TEST_CASE_EMC_test_routine() {

	/* Onboard NUCLEO user LED test */
	FSM01M1_LD2_USER_ON();
	FSM01M1_TimeLoop_Default();
	FSM01M1_LD2_USER_OFF();
	FSM01M1_TimeLoop_Default();

	/* USER_LED_GREEN test */
	FSM01M1_user_LED_green_ON();
	FSM01M1_TimeLoop_Short();
	FSM01M1_user_LED_green_OFF();
	FSM01M1_TimeLoop_Short();

	/* USER_LED_RED test */
	FSM01M1_user_LED_red_ON();
	FSM01M1_TimeLoop_Default();
	FSM01M1_user_LED_red_OFF();
	FSM01M1_TimeLoop_Default();

	/* Turn-OFF both channels */
	FSM01M1_OUT1_CTRL_OFF();
	FSM01M1_OUT1_CTRL_OFF();

	/* VCCx control test */
	FSM01M1_VCC1_OFF();
	FSM01M1_VCC2_OFF();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	if (VCC1_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD ||
		VCC2_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	/* VCC1 function test */
	FSM01M1_VCC1_ON();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	/* Cross-check both VCCx domains */
	if (VCC1_scan < FSM01M1_NOMINAL_VOLTAGE_THRESHOLD ||
		VCC2_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	/* VCC2 function test */
	FSM01M1_VCC1_OFF();
	FSM01M1_VCC2_ON();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	/* Cross-check both VCCx domains */
	if (VCC1_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD ||
		VCC2_scan < FSM01M1_NOMINAL_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	FSM01M1_VCC1_ON();
	FSM01M1_VCC2_ON();
	FSM01M1_OUT1_CTRL_ON();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	/* Cross-check both VCCx domains */
	if (OUT2_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD ||
		OUT1_scan < FSM01M1_NOMINAL_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	/* OUT2 control test */
	FSM01M1_VCC1_ON();
	FSM01M1_VCC2_ON();
	FSM01M1_OUT2_CTRL_ON();
	FSM01M1_OUT1_CTRL_OFF();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	/* Cross-check both OUTx domains */
	if (OUT1_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD ||
		OUT2_scan < FSM01M1_NOMINAL_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	FSM01M1_OUT1_CTRL_OFF();
	FSM01M1_OUT2_CTRL_OFF();
	HAL_Delay(FSM01M1_ADC120_DEBOUNCE_TIME_MS);

	FSM01M1_scan_voltage_vector(&hspi2);

	/* Cross-check both OUTx domains */
	if (OUT1_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD ||
			OUT2_scan > FSM01M1_ZERO_VOLTAGE_THRESHOLD) {

		FSM01M1_user_LED_red_ON();
		while(1);
	}

	/* Test pulses deactivation */
	FSM01M1_TP1_OFF();
	FSM01M1_TP2_OFF();
}

void FSM01M1_TEST_CASE_VCCx_test_pulse_routine() {

	FSM01M1_VCC2_ON();
	while(1) {
		FSM01M1_OUT2_CTRL_ON();
		FSM01M1_VCC1_ON();
		FSM01M1_TimeLoop_Short();

		FSM01M1_OUT2_CTRL_OFF();
		FSM01M1_VCC1_OFF();
		TimeLoop_test_pulse();
	}
}

/**
 * @brief Compares expected voltage levels with real ones
 * @params expected switch states of devices
 * @retval None
 */
void FSM01M1_TEST_PROC_check_expected_voltages(bool * vcc, bool * vcc1, bool * out1, bool * vcc2, bool * out2) {
	FSM01M1_OUT1_CTRL_OFF();
	FSM01M1_VCC1_OFF();
	FSM01M1_OUT2_CTRL_OFF();
	FSM01M1_VCC2_OFF();
	HAL_Delay(100);

	/* Switch */
	if (vcc1) FSM01M1_VCC1_ON();
	if (vcc2) FSM01M1_VCC2_ON();
	if (out1) FSM01M1_OUT1_CTRL_ON();
	if (out2) FSM01M1_OUT2_CTRL_ON();
	HAL_Delay(100);

	FSM01M1_OUT1_CTRL_ON();
	HAL_Delay(100);
	/* ADC measurements */
	VCC1_ADC = FSM01M1_ADC120_read_single_node(&hspi2, VCC_ADC_CHANNEL_ID);
//	VCC1_ADC = STEVAL_FSM01M1_scan_voltage_point(&hspi2, VCC_ADC_CHANNEL_ID);
//	VCC_ADC = STEVAL_FSM01M1_scan_voltage_point(&hspi2, OUT1_ADC_CHANNEL_ID);
	VCC_ADC = FSM01M1_ADC120_read_single_node(&hspi2, OUT1_ADC_CHANNEL_ID);
	OUT1_ADC = FSM01M1_ADC120_read_single_node(&hspi2, VCC2_ADC_CHANNEL_ID);
	VCC2_ADC = FSM01M1_ADC120_read_single_node(&hspi2, OUT2_ADC_CHANNEL_ID);
	OUT2_ADC = FSM01M1_ADC120_read_single_node(&hspi2, VCC1_ADC_CHANNEL_ID);

	/* Criteria */

	// Initialize result by checking Vcc
	bool result = VCC_ADC >= FSM01M1_NOMINAL_VOLTAGE_THRESHOLD;
	(* vcc) = result;


	if (vcc1) {
		bool check = VCC1_ADC >= FSM01M1_NOMINAL_VOLTAGE_THRESHOLD;
		result = result && check;
		(* vcc1) = check;
	}
	else {
		bool check = VCC1_ADC <= FSM01M1_ZERO_VOLTAGE_THRESHOLD;
		result = result && check;
		(* vcc1) = check;
	}
	if (out1) {
		bool check = OUT1_ADC >= FSM01M1_NOMINAL_VOLTAGE_THRESHOLD;
		result = result && check;
		(* out1) = check;
	}
	else {
		bool check = OUT1_ADC <= FSM01M1_ZERO_VOLTAGE_THRESHOLD;
		result = result && check;
		(* out1) = check;
	}
	if (vcc2) {
		bool check = VCC2_ADC >= FSM01M1_NOMINAL_VOLTAGE_THRESHOLD;
		result = result && check;
		(* vcc2) = check;
	}
	else {
		bool check = VCC2_ADC <= FSM01M1_ZERO_VOLTAGE_THRESHOLD;
		result = result && check;
		(* vcc2) = check;
	}
	if (out2) {
		bool check = OUT2_ADC >= FSM01M1_NOMINAL_VOLTAGE_THRESHOLD;
		result = result && check;
		(* out2) = check;
	}
	else {
		bool check = OUT2_ADC <= FSM01M1_ZERO_VOLTAGE_THRESHOLD;
		result = result && check;
		(* out2) = check;
	}
}

/**
 * @brief Provides testing service for expected voltage levels
 * @params expected switch states of devices
 * @retval None
 */
void FSM01M1_TEST_CASE_expected_voltages_test(bool vcc, bool vcc1, bool out1, bool vcc2, bool out2) {
	FSM01M1_TEST_PROC_check_expected_voltages(&vcc, &vcc1, &out1, &vcc2, &out2);

	USART_MessageTypeDef msg = NUCLEO_USART_vCOM_CreateMessage();

	bool result = vcc && vcc1 && out1 && vcc2 && out2;

	// Test VCC
	if (vcc) {
		msg.AppendStr("VCC PASSED ", &msg);
		msg.AppendFloat(VCC_ADC, &msg);
	}
	else {
		msg.AppendStr("VCC FAILED ", &msg);
		msg.AppendFloat(VCC_ADC, &msg);
	}
	FSM01M1_USART_vCOM_FlushWriteLine(&msg);

	// Test VCC1
	if (vcc1) {
		msg.AppendStr("VCC1 PASSED ", &msg);
		msg.AppendFloat(VCC1_ADC, &msg);
	}
	else {
		msg.AppendStr("VCC1 FAILED ", &msg);
		msg.AppendFloat(VCC1_ADC, &msg);
	}
	FSM01M1_USART_vCOM_FlushWriteLine(&msg);

	// Test OUT1
	if (out1) {
		msg.AppendStr("OUT1 PASSED ", &msg);
		msg.AppendFloat(OUT1_ADC, &msg);
	}
	else {
		msg.AppendStr("OUT1 FAILED ", &msg);
		msg.AppendFloat(OUT1_ADC, &msg);
	}
	FSM01M1_USART_vCOM_FlushWriteLine(&msg);

	// Test VCC2
	if (vcc2) {
		msg.AppendStr("VCC2 PASSED ", &msg);
		msg.AppendFloat(VCC2_ADC, &msg);
	}
	else {
		msg.AppendStr("VCC2 FAILED ", &msg);
		msg.AppendFloat(VCC2_ADC, &msg);
	}
	FSM01M1_USART_vCOM_FlushWriteLine(&msg);

	// Test OUT2
	if (out2) {
		msg.AppendStr("OUT2 PASSED ", &msg);
		msg.AppendFloat(OUT2_ADC, &msg);
	}
	else {
		msg.AppendStr("OUT2 FAILED ", &msg);
		msg.AppendFloat(OUT2_ADC, &msg);
	}
	FSM01M1_USART_vCOM_FlushWriteLine(&msg);

	if (!result) {
		FSM01M1_user_LED_red_ON();
		while(1);
	}
}
