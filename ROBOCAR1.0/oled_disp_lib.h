/*
 * oled_disp_lib.h
 *
 *  Created on: 22/12/2016
 *      Author: João Góis
 */

#include "spi.h"

//define the pin DC as a 4 bit of PINB
#define DC PB4;

//function prototype
void init_oled_lcd();
void oled_lcd_send_command(uint8_t tData);
void oled_lcd_send_data(uint8_t tData);
