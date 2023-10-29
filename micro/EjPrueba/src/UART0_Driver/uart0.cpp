/*
 * uart0.cpp
 *
 *  Created on: 19 sep. 2023
 *      Author: notebook
 */

#include "uart0.h"
#include "Defines.h"
#include "tipos.h"
#include "gpio.h"
UART0_Struct		UART0;


void uart0Init(uint32_t baudrate)
{
	IOCON_config_t	Temporal;

	IOCON_config_io(IOCON_INDEX_PIO0_0, &Temporal);
	GPIO_Dir( PIN_ENABLE485, 1 );
	GPIO_Set( PIN_ENABLE485, 0 );							//ENABLE 485

	//elegimos la fuente de clock, habilitando la uart a usar
	SYSCON->SYSAHBCLKCTRLO |= (1<<14); //LE PONEMOS UN 1 EN EL BIT 14 DE ESE REGISTRO

	//con el registro pinassign (8bits) le indicamos por que pin fisico queremos que salga
	SWMO->PINASSIGN.PINASSIGN0 = (25<<0) | (24<<8); //USAMOS 25 COMO TX Y 24 COMO RX
	//habilitamos la interrupción de RX
	USART0->INTERSET = (1<<0); //en el pin 0 le ponemos un uno para habilitar la interrupción
	NVIC->ISER[0] = (1<<3);//habilitamos dentro del registro NVIC la fuente de interrupción, PONEMOS UN 1 EN EL BIT 3

	//configuramos el baudrate a utilizar en la uart0 en el registro BRG, sabemos que la FREQ_PRINCIPAL ES 12M, y el baudrate es lo que nosotros queremos configurar
	UART0->BRG = (FREQ_PRINCIPAL / baudrate)/16; // LE ASIGNAMOS EL VALOR PARA DIVIDIR LOS 12M Y OBTENER EL BAUDRATE

	//configuramos la comunicación general
	USART0->CFG = 	(1<<0) //0 disable 1 enable
					|(1<<2) //cant bits
					|(0<<4) //bit de paridad
					|(0<<6) //bit de stop
					|(0<<9) //flowcontrol
					|(0<<11) //asincronica o sincronica
					|(0<<14) //slave o master
}

void uart0Handler(void) //como tenemos una sola fuente de interrupción, tenemos que analizar por bit para saber si viene por Rx y/o Tx
{
	int32_t temporal;
	uint32_t status = USART->STAT; //leemos el registro

	if(status & (1<<0)) //leo el primer bit, RX
	{
		temporal = (int32_t)USART0->RXDAT; //aca si leemos el byte de datos recibido
		//aca como va a ir recibiendo byte tras byte, tenemos que crear buffers o algun sistema para que nada se pierda
	}
	if(status & (1<<2)) //leo el tercer bit, TX
	{
		temporal = UART0
	}

}

void uart0Send(uint8_t *Datos, uint32_t Tamanio)
{
	uint32_t i;

	if(0 == Tamanio)
		Tamanio = strlen(Datos);

	for(i = 0 ; i < Tamanio ; i++)
		UART0_PushTx(Datos[i]); //mando uno a uno los datos guardados en el buffer de trasmición

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

		USART0->TXDAT = (uint8_t)UART0_PopTx(); //aca se usa la función de abajo para obtener el dato del buffer

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
