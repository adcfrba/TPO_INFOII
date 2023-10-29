/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */


#include 	"Defines.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define 	PIN_LED_VERDE	1,0
#define 	PIN_LED_AZUL	1,1
#define 	PIN_LED_ROJO	1,2

#define		PIN_TECLA_USR	0,4

int main(void)
{
	uint32_t i, cont = 0, flag = 0;

	// Encendemos modulos de GPIO
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20);

	// Inicializacion pin de salida
	GPIO_Dir(PIN_LED_VERDE, SALIDA);
	GPIO_Dir(PIN_LED_AZUL, SALIDA);
	GPIO_Dir(PIN_LED_ROJO, SALIDA);

	GPIO_Dir(PIN_TECLA_USR, ENTRADA);

    while(1)
    {
    	// Loop
    	GPIO_Set(PIN_LED_VERDE, 0);
    	GPIO_Set(PIN_LED_AZUL, 1);
    	GPIO_Set(PIN_LED_ROJO, 1);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    	GPIO_Set(PIN_LED_VERDE, 1);
    	GPIO_Set(PIN_LED_AZUL, 0);
    	GPIO_Set(PIN_LED_ROJO, 1);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    	GPIO_Set(PIN_LED_VERDE, 1);
    	GPIO_Set(PIN_LED_AZUL, 1);
    	GPIO_Set(PIN_LED_ROJO, 0);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    	/*if(GPIO_Read(PIN_TECLA_USR) == 0)
    	{
    		// TECLA PRESIONADA
    		if(flag == 0)
    		{
    			flag = 1;
				cont++;

				printf("Cont=%d", cont);
    		}
    	}
    	else
    		flag = 0;*/

    }
    return 0 ;
}
