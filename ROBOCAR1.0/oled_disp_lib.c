/*
 * oled_disp_lib.c
 *
 *  Created on: 22/12/2016
 *      Author: João Góis
 */

#include "oled_disp_lib.h"

#define CMD_OLED_ON                   (uint8_t)0xAF
#define CMD_OLED_OFF                  (uint8_t)0xAE
#define CMD_OLED_ENTIRE_DISP_ON       (uint8_t)0xA5
#define CMD_OLED_ENTIRE_DISP_OFF      (uint8_t)0xA4
#define CMD_OLED_SET_CONTRAST_CONTROL (uint8_t)0x81
#define CMD_OLED_SET_NORMAL_DISPLAY   (uint8_t)0xA6
#define CMD_OLED_SET_INVERSE DISPLAY  (uint8_t)0xA7


void init_oled_lcd()
{
	oled_lcd_send_command(CMD_OLED_OFF);
	oled_lcd_send_command(0xD5);
	oled_lcd_send_command(0x80);
	oled_lcd_send_command(0xA8);
	oled_lcd_send_command(127);
	oled_lcd_send_command(0xD3);
	oled_lcd_send_command(0x0);
	oled_lcd_send_command(0x40);
	oled_lcd_send_command(0x8D);
	oled_lcd_send_command(0xDA);
	oled_lcd_send_command(0x12);
	oled_lcd_send_command(CMD_OLED_SET_CONTRAST_CONTROL);
	oled_lcd_send_command(0xDB);
	oled_lcd_send_command(0x40);
	oled_lcd_send_command(0xA4);
	oled_lcd_send_command(0xA6);
	oled_lcd_send_command(0x2E);
	oled_lcd_send_command(CMD_OLED_ON);
}


void oled_lcd_send_command(uint8_t tData)
{
	spi_init();

	//configure the DC pin as output
	DDRB |= DC;

	// init all PORTB bits to 0 and then SS and DC to HIGH
	PORTB = 0x00;
	PORTB |= SS;
	PORTB |= DC;

	//SS and DC do LOW (Select the slave and put the DC to LOW to send a command)
	PORTB |= ~SS;
	PORTB |= ~DC;

	//send command
	spi_datatransmit(tData);

	//SS to HIGH and DC to HIGH
	PORTB |= SS;
	PORTB |= DC;

}


void oled_lcd_send_data(uint8_t tData)
{
	spi_init();

	//configure the DC pin as output
	DDRB |= DC;

	//initialization of all PORTB bits to 0 and then SS and DC to HIGH
	PORTB = 0x00;
	PORTB |= SS;
	PORTB |= ~DC;

	//SS to LOW and DC do HIGH (Select the slave and put the DC to HIGH to send data)
	PORTB |= ~SS;
	PORTB |= DC;

	//send command
	spi_datatransmit(tData);

	//SS to HIGH and DC to HIGH
	PORTB |= SS;
	PORTB |= ~DC;

}
