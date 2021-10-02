/*
 * driver.c
 *
 *  Created on: 28 сент. 2021 г.
 *      Author: 1
 */

#include "driver.h"

bool getButtonState(){
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_SET) return 1;
	else return 0;
}

void resetButton(){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
}

void resetAllDiodes(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
}

uint32_t getButtonTime(uint32_t time){
	return HAL_GetTick()-time;
}

void delay(uint32_t ms){
	HAL_Delay(ms);
}

void playOutputSignal(uint32_t time, uint16_t GPIO_Pin){
	resetAllDiodes();
	HAL_GPIO_WritePin(GPIOD, GPIO_Pin, GPIO_PIN_SET);
	delay(time);
	HAL_GPIO_WritePin(GPIOD, GPIO_Pin, GPIO_PIN_RESET);

}

void playShortYellow(uint32_t time){
	playOutputSignal(time, GPIO_PIN_14);
}

void playLongRed(uint32_t time){
	playOutputSignal(time, GPIO_PIN_15);
}

void playGreen(uint32_t time){
	playOutputSignal(time, GPIO_PIN_13);
}

void playMorze(bool *chain, int n, uint32_t time){
	int i;
	for (i = 0; i < n; i++){
		if (chain[i]) playGreen(time*2);
		else playGreen(time);
	}
}


