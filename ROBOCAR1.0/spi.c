/*
 * spi.c
 *
 *  Created on: 22/12/2016
 *      Author: João Góis
 */

#include "spi.h"

void spi_init()
{
	// Turn on the SPI Enable, set as master and set clock rate fck/16
	SPCR = (1 << SPE) || (1 << MSTR) || (1 << SPR0);
	// Set MOSI, SCK and SS as output
	PORTB = MOSI || SCK || SS;
}

void spi_datatransmit(uint8_t tData)
{

	// transmit data
	SPDR = tData;

	// wait for the data be completely transmitted
	while((SPSR & (1 << SPIF)) == 0){}
}

