/*
 * UART1_Driver.h
 *
 *  Created on: Jul 26, 2019
 *      Author: GJF-Trabajo
 */

#ifndef DRIVER_UART_UART1_DRIVER_H_
#define DRIVER_UART_UART1_DRIVER_H_

#define		UART1_TAMANIO_COLA_RX					100
#define		UART1_TAMANIO_COLA_TX					100

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART1_TAMANIO_COLA_RX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_RX;

typedef struct
{
	uint8_t						Datos_Validos;
	uint16_t					Tamanio;
	uint8_t						Buffer[UART1_TAMANIO_COLA_TX];
	uint16_t					Indice_in, Indice_out;
}STRUCT_TX;

typedef struct
{
	STRUCT_RX					RX;
	STRUCT_TX					TX;
}UART_Struct;

void UART1_Init(uint32_t baudrate);
void UART1_Send(uint8_t *Datos, uint32_t Tamanio);
void UART1_PushTx(uint8_t Dato);
int32_t UART1_PopTx( void );
void UART1_PushRx(uint8_t Dato);
int32_t UART1_PopRx( void );

#endif /* DRIVER_UART_UART1_DRIVER_H_ */
