/*
 * lcd.h
 *
 *  Created on: 31 oct. 2023
 *      Author: notebook
 */
#include "Defines.h"
#ifndef LCD_DRIVER_LCD_H_
#define LCD_DRIVER_LCD_H_

//COMANDOS SEGUN LA TABLA PARA EL 16X2
#define		BORRAR_PANTALLA		0x01
#define 	RESETEAR_CURSOR		0x02
#define		APAGAR_LCD			0x08
#define		PREPARAR_TODO		0x0C

//MACROS PARA CONFIGURAR O PARA PONER DATOS
#define 	LCD16x2_CONTROL		0
#define 	LCD16x2_DATA		1

//PINES
#define		PIN_LCD16X2_RS		0,15
#define		PIN_LCD16X2_E		0,14
#define		PIN_LCD16X2_D7		0,13
#define		PIN_LCD16X2_D6		0,11
#define		PIN_LCD16X2_D5		0,10
#define		PIN_LCD16X2_D4		0,9
//#define		PIN_LCD16X2_D3		0,8
//#define		PIN_LCD16X2_D2		0,7
//#define		PIN_LCD16X2_D1		0,6
//#define		PIN_LCD16X2_D0		0,5

class lcd: public Gpio{
private:
	Gpio LCD_RS;
	Gpio LCD_E;
	Gpio LCD_D4;
	Gpio LCD_D5;
	Gpio LCD_D6;
	Gpio LCD_D7;
	void delay(void);

public:
	lcd();
	virtual ~lcd();
	void escribir(uint8_t control,uint8_t comando);
	void escribirTexto(uint8_t *);
	void escribirTextoEspecifico(uint8_t *, uint8_t, uint8_t);

};


#endif /* LCD_DRIVER_LCD_H_ */
