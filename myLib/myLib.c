/*
 * myLib.c
 *
 *  Created on: Nov 15, 2024
 *      Author: user
 */
#include "main.h"
#include <stdio.h>

extern UART_HandleTypeDef huart2;

int __io_getchar(void) {
	char ch;
	while(HAL_UART_Receive(&huart2, &ch, 1, 10/*ms*/) != HAL_OK);
	HAL_UART_Transmit(&huart2, &ch, 1, 10/*ms*/);	// Echo
	if(ch == '\r'/* Enter */)	HAL_UART_Transmit(&huart2, "\n", 1, 10/*ms*/);
	return ch;
}
int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart2, &ch, 1, 10/*ms*/);
	return ch;
}
void standby() {
	while (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin))
		;
}
void cls()				   // 화면 clear
{
	printf("\033[2J");
}
void cursor(int x, int y)  // 해당 위치로 커서 이동
{
	char buf[20];
	sprintf(buf, "\033[%d;%dH", y, x);
	puts(buf);
}
void ProgramStart(char *str)
{
//	printf("\033[2J\033[0;0H");
	cls();
	cursor(0,0);
	printf("program Name - %s\r\n", str);
	printf("Press Blue-button(B1) to Start...\r\n");
	standby();
	setvbuf(stdin, NULL, _IONBF, 0);
}

