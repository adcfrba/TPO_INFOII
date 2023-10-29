/*
===============================================================================
 Name        : PlantillaLPC845.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <stdio.h>
#include "LPC845.h"
#include "uart1.h"
#include "dr_pll.h"
#include "dr_systick.h"
#include "gpio.h"

uint8_t flag = 0;

int main(void)
{
	int8_t caracter;
	uint8_t estado = 0;

	Inicializar_PLL();
	Inicializar_SysTick( FREQ_PRINCIPAL / FREQ_SYSTICK * 2 );
	Inicializar_GPIO( );
	Inicializar_UART1(9600);


	while(1)
	{

		caracter = UART1_PopRx();

		if( flag )		//Cada 1 seg se pone en 1 mediante Systick
		{
			flag = 0;
			UART1_Send( (uint8_t *)"AT", 2);

		}
		switch( estado )
		{

			case 0:
				if( caracter == 'O')
				{
					estado = 1;

				}
				break;

			case 1:
				if( caracter == 'K')
				{
					estado = 0;

				}
				break;

			default:
				estado = 0;
				break;
		}

	}
    return 0 ;
}
