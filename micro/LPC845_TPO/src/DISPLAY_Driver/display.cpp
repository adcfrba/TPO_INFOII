#include "Defines.h"
/*
void LCD_Escribir(uint8_t control , uint8_t comando)
{
	int32_t q , i = 1;

	//DESHABILITO EL ENABLE
	//LCD_E.Set(0);

	do
	{
		//ESCRIBO LOS DATOS
		LCD_D7.Set((comando >> (3+i*4)) & 0x01);
		LCD_D6.Set((comando >> (2+i*4)) & 0x01);
		LCD_D5.Set((comando >> (1+i*4)) & 0x01);
		LCD_D4.Set((comando >> (0+i*4)) & 0x01);

		//RS
		LCD_RS.Set(control); //cuando es 0 configuro, cuando es 1 escribo data

		//HABILITO EL ENABLE
		LCD_E.Set(1);
		for( q = 0 ; q < 400 ; q++ );

		//VUELVO A DESHABILITAR EL ENABLE
		LCD_E.Set(0);
		for( q = 0 ; q < 14000 ; q++ );
	}
	while ( i-- );

}

void Display_LCD( uint8_t *texto , uint8_t linea , uint8_t columna )
{
	uint32_t offset = 0; //por si linea y columna valen 0

	offset = linea * 40; //cada una tiene 40
	offset += columna;

	LCD_Escribir(LCD16x2_CONTROL, 0x80 + offset);

	for(int i = 0; texto[i] != 0; i++)
		LCD_Escribir(LCD16x2_DATA, texto[i]);
}

void LCD_Delay( void )
{
  uint32_t 	i;

  for ( i = 0 ; i < 500000 ; i++ ); // 300000
}
void Inicializar_LCD( void )
{
	uint32_t i, j;
	//INICIALMENTE TODO EN 0
	LCD_E.Set(0);
	LCD_RS.Set(0);
	LCD_D7.Set(0);
	LCD_D6.Set(0);
	LCD_D5.Set(0);
	LCD_D4.Set(0);
	for( i = 0 ; i < 3 ; i++ )
		{
			LCD_E.Set(0);
			LCD_Delay( );
			LCD_D7.Set(0);
			LCD_D6.Set(0);
			LCD_D5.Set(1);
			LCD_D4.Set(1);

			//O ES CONFIGURACIÓN
			LCD_RS.Set(0);
			//HABILITO ENABLE
			LCD_E.Set(1);

			for( j = 0 ; j < 10000 ; j++ );//4500
			//VUELVO A DESHABILITAR
			LCD_E.Set(0);
		}

		//DESHABILITO ENABLE
		LCD_E.Set(0);
		LCD_Delay();

		LCD_D7.Set(0);
		LCD_D6.Set(0);
		LCD_D5.Set(1);
		LCD_D4.Set(0);

		//CONFIGURACIÓN Y HABILITO ENABLE
		LCD_RS.Set(0);
		LCD_E.Set(1);

		for( j = 0 ; j < 10000 ; j++ );//ESPERO
		//DESHABILITO ENABLE
		LCD_E.Set(0);

		//LO DEJO CLEAN Y RESETEO CURSOR TODO CON 4 BITS
		LCD_Escribir(LCD16x2_CONTROL, APAGAR_LCD);
		LCD_Escribir(LCD16x2_CONTROL, BORRAR_PANTALLA);
		LCD_Escribir(LCD16x2_CONTROL, RESETEAR_CURSOR);
		LCD_Escribir(LCD16x2_CONTROL, PREPARAR_TODO);
}
*/

