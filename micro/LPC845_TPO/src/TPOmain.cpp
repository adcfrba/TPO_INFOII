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
void inicializacion(uint8_t, uint8_t, uint8_t);

//SYSTICK
SYSTICK Systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,6,0); //PIN0_6

//AUXILIARES GLOBALES
uint8_t flag = 0;
uint8_t flagPanico = 0;
uint8_t	bufferADC[15];
uint8_t bufferAnt[15];
uint8_t bufferTrama[15];
uint8_t temp = 100;
uint8_t oxi = 0;
uint8_t pulso = 0;
uint8_t gas = 100;
uint8_t trama =1;

//ADC
extern uint32_t	ADC_Cuentas[2];

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;
TIMERSW timerPanico;

int main(void) {

	inicializacion(0, (uint8_t)9600, 1);

    while(1) {
    	if((1==Pulsador.Read()) && (0==flagPanico))
    	{
    		flagPanico = 1;
    		trama = ALERTA;
    		ledR.Set(0);
    		ledG.Set(1);
    		//timerPanico.Start(5000, 5000, LedR); //PRENDO LED
    	}
		else if ((1==Pulsador.Read()) && (1==flagPanico))
		{
			ledR.Set(1);
			ledG.Set(0);
			flagPanico = 0;
			trama = OK;
			//timerPanico.Start(0,0,LedR);
		}
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
	switch (trama)
	{
		case ALERTA:
			uart0Send( (uint8_t *)"¡ALERTA!", (uint32_t)0);
			break;
		case OK:
			uart0Send( (uint8_t *)bufferTrama, (uint32_t)0);
			break;
		default:
			trama = OK;
			break;
	}

}

void leerData(void)
{
	//analisis uno por uno del sensor
	static uint8_t CanalADC = 0;
	gas = ADC_Cuentas[CanalADC];

	if (0 == CanalADC)
	{
		temp = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		//AGREGAR FILTROS
		CanalADC++;
	}
	else if (1 == CanalADC)
	{
		gas = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		CanalADC = 0;
	}
	else
	{
		temp = -1;
		gas = -1;
		CanalADC = 0;
	}

	//sprintf((char*)bufferADC, "ADC=%01d.%d", ADC_Cuentas[0]/1000, ADC_Cuentas[0] %1000);
	//sprintf((char*)Buffer, "ADC=%d", ADC_Cuentas[0]); POTE

}

void armarTrama(uint8_t temp, uint8_t gas, uint8_t oxi, uint8_t pulso)
{
	//sprintf(bufferTrama, "<-%03d-%02f-%03f-%03f-%04f->",temp, gas, oxi, pulso,temp+gas+oxi+pulso);
}

void inicializacion(uint8_t adc, uint8_t baudrate, uint8_t leds)
{
    ADC_Inicializar(adc); //HABILITO EL DEL PIN07, DONDE ESTA EL POTE
	uart0Init(baudrate); //inicializamos la uart a utilizar

	timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	timerLecturaADC.Start(1000, 1000, leerData); //CADA 1 SEG LO MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(1000,1000, enviarTrama); //CADA 2 SEG ENVIA

	//SETEO DE LEDS APAGADOS
	ledG.Set(leds);
	ledB.Set(leds);
	ledR.Set(leds);
}


