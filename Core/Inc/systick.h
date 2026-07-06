/*
 * systick.h
 *
 *  Created on: 30 juin 2026
 *      Author: asus
 */

#ifndef SOURCES_DRIVERS_INC_SYSTICK_H_
#define SOURCES_DRIVERS_INC_SYSTICK_H_

#include <stdint.h>

#include "base.h"
typedef struct {

	volatile uint32_t STK_CTR;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;
}Typdef_Systick ;

#define Systick	((Typdef_Systick *) Systick_base)
//STK_CTR register
#define ENABLE (1U<<0)
#define TICKINT	(1U<<1)
#define CLKSOURCE (1U<<2)
#define COUNTFLAG	(1U<<16)
#define SYSTICK		0

void systick_delay(uint32_t delay);
void systick_init(uint32_t tick , uint8_t priority);
void SysTick_Handler(void);
#endif /* SOURCES_DRIVERS_INC_SYSTICK_H_ */
