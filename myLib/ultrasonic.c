/*
 * Ultrasonic.c
 *
 *  Created on: jan 16, 2025
 *      Author: user
 */
#include "main.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart2;

void MicroDelay(int us)		// us : micro Second
{
	htim2.Instance->CNT = 0;
	while(htim2.Instance->CNT < us);
}
void Trigger()
{
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 0);
	MicroDelay(10);
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 1);
	MicroDelay(10);
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, 0);
}
double Distance()
{
	Trigger();

	int t2, t3;
	while(HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == 0) // wait until Echo High
	{
		if((htim2.Instance->CNT) > 30000)	return -1;	// timeout
	}
	t2 = htim2.Instance->CNT;

	while(HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == 1)
	{
	  if((htim2.Instance->CNT) > (t2 + 30000)) return -1;	// 측정 불가 값이 나오면 -1을 출력
	} // wait until Echo Low
	t3 = htim2.Instance->CNT;

	double distance = (t3 - t2) * 0.17;	// 초음파 속도 343 m/s

	return distance;
}
