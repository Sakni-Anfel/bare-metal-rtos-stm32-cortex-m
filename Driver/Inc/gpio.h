/*
 * gpio.h
 *
 *  Created on: 1 juil. 2026
 *      Author: asus
 */

#ifndef SOURCES_DRIVERS_INC_GPIO_H_
#define SOURCES_DRIVERS_INC_GPIO_H_

#include <stdint.h>
#include "base.h"

typedef struct {

	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;

}Typdef_GPIOx;

typedef enum {

	PIN_0 = 0,
	PIN_1 = 1,
	PIN_2 = 2,
	PIN_3 = 3,
	PIN_4 = 4,
	PIN_5 = 5,
	PIN_6 =6,
	PIN_7 = 7,
	PIN_8 = 8,
	PIN_9 = 9,
	PIN_10 = 10,
	PIN_11 = 11,
	PIN_12 = 12,
	PIN_13 = 13,
	PIN_14 = 14,
	PIN_15 = 15,
} PIN_t;

typedef enum{
	MODER_INPUT =0,
	MODER_OUTPUT=1,
	MODER_ALTERNATE=2,
	MODER_ADC=3
}MODER_type;

typedef enum {
	OTYPER_PUSHPULL=0,
	OTYPER_OPENDRAIN=1,
}OTYPER_type;

typedef enum {

	OSPEEDR_LOW=0,
	OSPEEDR_MEDIUM=1,
	OSPEEDR_HIGH=2,
	OSPEEDR_VERY_HIGH=3

}OSPEEDR_type;

typedef enum{
	PUPDR_NO=0,
	PUPDR_PULLUP=1,
	PUPDR_PULLDOWN=2,
	PUPDR_RESERVED=3
}PUPDR_type;

typedef enum {
	PIN_STATE_RESET=0,
	PIN_STATE_SET=1,
}PIN_STATE_type;
#define GPIOA	((Typdef_GPIOx *) GPIOA_base)
#define GPIOB	((Typdef_GPIOx *) GPIOB_base)
#define GPIOC	((Typdef_GPIOx *) GPIOC_base)
#define GPIOD	((Typdef_GPIOx *) GPIOD_base)

void GPIO_int(Typdef_GPIOx * port ,
		PIN_t pin, MODER_type mode ,
		OTYPER_type outputType,
		OSPEEDR_type outputSpeed,
		PUPDR_type pullUpDown );
void GPIO_Write(Typdef_GPIOx * port ,
		PIN_t pin,PIN_STATE_type state);
void GPIO_Toggle(Typdef_GPIOx * port ,
		PIN_t pin);
#endif /* SOURCES_DRIVERS_INC_GPIO_H_ */
