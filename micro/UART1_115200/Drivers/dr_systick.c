/*
 * TIMER_DRIVER.c
 *
 *  Created on: Jul 25, 2019
 *      Author: GJF-Trabajo
 */

#include "dr_systick.h"
#include "core_cm0plus.h"
#include "gpio.h"

#define MAX_TICKS 	0xffffff
extern uint8_t flag;

void SysTick_Handler(void)
{
	static uint32_t milisegundos = 0;


	milisegundos ++;

	if( milisegundos == 1000  )
	{
		milisegundos = 0;
		flag ++;
		flag %= 2;

		if( flag )
			GPIO_Set( PIN_ROJO, LED_OFF );
		else
			GPIO_Set( PIN_ROJO, LED_ON );

	}

}

uint32_t Inicializar_SysTick( uint32_t ticks )
{
	if (ticks > MAX_TICKS)
		return 1 ;          			//* Reload value impossible

	SysTick->LOAD = ticks - 1;   		//* set reload register


	//SysTick->LOAD = (SysTick->CALIB)/10 -1;   		//* set reload register

	SysTick->VAL = 0;                   //* Load the SysTick Counter Value

	SysTick->CTRL = 7;					//* Enable SysTick IRQ and SysTick Timer

	return 0;
}

