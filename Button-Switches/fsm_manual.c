/*
 * fsm_manual.c
 *
 *  Created on: Aug 16, 2024
 *      Author: ASUS
 */
#include "fsm_manual.h"
#include "main.h"

void fsm_manual_run(){
	switch (status){
		case MAN_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1);
			if(timer1_flag == 1){
				status = AUTO_RED;
				setTimer1(500);
			}
			if(isButton1Pressed() == 1){
				status = MAN_GREEN;
				setTimer1(1000);
			}
			break;
		case MAN_GREEN:
			break;
		case MAN_YELLOW:
			break;
		default:
			break;
	}
}

