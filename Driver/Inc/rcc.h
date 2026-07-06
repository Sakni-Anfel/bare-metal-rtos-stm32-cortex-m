/*
 * rcc.h
 *
 *  Created on: 30 juin 2026
 *      Author: asus
 */

#ifndef SOURCES_DRIVERS_INC_RCC_H_
#define SOURCES_DRIVERS_INC_RCC_H_

#include "base.h"

typedef struct {

	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	// 2 reserved here 0x18 and 0x1C
	uint32_t reserved0[2];
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	//2 reserved here 0x28 and 0x2c
	uint32_t reserved1[2];
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	//2 reserved here 0x38 0x3C
	uint32_t reserved3[2];
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
}Typdef_RCC	;

#define RCC ((Typdef_RCC *) RCC_base )
void sysclock(void);


#endif /* SOURCES_DRIVERS_INC_RCC_H_ */
