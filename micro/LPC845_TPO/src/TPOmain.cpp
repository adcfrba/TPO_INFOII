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
void LedR(void);
void LedV(void);
void disparoADC(void);
void enviarTrama(void);
void leerData(void);
void armarTrama(uint8_t, uint8_t, uint8_t, uint8_t);

//SYSTICK
SYSTICK Systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,6,0);

//AUXILIARES GLOBALES
uint8_t flag = 0;
uint8_t flagPanico = 0;
uint8_t	bufferADC[15];
uint8_t mensajePanico[10]="TODO OK";
uint8_t bufferTrama[15];
uint8_t bufferUART[15];
uint8_t temp = -1;
uint8_t oxi = -1;
uint8_t pulso = -1;
uint8_t gas = -1;

//ADC
extern uint32_t	ADC_Cuentas[2];

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;
TIMERSW timerPanico;

int main(void) {

    ADC_Inicializar(0); //HABILITO EL DEL PIN07, DONDE ESTA EL POTE

	uart0Init(9600); //inicializamos la uart a utilizar
	timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	timerLecturaADC.Start(1000, 1000, leerData); //CADA 1 SEG LO MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(1000,1000, enviarTrama); //CADA 2 SEG ENVIA

	//SETEO DE LEDS APAGADOS
	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1) {

    	if(1==Pulsador.Read() && 0==flagPanico)
    	{
    		sprintf((char*)mensajePanico, "¡ALERTA!");
    		timerPanico.Start(2000, 2000, LedR); //PRENDO LED
    		ledR.Set(0);
    		flagPanico = 1;
    	}
		else if (1==Pulsador.Read() && 1==flagPanico)
		{
    		sprintf((char*)mensajePanico, "TODO OK");
			flagPanico = 0;
			ledR.Set(1);
    		//timerPanico.Start(10000, 10000, LedV); //PRENDO LED
			timerPanico.Stop();
		}
		else if (1==Pulsador.Read())
			ledR.Set(1);

    }
    return 0 ;

}

void LedR(void){
	static uint8_t status = 0;

	if(status){
		status = 0;
		ledR.Set(0);
	}else{
		status = 1;
		ledR.Set(1);
	}
}

void LedV(void){
	static uint8_t status = 0;

	if(status){
		status = 0;
		ledG.Set(0);
	}else{
		status = 1;
		ledG.Set(1);
	}
}

void disparoADC(void){
	static uint8_t 		CanalADC = 0;

	ADC_Disparo(CanalADC); //TENEMOS DOS SENSORES CON ADC
	CanalADC++;
	if(CanalADC > 1)
		CanalADC = 0;
}

void enviarTrama(void)
{
	//uart0Send( (uint8_t *)"<-37.2-0.1-99-100-236.3->", (uint32_t)0);
	uart0Send( (uint8_t *)bufferUART, (uint32_t)0);

}

void leerData(void)
{
	sprintf((char*)bufferADC, "ADC=%01d.%d", ADC_Cuentas[0]/1000, ADC_Cuentas[0] %1000);
	//sprintf((char*)Buffer, "ADC=%d", ADC_Cuentas[0]); POTE

}

void armarTrama(uint8_t temp, uint8_t gas, uint8_t oxi, uint8_t pulso)
{
	//sprintf(bufferTrama, "<-%03d-%02f-%03f-%03f-%04f->",temp, gas, oxi, pulso,temp+gas+oxi+pulso);
}


