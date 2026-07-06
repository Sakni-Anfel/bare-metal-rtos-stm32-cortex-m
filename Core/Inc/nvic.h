/*
 * nvic.h
 *
 *  Created on: 2 juil. 2026
 *      Author: asus
 */

#ifndef CORE_BSP_DRIVERS_INC_NVIC_H_
#define CORE_BSP_DRIVERS_INC_NVIC_H_
#include "stdint.h"

#include "base.h"
typedef struct {

	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ISER3;
	volatile uint32_t NVIC_ISER4;
	volatile uint32_t NVIC_ISER5;
	volatile uint32_t NVIC_ISER6;
	volatile uint32_t NVIC_ISER7;
uint32_t reserved0 [24]; //the reason we put a reserved here cause we don't move from ISER to ISPR directly there is a gap
						// by 96 byte so we devided by 4 cause we are using uint32_t which take 4 bytes and we get 24
	volatile uint32_t NVIC_ICER0;
	volatile uint32_t NVIC_ICER1;
	volatile uint32_t NVIC_ICER2;
	volatile uint32_t NVIC_ICER3;
	volatile uint32_t NVIC_ICER4;
	volatile uint32_t NVIC_ICER5;
	volatile uint32_t NVIC_ICER6;
	volatile uint32_t NVIC_ICER7;
	uint32_t reserved5 [24];

volatile uint32_t NVIC_ISPR0;
	volatile uint32_t NVIC_ISPR1;
	volatile uint32_t NVIC_ISPR2;
	volatile uint32_t NVIC_ISPR3;
	volatile uint32_t NVIC_ISPR4;
	volatile uint32_t NVIC_ISPR5;
	volatile uint32_t NVIC_ISPR6;
	volatile uint32_t NVIC_ISPR7;
	uint32_t reserved2 [24];
	volatile uint32_t NVIC_ICPR0;
	volatile uint32_t NVIC_ICPR1;
	volatile uint32_t NVIC_ICPR2;
	volatile uint32_t NVIC_ICPR3;
	volatile uint32_t NVIC_ICPR4;
	volatile uint32_t NVIC_ICPR5;
	volatile uint32_t NVIC_ICPR6;
	volatile uint32_t NVIC_ICPR7;
	uint32_t reserved3 [24];
	volatile uint32_t NVIC_IABR0;
	volatile uint32_t NVIC_IABR1;
	volatile uint32_t NVIC_IABR2;
	volatile uint32_t NVIC_IABR3;
	volatile uint32_t NVIC_IABR4;
	volatile uint32_t NVIC_IABR5;
	volatile uint32_t NVIC_IABR6;
	volatile uint32_t NVIC_IABR7;
	uint32_t reserved4 [56];
	volatile uint32_t NVIC_IPR[60];

	uint32_t reserved1[644];
	volatile uint32_t STIR;

}Typdef_NVIC;
#define NVIC ((Typdef_NVIC *)NVIC_base)

void NVIC_EnableIRQ(uint32_t  interrupt);
void NVIC_DisableIRQ(uint32_t  irq);
void NVIC_SetPendingIRQ(uint32_t irq);
void NVIC_ClearPendingIRQ(uint32_t irq);
void NVIC_SetPriority(uint32_t irq , uint32_t priority);
#endif /* CORE_BSP_DRIVERS_INC_NVIC_H_ */
