/*
 * uart0.cpp
 *
 *  Created on: 19 sep. 2023
 *      Author: notebook
 */

#include "uart0.h"
#include "Defines.h"
UART0_Struct		UART0;


void uart0Init(uint32_t baudrate)
{
	//elegimos la fuente de clock, habilitando la uart a usar
	SYSCON->SYSAHBCLKCTRL0 |= (1<<14); //LE PONEMOS UN 1 EN EL BIT 14 DE ESE REGISTRO

	//con el registro pinassign (8bits) le indicamos por que pin fisico queremos que salga
	SWM0->PINASSIGN.PINASSIGN0 = (8 << 0) | (9 << 8);	//Ejemplo: Tx0 = P0.8 y Rx0 = P0.9

	//configuramos la comunicación general
	USART0->CFG = 	(0<<0) //0 disable 1 enable
					|(1<<2) //cant bits
					|(0<<4) //bit de paridad
					|(0<<6) //bit de stop
					|(0<<9) //flowcontrol
					|(0<<11) //asincronica o sincronica
					|(1<<14); //slave o master

	// CONFIGURACION EXTRA
	USART0->CTL = 0;

	//habilitamos la interrupción de RX
	USART0->INTENSET = (1<<0); //en el pin 0 le ponemos un uno para habilitar la interrupción
	NVIC->ISER[0] = (1<<3);//habilitamos dentro del registro NVIC la fuente de interrupción, PONEMOS UN 1 EN EL BIT 3

	// CONFIGURACION DEL BAUDRATE
	UART0CLKSEL = 1;
	USART0->BRG = (FREQ_PRINCIPAL / baudrate) / 16; // LE ASIGNAMOS EL VALOR PARA DIVIDIR LOS 12M Y OBTENER EL BAUDRATE

	//HABILITAMOS
	USART0->CFG |= 1;
}

void UART0_IRQHandler(void) //como tenemos una sola fuente de interrupción, tenemos que analizar por bit para saber si viene por Rx y/o Tx
{
	int32_t temporal;
	uint32_t status = USART0->STAT; //leemos el registro

	if(status & (1<<0)) //leo el primer bit, RX
	{
		temporal = (int32_t)USART0->RXDAT; //aca si leemos el byte de datos recibido
		//aca como va a ir recibiendo byte tras byte, tenemos que crear buffers o algun sistema para que nada se pierda
		uart0PushTx((uint8_t)temporal);
	}
	if(status & (1<<2)) //leo el tercer bit, TX
	{
		temporal = uart0PopTx();
		if(temporal >= 0)
			USART0->TXDAT = (uint8_t)temporal;
		else
		{
			USART0->INTENCLR = (1 << 2); //disable int TX
			UART0.TX.Datos_Validos = 0;
		}
	}

}

void uart0Send(uint8_t *Datos, uint32_t Tamanio)
{
	uint32_t i;

	if(0 == Tamanio)
		Tamanio = strlen(Datos);

	for(i = 0 ; i < Tamanio ; i++)
		uart0PushTx(Datos[i]); //mando uno a uno los datos guardados en el buffer de trasmición
	return;
}


void uart0PushTx(uint8_t dato)
{
	UART0.TX.Buffer[UART0.TX.Indice_in] = dato; //voy guardando uno a uno en el buffer de trasmición

	UART0.TX.Indice_in ++;
	UART0.TX.Indice_in %= UART0_TAMANIO_COLA_TX;

	if ( UART0.TX.Datos_Validos == 0 ) //mientras no se este trasmitiendo algo, mando el primer dato del buffer
	{
		UART0.TX.Datos_Validos = 1; //y lo cambio para que no siga trasmitiendo

		USART0->TXDAT = (uint8_t)uart0PopTx(); //aca se usa la función de abajo para obtener el dato del buffer

		USART0->INTENSET = (1 << 2); // int tx //habilitamos la interrupci´+on
	}
}

int32_t uart0PopTx( void )
{
	int32_t dato = -1;

	if ( UART0.TX.Indice_in != UART0.TX.Indice_out )
	{
		dato = (int32_t) UART0.TX.Buffer[UART0.TX.Indice_out];
//		UART0.TX.Buffer[UART0.TX.Indice_out] = 0;

		UART0.TX.Indice_out ++;
		UART0.TX.Indice_out %= UART0_TAMANIO_COLA_TX;
	}
	return dato;
}

void uart0PushRx(uint8_t dato)
{
	UART0.RX.Buffer[UART0.RX.Indice_in] = dato; // cada dato que recibe la función se va guardando en un buffer para no perderlos

	UART0.RX.Indice_in ++;
	UART0.RX.Indice_in %= UART0_TAMANIO_COLA_RX;
}

int32_t uart0PopRx( void )
{
	int32_t dato = -1;

	if ( UART0.RX.Indice_in != UART0.RX.Indice_out ) //siempre que los indices de salida y entrada no sean iguales(esten ambos al principio)
	{
		dato = (int32_t) UART0.TX.Buffer[UART0.RX.Indice_out];
		UART0.RX.Indice_out ++;
		UART0.RX.Indice_out %= UART0_TAMANIO_COLA_RX;
	}
	return dato; //devuelvo el dato del buffer de recepción
}

uint32_t strlen(uint8_t *Datos)
{
	int i;

	for(i = 0 ; Datos[i] != 0 ; i++);

	return i;
}
