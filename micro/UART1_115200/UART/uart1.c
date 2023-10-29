/*

 * UART_Driver.c
 *
 *  Created on: May 17, 2019
 *      Author: GJF-Trabajo
 */

#include "uart1.h"

#include <LPC845.h>
#include "tipos.h"
#include "gpio.h"

UART1_Struct		UART1;

/*****************************************************************************
** Function name:		UART1_IRQHandler
**
** Descriptions:		UART interrupt handler
**
** parameters:			None
** Returned value:		None
**
*****************************************************************************/
void UART1_IRQHandler (void)
{
	int32_t Temporal;

	uint32_t	Int = USART1->STAT;

	if(Int & (1 << 0))
	{
		//RX
		Temporal = (int32_t)USART1->RXDAT;

		UART1_PushRx((uint8_t)Temporal);

	}

	if(Int & (1 << 2))
	{
		//TX
		Temporal = UART1_PopTx();
		if(Temporal >= 0)
			USART1->TXDAT = (uint8_t)Temporal;
		else
		{
			USART1->INTENCLR = (1 << 2); //disable int TX
			UART1.TX.Datos_Validos = 0;
		}

	}


}


void Inicializar_UART1(uint32_t baudrate)
{
	IOCON_config_t	Temporal;



	IOCON_config_io(IOCON_INDEX_PIO0_0, &Temporal);
	GPIO_Dir( PIN_ENABLE485, 1 );
	GPIO_Set( PIN_ENABLE485, 0 );							//ENABLE 485

	SYSCON->SYSAHBCLKCTRL0 |= (1 << 15);							// 15 = UART1

	//SWM0->PINASSIGN.PINASSIGN1 = (0x24 << 8) | (23 << 16);			// TX1 = P1.4	RX1 = P0.23
	SWM0->PINASSIGN.PINASSIGN1 = (0x10 << 8) | (0x11 << 16);			// TX1 = P0.16	RX1 = P0.17
	//SWM0->PINASSIGN.PINASSIGN1 = (0x19 << 8) | (0x18 << 16);			// TX1 = P0.25	RX1 = P0.24	VCOM
	USART1->CFG = 	(0)				// 0=DISABLE 1=ENABLE
					| (1 << 2)		// 0=7BITS 1=8BITS 2=9BITS
					| (0 << 4)		// 0=NOPARITY 2=PAR 3=IMPAR
					| (0 << 6)		// 0=1BITSTOP 1=2BITSTOP
					| (0 << 9)		// 0=NOFLOWCONTROL 1=FLOWCONTROL
					| (0 << 11)		// 0=ASINCRONICA 1=SINCRONICA
					| (1 << 14);	// 0=SLAVE 1=MASTER


	USART1->CTL = 0;

	USART1->INTENSET = (1 << 0);	//RX Y TX INTERRUPT

	UART1CLKSEL = 1;

	USART1->BRG = (FREQ_PRINCIPAL / baudrate) / 16;

	NVIC->ISER[0] = (1 << 4); /* enable interrupt */

	USART1->CFG |= 	(1);			// ENABLE USART1

	return;
}

void UART1_Send(uint8_t *Datos, uint32_t Tamanio)
{
	uint32_t i;

	/*if(0 == Tamanio)
		Tamanio = CADENAS_Strlen(Datos);
	*/
	for(i = 0 ; i < Tamanio ; i++)
		UART1_PushTx(Datos[i]);

	return;
}


void UART1_PushTx(uint8_t dato)
{
	UART1.TX.Buffer[UART1.TX.Indice_in] = dato;

	UART1.TX.Indice_in ++;
	UART1.TX.Indice_in %= UART1_TAMANIO_COLA_TX;

	if ( UART1.TX.Datos_Validos == 0 )
	{
		UART1.TX.Datos_Validos = 1;

		USART1->TXDAT = (uint8_t)UART1_PopTx();

		USART1->INTENSET = (1 << 2); // int tx
	}
}

int32_t UART1_PopTx( void )
{
	int32_t dato = -1;

	if ( UART1.TX.Indice_in != UART1.TX.Indice_out )
	{
		dato = (int32_t) UART1.TX.Buffer[UART1.TX.Indice_out];
		UART1.TX.Indice_out ++;
		UART1.TX.Indice_out %= UART1_TAMANIO_COLA_TX;
	}
	return dato;
}

void UART1_PushRx(uint8_t dato)
{
	UART1.RX.Buffer[UART1.RX.Indice_in] = dato;

	UART1.RX.Indice_in ++;
	UART1.RX.Indice_in %= UART1_TAMANIO_COLA_RX;
}

int32_t UART1_PopRx( void )
{
	int32_t dato = -1;

	if ( UART1.RX.Indice_in != UART1.RX.Indice_out )
	{
		dato = (int32_t) UART1.RX.Buffer[UART1.RX.Indice_out];
		UART1.RX.Indice_out ++;
		UART1.RX.Indice_out %= UART1_TAMANIO_COLA_RX;
	}
	return dato;
}
