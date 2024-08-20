/*
 * fsm_automatic.c
 *
 *  Created on: Aug 16, 2024
 *      Author: ASUS
 */
#include "fsm_automatic.h"
#include "main.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			//TODO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1);
			status = AUTO_RED;
			setTimer1(300);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1);
			if(timer1_flag == 1){
				status = AUTO_GREEN;
				setTimer1(200);
			}
			if(isButton1Pressed() == 1){
				status = MAN_RED;
				setTimer1(100);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1);
			if(timer1_flag == 1){
				status = AUTO_YELLOW;
				setTimer1(100);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 0);
			if(timer1_flag == 1){
				status = AUTO_RED;
				setTimer1(300);
			}
			break;
		default:
			break;
	}
}

