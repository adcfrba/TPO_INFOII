
#ifndef DRIVER_LCD16X2_DRIVER_LCD16X2_H_
#define DRIVER_LCD16X2_DRIVER_LCD16X2_H_

#define 	LCD16x2_CONTROL		1
#define 	LCD16x2_DATA		0

#define		PIN_LCD16X2_RS		0,23
#define		PIN_LCD16X2_E		0,22
#define		PIN_LCD16X2_D7		0,18
#define		PIN_LCD16X2_D6		0,19
#define		PIN_LCD16X2_D5		0,20
#define		PIN_LCD16X2_D4		0,21

void LCD_Escribir(uint8_t , uint8_t);
void Display_LCD( uint8_t*, uint8_t , uint8_t );
void Inicializar_LCD( void );
void LCD_Delay( void );


#endif /* DRIVER_LCD16X2_DRIVER_LCD16X2_H_ */
