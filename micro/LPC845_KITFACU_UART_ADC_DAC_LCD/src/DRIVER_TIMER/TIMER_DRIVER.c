/*
 * TIMER_DRIVER.c
 *
 *  Created on: Jul 25, 2019
 *      Author: GJF-Trabajo
 */


#include "Defines.h"


#define	SEGUNDOS	1000
#define MAX_TICKS 	0xffffff

volatile uint16_t segundos = SEGUNDOS;

void SysTick_Handler(void)
{
	static uint8_t		Parpadeo = 0;
	static uint8_t 		CanalADC = 0;

	DISPLAY_7SEG_Barrido();

	TECLADO_Barrido();

	ADC_Disparo(CanalADC);
	CanalADC++;
	if(CanalADC > 1)
		CanalADC = 0;

	segundos--;
	if(!segundos)
	{
		segundos = SEGUNDOS;



		switch(Parpadeo)
		{
			case 0:
				GPIO_Set( PIN_AZUL, 0 );
				GPIO_Set( PIN_VERDE, 1 );
				GPIO_Set( PIN_ROJO, 1 );
				break;

			case 1:
				GPIO_Set( PIN_AZUL, 1 );
				GPIO_Set( PIN_VERDE, 0 );
				GPIO_Set( PIN_ROJO, 1 );
				break;

			case 2:
				GPIO_Set( PIN_AZUL, 1 );
				GPIO_Set( PIN_VERDE, 1 );
				GPIO_Set( PIN_ROJO, 0 );
				break;

			default:
				break;
		}
		Parpadeo++;
		Parpadeo %= 3;
	}

}

uint32_t SysTick_Inic( uint32_t ticks )
{
	if (ticks > MAX_TICKS)
		return 1 ;          			//* Reload value impossible

	SysTick->LOAD = ticks - 1;   	//* set reload register

	SysTick->VAL = 0;                         //* Load the SysTick Counter Value

	//* Enable SysTick IRQ and SysTick Timer
	SysTick->CTRL = 7;

	return 0;
}

