/*
 * driver.h
 *
 *  Created on: 2 окт. 2021 г.
 *      Author: 1
 */

#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_

/*
 * driver.c
 *
 *  Created on: 28 сент. 2021 г.
 *      Author: 1
 */

#include "driver.h"

bool getButtonState();

void resetButton();

void setGreenDiode();

void setYellowDiode();

void setRedDiode();

void resetAllDiodes();

uint32_t getButtonTime(uint32_t time);

void delay(uint32_t ms);

void playOutput(uint32_t time, uint16_t GPIO_Pin);


void playShortYellow(uint32_t time);

void playLongRed(uint32_t time);

void playGreen(uint32_t time);

#endif /* INC_DRIVER_H_ */
