/*
 * main.c
 *
 *  Created on: 22/12/2016
 *      Author: João Góis
 */


#include"avr/io.h"
#include"avr/delay.h"
#include "spi.h"



int main()
{
	spi_init();

	init_oled_lcd();
	int i = 0;
	while(1)
	{
		_delay_ms(1000);
		oled_lcd_send_data(i);
		i++;
	}

}
