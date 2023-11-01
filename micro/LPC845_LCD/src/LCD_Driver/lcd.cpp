/*
 * lcd.cpp
 *
 *  Created on: 31 oct. 2023
 *      Author: notebook
 */

#include "lcd.h"

//COMANDOS SEGUN LA TABLA PARA EL 16X2
#define		BORRAR_PANTALLA		0x01
#define 	RESETEAR_CURSOR		0x02

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
#define		PIN_LCD16X2_D3		0,8
#define		PIN_LCD16X2_D2		0,7
#define		PIN_LCD16X2_D1		0,6
#define		PIN_LCD16X2_D0		0,5


//COMO NUNCA LEO, SOLO ESCRIBO-->SIEMPRE LA DIRECCIÓN ES 1
Gpio LCD_RS(PIN_LCD16X2_RS, 1);
Gpio LCD_E(PIN_LCD16X2_E, 1);
Gpio LCD_D0(PIN_LCD16X2_D0, 1);
Gpio LCD_D1(PIN_LCD16X2_D1, 1);
Gpio LCD_D2(PIN_LCD16X2_D2, 1);
Gpio LCD_D3(PIN_LCD16X2_D3, 1);
Gpio LCD_D4(PIN_LCD16X2_D4, 1);
Gpio LCD_D5(PIN_LCD16X2_D5, 1);
Gpio LCD_D6(PIN_LCD16X2_D6, 1);
Gpio LCD_D7(PIN_LCD16X2_D7, 1);

//PARA PODER USARLA
LCD.escribir(LCD16x2_CONTROL, BORRAR_PANTALLA);
LCD.escribir(LCD16x2_CONTROL, RESETEAR_CURSOR);

LCD.escribir(LCD16x2_DATA, 'H');
LCD.escribir(LCD16x2_DATA, 'O');
LCD.escribir(LCD16x2_DATA, 'L');
LCD.escribir(LCD16x2_DATA, 'A');


void lcd::escribir(uint8_t control, uint8_t comando)
{
	//DESHABILITO EL ENABLE
	LCD_E.Set(0);

	//RS
	LCD_RS.Set(control); //cuando es 0 configuro, cuando es 1 escribo data

	//HABILITO EL ENABLE
	LCD_E.Set(1);

	//ESCRIBO LOS DATOS
	LCD_D0.Set(comando & 0x01);
	LCD_D1.Set((comando >> 1) & 0x01);
	LCD_D2.Set((comando >> 2) & 0x01);
	LCD_D3.Set((comando >> 3) & 0x01);
	LCD_D4.Set((comando >> 4) & 0x01);
	LCD_D5.Set((comando >> 5) & 0x01);
	LCD_D6.Set((comando >> 6) & 0x01);
	LCD_D7.Set((comando >> 7) & 0x01);

	//VUELVO A DESHABILITAR EL ENABLE
	LCD_E.Set(0);

}

void lcd::escribirTexto(uint8_t * texto)
{
	for(int i = 0; texto[i] != 0; i++)
	{
		LCD.escribir(LCD16x2_DATA, texto[i]);
	}
}

void lcd::escribirTextoEspecifico(uint8_t * texto, uint8_t linea, uint8_t columna)
{
	uint32_t offset = 0; //por si linea y columna valen 0

	offset = linea * 40; //cada una tiene 40
	offset += columna;

	LCD.escribir(LCD16x2_CONTROL, 0x80 + offset);
	for(int i = 0; texto[i] != 0; i++)
	{
		LCD.escribir(LCD16x2_DATA, texto[i]);
	}
}

void lcd::inicializar(void)
{

}

/*
Si estuviese en el while 1

while(1)
{
	LCD.escribir(LCD16x2_CONTROL, 0x80 + donde_quiero_que_empiece); //es necesario esta suma en
	sprintf(buffer, "%03d", temp);
	LCD.escribir(LCD16x2_DATA, buffer);
 */


/*PARA AHORRAR PIOLINES
void lcd::escribir(uint8_t control, uint8_t comando)
{
	//DESHABILITO EL ENABLE
	LCD_E.Set(0);

	//RS
	LCD_RS.Set(control); //cuando es 0 configuro, cuando es 1 escribo data

	//HABILITO EL ENABLE
	LCD_E.Set(1);

	//ESCRIBO LOS DATOS
	LCD_D0.Set(comando & 0x01);
	LCD_D1.Set((comando >> 1) & 0x01);
	LCD_D2.Set((comando >> 2) & 0x01);
	LCD_D3.Set((comando >> 3) & 0x01);
	LCD_D4.Set((comando >> 4) & 0x01);
	LCD_D5.Set((comando >> 5) & 0x01);
	LCD_D6.Set((comando >> 6) & 0x01);
	LCD_D7.Set((comando >> 7) & 0x01);

	//VUELVO A DESHABILITAR EL ENABLE
	LCD_E.Set(0);

}
 */

