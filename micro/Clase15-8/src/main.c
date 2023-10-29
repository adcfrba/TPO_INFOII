/*
===============================================================================
 Name        : Parpadeo_Led.c
 Author      : Gustavo Fresno
 Description : main definition
===============================================================================
*/

#include 	"Defines.h"

#define 	PIN_LED_VERDE	1,0
#define 	PIN_LED_AZUL	1,1
#define 	PIN_LED_ROJO	1,2

#define		PIN_TECLA_USR	0,4

int main(void)
{
	uint32_t i, cont = 0, flag = 0;

	PLL_Init();

	// Encendemos modulos de GPIO
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20);

	// Inicializacion pin de salida
	GPIO_Dir(PIN_LED_VERDE, SALIDA);
	GPIO_Dir(PIN_LED_AZUL, SALIDA);
	GPIO_Dir(PIN_LED_ROJO, SALIDA);

	GPIO_Dir(PIN_TECLA_USR, ENTRADA);

	SysTick_Inic(FREQ_PRINCIPAL / FREQ_SYSTICK); //inicializamos el systic para que cada tanta
	//											frecuencia llame a la funcion que maneja las interrupciones


    while(1)
    {
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

void PLL_Init(void)
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
	SYSCON->SYSPLLCTRL               = 0x01;      // M=1 P=1

	//main_clk = fro * (M + 1) / P
	//main_clk = 24Mhz

	SYSCON->PDRUNCFG                 &= ~(1<<7);  //power up PLL after divider values changed (sec. 3.5.35)
	while((SYSCON->SYSPLLSTAT & 1) == 0);         //wait for PLL to lock

	SYSCON->MAINCLKPLLSEL            = 0x01;      //set system oscillator to the output of the PLL (sec. 3.5.11)
	SYSCON->MAINCLKPLLUEN            &= ~(1);     //write a zero to the MAINCLKUEN register (sec. 3.5.12), necessary for MAINCLKSEL to update
	SYSCON->MAINCLKPLLUEN            |= 1;        //write a one to the MAINCLKUEN register (sec. 3.5.12)
}

