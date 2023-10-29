/*
 * OS_TECLADO_DRIVER.h
 *
 *  Created on: 28/09/2011
 *      Author: GustavoFresno
 */

#ifndef OS_TECLADO_DRIVER_H_
#define OS_TECLADO_DRIVER_H_

#define	NO_KEY					0xff
#define	NO_KEY_32b				0xffffffff
#define	CANTIDAD_DE_REBOTES		10
#define	CANTIDAD_DE_REBOTES_REP	200

// Definicion de los pines del teclado
#define	TECLADO_FILA_1		0,27
#define	TECLADO_FILA_2		0,29

#define	TECLADO_COLUMNA_1	0,30
#define	TECLADO_COLUMNA_2	0,31
#define	TECLADO_COLUMNA_3	0,8

#define PULSADOR_FRENTE_1	0,4

enum
{
	CODIGO_TECLA_0 = 0,
	CODIGO_TECLA_1,
	CODIGO_TECLA_2,
	CODIGO_TECLA_3,
	CODIGO_TECLA_4,
	CODIGO_TECLA_5,
	CODIGO_TECLA_6,
	CODIGO_TECLA_7,
	CODIGO_TECLA_8,
	CODIGO_TECLA_9,
	CODIGO_TECLA_10,
	CODIGO_TECLA_11,
	CODIGO_TECLA_12,
	CODIGO_TECLA_13,
	CODIGO_TECLA_14,
	CODIGO_TECLA_15,
};

void TECLADO_Barrido_SW( uint8_t );
uint8_t TECLADO_Barrido_HW(void);
void TECLADO_Inicializar(void);
void TECLADO_Barrido(void);
uint8_t TECLADO_Read_1_key_driver(void);

#endif /* OS_TECLADO_DRIVER_H_ */
