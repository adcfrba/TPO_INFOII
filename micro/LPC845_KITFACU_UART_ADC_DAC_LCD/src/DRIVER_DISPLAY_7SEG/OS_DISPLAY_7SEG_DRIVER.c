//************************************************************************************************
// Archivo:				OS_GPIO_DRIVER.c
//
// Descripcion:
//
// Realizado por:		Ing. Fresno Gustavo (13/09/11)
//
//************************************************************************************************

#include "Defines.h"

uint8_t		DISPLAY_7SEG_Buffer[CANTIDAD_DIGITOS];
uint8_t		DISPLAY_7SEG_Indice;

void DISPLAY_7SEG_Inicializar(void)
{
	GPIO_Dir(PIN_BCD_A, 1);
	GPIO_Set(PIN_BCD_A, 0);

	GPIO_Dir(PIN_BCD_B, 1);
	GPIO_Set(PIN_BCD_B, 0);

	GPIO_Dir(PIN_BCD_C, 1);
	GPIO_Set(PIN_BCD_C, 0);

	GPIO_Dir(PIN_BCD_D, 1);
	GPIO_Set(PIN_BCD_D, 0);

	GPIO_Dir(PIN_RST_7SEG, 1);
	GPIO_Set(PIN_RST_7SEG, 0);

	GPIO_Dir(PIN_CK_7SEG, 1);
	GPIO_Set(PIN_CK_7SEG, 0);

	DISPLAY_7SEG_Indice = 0;
}

void DISPLAY_7SEG_Barrido(void)
{
	uint8_t	Temporal;

	GPIO_Set(PIN_CK_7SEG, 0);
	GPIO_Set(PIN_RST_7SEG, 0);

	GPIO_Set(PIN_CK_7SEG, 1);

	DISPLAY_7SEG_Indice++;
	if(DISPLAY_7SEG_Indice >= CANTIDAD_DIGITOS)
	{
		GPIO_Set(PIN_RST_7SEG, 1);
		DISPLAY_7SEG_Indice = 0;
	}

	Temporal = DISPLAY_7SEG_Buffer[CANTIDAD_DIGITOS - DISPLAY_7SEG_Indice - 1];

	GPIO_Set(PIN_BCD_A, Temporal & (1<<0));
	GPIO_Set(PIN_BCD_B, Temporal & (1<<1));
	GPIO_Set(PIN_BCD_C, Temporal & (1<<2));
	GPIO_Set(PIN_BCD_D, Temporal & (1<<3));

}

void DISPLAY_7SEG_Print(uint32_t Dato)
{
	uint32_t	i;

	if(Dato == 0)
	{
		DISPLAY_7SEG_Buffer[0] = 0;
		DISPLAY_7SEG_Buffer[1] = 0;
		DISPLAY_7SEG_Buffer[2] = 0;
		DISPLAY_7SEG_Buffer[3] = 0;
		DISPLAY_7SEG_Buffer[4] = 0;
		DISPLAY_7SEG_Buffer[5] = 0;
	}
	else
	{
		for(i = 0 ; i < CANTIDAD_DIGITOS ; i++)
		{
			DISPLAY_7SEG_Buffer[i] = Dato % 10;//Tabla_Digitos_BCD_7seg[Dato % 10];
			Dato /= 10;
		}
	}
}
