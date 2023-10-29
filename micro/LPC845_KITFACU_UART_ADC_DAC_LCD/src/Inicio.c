/*
===============================================================================
 Name        : Inicio.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "Defines.h"

#include <stdio.h>


extern uint32_t	ADC_Cuentas[2];

uint8_t		Buffer[15];
uint8_t		Tecla = NO_KEY;


// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void)
{
    PLL_Init();

    GPIO_Inicializacion();

    TECLADO_Inicializacion();

    LCD_Inicializar();

    DISPLAY_7SEG_Inicializar();

    ADC_Inicializar();

    SysTick_Inic(FREQ_PRINCIPAL / FREQ_SYSTICK * 2);

    //UART1_Init(9600);

    //DISPLAY_7SEG_Print(123456);

    while(1)
    {
    	DISPLAY_7SEG_Print(ADC_Cuentas);

    	sprintf(Buffer, "ADC=%01d.%d", ADC_Cuentas[0]/1000, ADC_Cuentas[0] %1000);
    	//sprintf(Buffer, "ADC=%f", ADC_Cuentas);
    	LCD_Display(Buffer, 0, 0);

    	sprintf(Buffer, "ADC=%01d.%d", ADC_Cuentas[1]/1000, ADC_Cuentas[1] %1000);
    	LCD_Display(Buffer, 1, 0);

    	Tecla = TECLADO_Read_1_key_driver();
    	if(Tecla != NO_KEY)
    	{
        	sprintf(Buffer, "TECLA=%03d", Tecla);
        	LCD_Display(Buffer, 1, 0);
    	}

//    	GPIO_Set( PIN_AZUL, 0 );
//    	GPIO_Set( PIN_VERDE, 1 );
//    	GPIO_Set( PIN_ROJO, 1 );
// //   	UART1_Send((uint8_t*)"GJF\r\n", 0);
////
//    	for(i = 0 ; i < 500000 ; i++);
////
//    	GPIO_Set( PIN_AZUL, 1 );
//    	GPIO_Set( PIN_VERDE, 0 );
//    	GPIO_Set( PIN_ROJO, 1 );
////
//    	for(i = 0 ; i < 500000 ; i++);
////
//    	GPIO_Set( PIN_AZUL, 1 );
//    	GPIO_Set( PIN_VERDE, 1 );
//    	GPIO_Set( PIN_ROJO, 0 );
////
//    	for(i = 0 ; i < 500000 ; i++);
     }

    return 0 ;
}

void PLL_Init(void) //(fin=12Mhz ==> fout=24Mhz)
{
	// Por default el FRO interno tiene 12Mhz

	SYSCON->SYSAHBCLKDIV             = 0x1;       //set clock divider for core to 1
	SYSCON->MAINCLKSEL               &= ~(0x03);  //set "main clock" to IRC oscillator, if not system will lock up when PLL turns off!(sec. 3.5.11)

	SYSCON->MAINCLKUEN               &= ~(1);     //write a zero to the MAINCLKUEN register (sec. 3.5.12), necessary for MAINCLKSEL to update
	SYSCON->MAINCLKUEN               |= 1;        //write a one to the MAINCLKUEN register (sec. 3.5.12), necessary for MAINCLKSEL to update

	SYSCON->SYSPLLCLKSEL             = 0;      	  //connect IRC oscillator to SYSTEM PLL (sec. 3.5.9)

	SYSCON->SYSPLLCLKUEN             &= ~(1);     //write a zero to SYSPLLUEN register (sec. 3.5.10), necessary for SYSPLLCLKSEL to update
	SYSCON->SYSPLLCLKUEN             |= 1;        //write a one to SYSPLLUEN register (sec. 3.5.10), necessary for SYSPLLCLKSEL to update

	SYSCON->PDRUNCFG                 |= (1<<7);   //power down the PLL before changing divider values (sec 3.5.35)
	SYSCON->SYSPLLCTRL               = 0x23;      // M=3 P=1

	//main_clk = fro * (M + 1) / P
	//main_clk = 24Mhz

	SYSCON->PDRUNCFG                 &= ~(1<<7);  //power up PLL after divider values changed (sec. 3.5.35)
	while((SYSCON->SYSPLLSTAT & 1) == 0);         //wait for PLL to lock

	SYSCON->MAINCLKPLLSEL            = 0x01;      //set system oscillator to the output of the PLL (sec. 3.5.11)
	SYSCON->MAINCLKPLLUEN            &= ~(1);     //write a zero to the MAINCLKUEN register (sec. 3.5.12), necessary for MAINCLKSEL to update
	SYSCON->MAINCLKPLLUEN            |= 1;        //write a one to the MAINCLKUEN register (sec. 3.5.12)
}

