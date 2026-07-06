/*
 * scb.c
 *
 *  Created on: 4 juil. 2026
 *      Author: asus
 */
#include "scb.h"

#include "stdint.h"


#define PENDSVSET 	(1UL<<28)
#define PEND_PRI	20
#define SYS_PRI		28
#define PENDSV		1
#define SYSTICK		0
#define VECTKEY		16
#define PRIGROUP	8
void SCB_pendSV(void){

	SCB->ICSR |=PENDSVSET;
}
void SCB_priority(uint32_t exception , uint8_t priority){

	if (exception == PENDSV){
		SCB->SHPR3 &= ~(0x0f<<PEND_PRI);
		SCB->SHPR3|= (priority & 0x0f<<PEND_PRI);
	}
	else if (exception == SYSTICK){
		SCB->SHPR3 &= ~(0x0f<<SYS_PRI);
		SCB->SHPR3|= (priority & 0x0f<<SYS_PRI);
		/* we added mask here cause the max priority value is 15
		*
		*so to prevent it pass it we add &0x0f
		 plus we could only write in the 4 bits not 8
		*/
	}

}
void SCB_priorityGroup(uint32_t pr_grp){
	uint32_t grp= SCB->AIRCR;
	grp &=~(0x7<<PRIGROUP);
	grp |=(pr_grp<<PRIGROUP);
	grp &=~(0xffffUL<<VECTKEY);
	grp|=(0x5faUL<<VECTKEY);
	SCB->AIRCR=grp;

}
