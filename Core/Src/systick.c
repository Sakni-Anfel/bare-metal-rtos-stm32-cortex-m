/*
 * systick.c
 *
 *  Created on: 30 juin 2026
 *      Author: asus
 */

#include "systick.h"

#include <stdint.h>

#include "base.h"
#include "gpio.h"
#include "scb.h"
volatile  uint32_t time;

void systick_delay(uint32_t delay){

	Systick->STK_LOAD = (CYCLE_CLCK/1000)-1;
	//clear systick current value register
	Systick->STK_VAL=0;
	//enable systick and select internal clck src
	Systick->STK_CTR |= ENABLE ;
	Systick->STK_CTR |= CLKSOURCE;

	for(uint32_t i=0; i<delay; i++){
		while((Systick->STK_CTR & COUNTFLAG)==0 ){}//empty loop wait until countflag is set so its just there to watch the counter

	}
	//FINISHING DELAY SO WE WRITE 0 TO CTRL
	Systick->STK_CTR=0;

}
void systick_init(uint32_t tick , uint8_t priority){
 uint32_t delay = CYCLE_CLCK/1000;
	Systick->STK_CTR=0;
	Systick->STK_LOAD=(delay * tick) -1;
	SCB_priority(SYSTICK, priority);
	Systick->STK_VAL=0;
	Systick->STK_CTR |= CLKSOURCE;
	Systick->STK_CTR |= TICKINT ;
	Systick->STK_CTR |= ENABLE ;
}
void SysTick_Handler(void){
	if (time >0){
		time--;
	}
	GPIO_Toggle(GPIOA ,
			PIN_5)	;
}
