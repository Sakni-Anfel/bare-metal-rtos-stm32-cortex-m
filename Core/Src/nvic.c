/*
 * nvic.c
 *
 *  Created on: 2 juil. 2026
 *      Author: asus
 */

#include "nvic.h"

#include "stdint.h"
#include <stdbool.h>

#define ISER0_end	31

#define ISER1_start	32
#define	ISER1_end 	63

#define ISER2_start	64
#define	ISER2_end 	95

#define ISER3_start	96
#define	ISER3_end 	127

#define ISER4_start	128
#define	ISER4_end 	159

#define ISER5_start	160
#define	ISER5_end 	191

#define ISER6_start	192
#define	ISER6_end 	223

#define ISER7_start	224
#define	ISER7_end 	239


void NVIC_EnableIRQ(uint32_t interrupt){

	if(interrupt <=ISER0_end){
NVIC->NVIC_ISER0 |=(uint32_t)(1UL<<interrupt);}
	else if (interrupt <=ISER1_end && interrupt >ISER0_end){
		NVIC->NVIC_ISER1 |=(uint32_t)(1UL<<(interrupt-ISER1_start));
	}
	else if (interrupt <=ISER2_end && interrupt > ISER1_end){
			NVIC->NVIC_ISER2 |=(uint32_t)(1UL<<(interrupt-ISER2_start));
		}
	else if (interrupt <=ISER3_end && interrupt > ISER2_end){
			NVIC->NVIC_ISER3 |=(uint32_t)(1UL<<(interrupt-ISER3_start));
		}
	else if (interrupt <=ISER4_end && interrupt > ISER3_end){
			NVIC->NVIC_ISER4 |=(uint32_t)(1UL<<(interrupt-ISER4_start));
		}
	else if (interrupt <=ISER5_end && interrupt > ISER4_end){
			NVIC->NVIC_ISER5 |=(uint32_t)(1UL<<(interrupt-ISER5_start));
		}
	else if (interrupt <=ISER6_end && interrupt > ISER5_end){
			NVIC->NVIC_ISER6 |=(uint32_t)(1UL<<(interrupt-ISER6_start));
		}
	else if (interrupt <=ISER7_end && interrupt >ISER6_end){
			NVIC->NVIC_ISER7 |=(uint32_t)(1UL<<(interrupt-ISER7_start));
		}
	else {
		//return false; todo i will add error handling here incase of irq >239
	}
}

void NVIC_DisableIRQ(uint32_t  irq){

	if(irq <=ISER0_end){
NVIC->NVIC_ICER0 |=(uint32_t)(1UL<<irq);}
	else if (irq <=ISER1_end && irq >ISER0_end){
		NVIC->NVIC_ICER1 |=(uint32_t)(1UL<<(irq-ISER1_start));
	}
	else if (irq <=ISER2_end && irq > ISER1_end){
			NVIC->NVIC_ICER2 |=(uint32_t)(1UL<<(irq-ISER2_start));
		}
	else if (irq <=ISER3_end && irq > ISER2_end){
			NVIC->NVIC_ICER3 |=(uint32_t)(1UL<<(irq-ISER3_start));
		}
	else if (irq <=ISER4_end && irq > ISER3_end){
			NVIC->NVIC_ICER4 |=(uint32_t)(1UL<<(irq-ISER4_start));
		}
	else if (irq <=ISER5_end && irq > ISER4_end){
			NVIC->NVIC_ICER5 |=(uint32_t)(1UL<<(irq-ISER5_start));
		}
	else if (irq <=ISER6_end && irq > ISER5_end){
			NVIC->NVIC_ICER6 |=(uint32_t)(1UL<<(irq-ISER6_start));
		}
	else if (irq <=ISER7_end && irq >ISER6_end){
			NVIC->NVIC_ICER7 |=(uint32_t)(1UL<<(irq-ISER7_start));
		}
	else {
		//return false; TODO i will add error handling here incase of irq >239
	}
}

void NVIC_SetPendingIRQ(uint32_t irq){

	if(irq <=ISER0_end){
	NVIC->NVIC_ISPR0 |=(uint32_t)(1UL<<irq);}
		else if (irq <=ISER1_end && irq >ISER0_end){
			NVIC->NVIC_ISPR1 |=(uint32_t)(1UL<<(irq-ISER1_start));
		}
		else if (irq <=ISER2_end && irq > ISER1_end){
				NVIC->NVIC_ISPR2 |=(uint32_t)(1UL<<(irq-ISER2_start));
			}
		else if (irq <=ISER3_end && irq > ISER2_end){
				NVIC->NVIC_ISPR3 |=(uint32_t)(1UL<<(irq-ISER3_start));
			}
		else if (irq <=ISER4_end && irq > ISER3_end){
				NVIC->NVIC_ISPR4 |=(uint32_t)(1UL<<(irq-ISER4_start));
			}
		else if (irq <=ISER5_end && irq > ISER4_end){
				NVIC->NVIC_ISPR5 |=(uint32_t)(1UL<<(irq-ISER5_start));
			}
		else if (irq <=ISER6_end && irq > ISER5_end){
				NVIC->NVIC_ISPR6 |=(uint32_t)(1UL<<(irq-ISER6_start));
			}
		else if (irq <=ISER7_end && irq >ISER6_end){
				NVIC->NVIC_ISPR7 |=(uint32_t)(1UL<<(irq-ISER7_start));
			}
		else {
			//return false; TODO i will add error handling here incase of irq >239
		}
}

void NVIC_ClearPendingIRQ(uint32_t irq){

	if(irq <=ISER0_end){
		NVIC->NVIC_ICPR0 |=(uint32_t)(1UL<<irq);}
			else if (irq <=ISER1_end && irq >ISER0_end){
				NVIC->NVIC_ICPR1 |=(uint32_t)(1UL<<(irq-ISER1_start));
			}
			else if (irq <=ISER2_end && irq > ISER1_end){
					NVIC->NVIC_ICPR2 |=(uint32_t)(1UL<<(irq-ISER2_start));
				}
			else if (irq <=ISER3_end && irq > ISER2_end){
					NVIC->NVIC_ICPR3 |=(uint32_t)(1UL<<(irq-ISER3_start));
				}
			else if (irq <=ISER4_end && irq > ISER3_end){
					NVIC->NVIC_ICPR4 |=(uint32_t)(1UL<<(irq-ISER4_start));
				}
			else if (irq <=ISER5_end && irq > ISER4_end){
					NVIC->NVIC_ICPR5 |=(uint32_t)(1UL<<(irq-ISER5_start));
				}
			else if (irq <=ISER6_end && irq > ISER5_end){
					NVIC->NVIC_ICPR6 |=(uint32_t)(1UL<<(irq-ISER6_start));
				}
			else if (irq <=ISER7_end && irq >ISER6_end){
					NVIC->NVIC_ICPR7 |=(uint32_t)(1UL<<(irq-ISER7_start));
				}
			else {
				//return false; TODO i will add error handling here incase of irq >239
			}
}

void NVIC_SetPriority(uint32_t irq , uint32_t priority)
{
uint32_t regiter_index = (uint32_t) irq/4;
uint32_t pos = (uint32_t) irq % 4;
NVIC->NVIC_IPR[regiter_index] &=~(0xffUL<<(pos*8));
	NVIC->NVIC_IPR[regiter_index] |=(uint32_t)(priority<<(pos*8));

}
