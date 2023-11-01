/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include <cr_section_macros.h>

#include "Defines.h"
#include <stdio.h>

//FUNCIONES A USAR
void Led(void);
void disparoADC(void);
void enviarTrama(void);
void leerData(void);

//SYSTICK
SYSTICK Systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,4,0);

//AUXILIARES GLOBALES
uint8_t flag = 0;
uint8_t	Buffer[15];

//ADC
extern uint32_t	ADC_Cuentas[2];

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;

int main(void)
{
    ADC_Inicializar(1); //HABILITO EL DEL PIN07, DONDE ESTA EL POTE
    //con ADC_Cuentas[] leo el resultado del adc
	uart0Init(9600); //INICIO A NUESTRA UART
	//timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	//timerLecturaADC.Start(1000, 1000, leerData); //CADA 1 SEG LO MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(1000,1000, enviarTrama); //CADA 2 SEG ENVIA

	//SETEO DE LEDS APAGADOS
	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1)
    {

    	if(0==Pulsador.Read())
		{
			ledB.Set(0);
			uart0Send( (uint8_t *)"<-37.2-0.1-99-100-236.3->", (uint32_t)0);
		}
		else
			ledB.Set(1);
    }
}


//DESARROLLO FUNCIONES
void Led(void){
	static uint8_t status = 0;

	if(status){
		status = 0;
		ledB.Set(1);
	}else{
		status = 1;
		ledB.Set(0);
	}
}

void disparoADC(void){
	static uint8_t 		CanalADC = 1;

	ADC_Disparo(CanalADC);
	/*CanalADC++;
	if(CanalADC > 1)
		CanalADC = 0;
		*/
}

void enviarTrama(void)
{
	uart0Send( (uint8_t *)"<-37.2-0.1-99-100-236.3->", (uint32_t)0);
	//uart0Send( (uint8_t *)"AT+NAMEbaymaxINFO2023", (uint32_t)0);

}

void leerData(void)
{
	sprintf((char*)Buffer, "ADC=%01d.%d", ADC_Cuentas[0]/1000, ADC_Cuentas[0] %1000);
	//sprintf((char*)Buffer, "ADC=%d", ADC_Cuentas[0]); POTE

}


