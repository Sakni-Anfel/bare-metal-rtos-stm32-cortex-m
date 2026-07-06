#ifndef BASE_H_
#define BASE_H_
// external_peripheral
#include <stdint.h>
#define EXTERNAL_PERIPHERAL_BASE		(0x40000000UL)
#define AHB1_OFFSET	(0x20000UL)
#define AHB1		(EXTERNAL_PERIPHERAL_BASE + AHB1_OFFSET)

#define APB2_OFFSET (0x10000UL)
#define APB2		(EXTERNAL_PERIPHERAL_BASE + APB2_OFFSET)

#define APB1_OFFSET (0x00000UL)
#define APB1 		(EXTERNAL_PERIPHERAL_BASE + APB1_OFFSET)

#define RCC_OFFSET  (0x3800UL)
#define RCC_base			(AHB1 + RCC_OFFSET)

#define GPIOA_OFFSET	(0x0000UL)
#define GPIOA_base			(AHB1 + GPIOA_OFFSET)

#define GPIOB_OFFSET	(0x0400UL)
#define GPIOB_base		(AHB1 + GPIOB_OFFSET)

#define GPIOC_OFFSET	(0x0800UL)
#define GPIOC_base			(AHB1+GPIOC_OFFSET)

#define GPIOD_OFFSET	(0x0C00UL)
#define GPIOD_base			(AHB1 + GPIOD_OFFSET)


//internal peripheral
#define INTERNAL_PERIPHERAL_BASE 	(0xE0000000UL)

#define NVIC_OFFSET					(0xE100UL)
#define NVIC_base						(INTERNAL_PERIPHERAL_BASE + NVIC_OFFSET )

#define Systick_OFFSET				(0xE010UL)
#define Systick_base					(INTERNAL_PERIPHERAL_BASE + Systick_OFFSET)

#define SCB_OFFSET					(0xED00UL)
#define SCB_base					(INTERNAL_PERIPHERAL_BASE + SCB_OFFSET)
#define CYCLE_CLCK	16000000



#endif
