/*
 * spi.h
 *
 *  Created on: 22/12/2016
 *      Author: João Góis
 */

#include"avr/io.h"


#ifndef SPI_H_
#define SPI_H_

//define the
#define MOSI (1 << PB2)
#define MISO (1 << PB3)
#define SS   (1 << PB0)
#define SCK  (1 << PB1)


void spi_init();
void spi_datatransmit();

#endif /* SPI_H_ */
