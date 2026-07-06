/*
 * rcc.c
 *
 *  Created on: 1 juil. 2026
 *      Author: asus
 */

//#include "base.h"
#include "rcc.h"

#include <stdint.h>
//here we are going to enable the system clock rcc for the peripheral that we are going to use

#define GPIOAEN		(1U<<0)
#define GPIOBEN		(1U<<1)
#define GPIOCEN		(1U<<2)
#define GPIODEN		(1U<<3)
void sysclock(){

	RCC->RCC_AHB1ENR |= GPIOAEN  ;
}
