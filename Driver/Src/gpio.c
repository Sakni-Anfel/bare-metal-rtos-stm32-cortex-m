/*
 * gpio.c
 *
 *  Created on: 1 juil. 2026
 *      Author: asus
 */

#include "gpio.h"

#include <stdint.h>

void GPIO_int(Typdef_GPIOx * port ,
		PIN_t pin,
		MODER_type mode ,
		OTYPER_type outputType,
		OSPEEDR_type outputSpeed,
			PUPDR_type pullUpDown ){

	port->GPIOx_MODER &=  ~(0x3UL<<(pin*2));
	port->GPIOx_MODER |=(uint32_t) (mode <<(pin*2U));

	port->GPIOx_OTYPER &=~(0x1UL<< pin);
	port->GPIOx_OTYPER |=((uint32_t) (outputType << pin));

	port->GPIOx_OSPEEDR &=  ~(0x3UL<<(pin*2));
	port->GPIOx_OSPEEDR |=(uint32_t) (outputSpeed <<(pin*2U));

	port->GPIOx_PUPDR &=  ~(0x3UL<<(pin*2));
	port->GPIOx_PUPDR |=(uint32_t) (pullUpDown <<(pin*2U));

}
void GPIO_Write(Typdef_GPIOx * port ,
		PIN_t pin,PIN_STATE_type state){

if (state == PIN_STATE_SET){
	port->GPIOx_BSRR |= (1UL<<pin);
}else {
	port->GPIOx_BSRR |= (1UL<<(pin+16)) ;

}
}
void GPIO_Toggle(Typdef_GPIOx * port ,
		PIN_t pin){

	port->GPIOx_ODR ^= (1UL<<pin);

}
