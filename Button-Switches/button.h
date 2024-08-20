/*
 * button.h
 *
 *  Created on: Jul 26, 2024
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET    //1
#define PRESSED_STATE GPIO_PIN_RESET //0

int isButton1Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
