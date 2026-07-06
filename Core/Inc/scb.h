/*
 * scb.h
 *
 *  Created on: 3 juil. 2026
 *      Author: asus
 */

#ifndef CORE_BSP_DRIVERS_INC_SCB_H_
#define CORE_BSP_DRIVERS_INC_SCB_H_

#include "base.h"

typedef struct {

volatile uint32_t CPUID;
volatile uint32_t ICSR;
volatile uint32_t VTOR;
volatile uint32_t AIRCR;
volatile uint32_t SCR;
volatile uint32_t CCR;
volatile uint32_t SHPR1;
volatile uint32_t SHPR2;
volatile uint32_t SHPR3;
volatile uint32_t SHCSR;
volatile uint32_t CFSR;
volatile uint32_t HFSR;
volatile uint32_t reserved11;
volatile uint32_t MMAR;
volatile uint32_t BFAR;
volatile uint32_t AFSR;

}Typedef_SCB;
#define SCB ((Typedef_SCB *)SCB_base)
void SCB_pendSV(void);
void SCB_priority(uint32_t exception , uint8_t priority);
void SCB_priorityGroup(uint32_t pr_grp);
#endif /* CORE_BSP_DRIVERS_INC_SCB_H_ */
