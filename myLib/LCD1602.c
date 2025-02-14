/*
 * LCD1602.c
 *
 *  Created on: Nov 21, 2024
 *      Author: user
 *      function : 1602 LCD device control
 */
#include "main.h"
#include <stdio.h>

#define I2C_ADDR 0x4E	// LCD 주소 값 : 0x27 << 1

I2C_HandleTypeDef *hi2c = NULL;  // i2c가 선언되지 않으면 동작 X

void lcd_command(char cmd)
{
	unsigned char n1, n2, n3, n4, dd[4];
	n1 = cmd & 0xf0;	// upper nibble : top group 4 bit store
	n2 = (cmd & 0x0f) << 4;	// lower nibble : bottom group 4 bit store
	n3 = (1<<3)|(1<<2)|0|0; //Back light|EN_1|R/W|RS;	0x0c
	n4 = (1<<3)|  0	  |0|0; //Back light|EN_1|R/W|RS;	0x08
	dd[0] = n1 | n3;
	dd[1] = n1 | n4;
	dd[2] = n2 | n3;
	dd[3] = n2 | n4;
	HAL_I2C_Master_Transmit(hi2c, I2C_ADDR, dd, 4, 10);
}
void lcd_data(char ch)
{
	unsigned char n1, n2, n3, n4, dd[4];
	n1 = ch & 0xf0;			// upper nibble : top group 4 bit store
	n2 = (ch & 0x0f) << 4;	// lower nibble : bottom group 4 bit store
	n3 = (1<<3)|(1<<2)|0|(1<<0); //Back light|EN_1|R/W|RS;	0x0E
	n4 = (1<<3)|  0	  |0|(1<<0); //Back light|EN_1|R/W|RS;	0x09
	dd[0] = n1 | n3;
	dd[1] = n1 | n4;
	dd[2] = n2 | n3;
	dd[3] = n2 | n4;
	HAL_I2C_Master_Transmit(hi2c, I2C_ADDR, dd, 4, 10);
}
void lcd_init()
{
	HAL_Delay(50);  // 초기화 전 충분한 대기 시간
	lcd_command(0x33);  // 4비트 모드 초기화 시퀀스
	lcd_command(0x32);
	lcd_command(0x28);  // 4비트, 2라인, 5x8 폰트
	lcd_command(0x0C);  // 디스플레이 온, 커서 오프
	lcd_command(0x06);  // 커서 방향 right
	lcd_command(0x01);  // 화면 클리어
	HAL_Delay(2);
}
/*void lcd_shift_r()
{
	lcd_command(0x07);  // right shift
	HAL_Delay(100);
}
void lcd_shift_l()
{
	lcd_command(0x05);	// left shift
}*/
int ln2 = 0;		// cursor line
char sbuf[20];		// 2nd line string
void lcd_printEx2(char *str)
{
	if(ln2 == 0)
	{
		lcd_command (0x80);		// 0 line
		ln2++;
	}
	else if(ln2 == 1)
	{
		lcd_command (0x80);	lcd_print(sbuf);

		lcd_command (0xc0);		// 1 line
		strcpy(sbuf, str);
	}
	lcd_print(str);
}

void lcd_print(char *str)
{
	while(*str)	lcd_data(*str++);
}
void lcd_printEx(char *str, int ln)
{
	if(ln == 0) lcd_command (0x80);
	if(ln == 1) lcd_command (0xc0);
	lcd_print(str);
}

void i2c_init(I2C_HandleTypeDef *p)
{
	hi2c = p;
}

void i2c_scan()
{
	if(hi2c == NULL)	return;
	for(int addr=0; addr<256; addr++)
	{
		if(HAL_I2C_IsDeviceReady(hi2c, addr, 1, 10 /* ms*/) == HAL_OK)
		{
			printf("  %02x ", addr);
		}
		else
		{
			printf("  .  ");
		}
		if((addr % 16) == 15)	printf("\r\n");
	}
}
