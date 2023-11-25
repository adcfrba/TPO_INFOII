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
#define		PIN_LCD16X2_RS		0,23
#define		PIN_LCD16X2_E		0,22
#define		PIN_LCD16X2_D7		0,18
#define		PIN_LCD16X2_D6		0,19
#define		PIN_LCD16X2_D5		0,20
#define		PIN_LCD16X2_D4		0,21

class lcd: public Gpio{
private:
	Gpio LCD_RS;
	Gpio LCD_E;
	Gpio LCD_D4;
	Gpio LCD_D5;
	Gpio LCD_D6;
	Gpio LCD_D7;
	void LCD_Delay(void);

public:
	lcd();
	virtual ~lcd();
	void LCD_Escribir(uint8_t control,uint8_t comando);
	void escribirTexto(uint8_t *);
	void Display_LCD(uint8_t *, uint8_t, uint8_t);

};


#endif /* LCD_DRIVER_LCD_H_ */
