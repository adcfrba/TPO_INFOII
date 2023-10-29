/*
 * SYSTICK.c
 *
 *  Created on: Aug 3, 2021
 *      Author: Gustavo
 */


#include "Defines.h"

volatile uint16_t Divisor_1_Seg = 0;
volatile uint8_t Divisor_1_Min = 0;
volatile uint16_t Divisor_10mseg = 0;

void SysTick_Handler(void)
{
	static uint8_t Temporal = 0;

	Divisor_1_Seg++;
	if(Divisor_1_Seg > CANTIDAD_TIEMPO_SYSTICK_1SEG)
	{
		Divisor_1_Seg = 0;

		switch(Temporal)
		{
			case 0:
				Temporal++;
				GPIO_Set(PIN_LED_VERDE, 0);
				GPIO_Set(PIN_LED_AZUL, 1);
				GPIO_Set(PIN_LED_ROJO, 1);
				break;

			case 1:
				Temporal++;
				GPIO_Set(PIN_LED_VERDE, 1);
				GPIO_Set(PIN_LED_AZUL, 0);
				GPIO_Set(PIN_LED_ROJO, 1);
				break;

			case 2:
				Temporal++;
				GPIO_Set(PIN_LED_VERDE, 1);
				GPIO_Set(PIN_LED_AZUL, 1);
				GPIO_Set(PIN_LED_ROJO, 0);
				break;

			default:
				Temporal = 0;
				break;
		}
	}

}

uint32_t SysTick_Inic( uint32_t ticks )
{
	if (ticks > MAX_TICKS)
		return 1 ;          			//* Reload value impossible

	SysTick->LOAD = ticks - 1;   	//* set reload register,

	SysTick->VAL = 0;                         //* Load the SysTick Counter Value

	//* Enable SysTick IRQ and SysTick Timer
	SysTick->CTRL = 7;

	return 0;
}


