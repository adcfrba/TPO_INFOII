/*
 * SYSTICK.cpp
 *
 *  Created on: 15 ago. 2023
 *      Author: gusta
 */

#include "Defines.h"

extern Gpio ledG;
extern Gpio ledR;
extern Gpio ledB;

SYSTICK::SYSTICK( uint32_t FrecuenciaSystick )
{
	uint32_t  ticks ;

	ticks = FREQ_PRINCIPAL / FrecuenciaSystick;  		// ticks = Tsystic / Tclock ;

	if (ticks > MAX_TICKS)
		return;          		//* Reload value fuera de rango

	SysTick->RELOAD = ticks - 1;  	//* Cargamos la Cuenta

	SysTick->CURR = 0;   			//* SysTick Counter en 0 para que se recargue

	SysTick->CTRL = 7;	// ENABLE = 1, TICKINT = 1, CLKSOURCE = 1;

	return;
}

void SysTick_Handler(void)
{
	static uint8_t status = 0;
	static uint16_t divisor = 0;

	divisor++; //es lo que va "contando"
	if(divisor >= 1000){
		divisor = 0;

		if(status){
			status = 0;
			ledR.Set(1);
			ledB.Set(0);
		}else{
			status = 1;
			ledR.Set(0);
			ledB.Set(1);
		}
	}
}
