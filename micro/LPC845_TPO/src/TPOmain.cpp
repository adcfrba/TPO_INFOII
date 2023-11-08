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


//FUNCIONES A USAR
void LedR(void);
void LedV(void);
void disparoADC(void);
void enviarTrama(void);
void leerData(void);
void armarTrama(float, float, uint8_t, uint8_t);
void inicializacion(uint8_t, uint8_t);

//SYSTICK
SYSTICK Systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,4,0); //PIN0_6

//AUXILIARES GLOBALES
uint8_t flag = 0;
uint8_t flagPanico = 0;
char bufferTrama[15];
float temp = 100;
uint8_t oxi = 0;
uint8_t pulso = 0;
float gas = 100;
uint8_t trama =1;

//ADC
extern uint32_t	ADC_Cuentas[2];

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;
TIMERSW timerPanico;

int main(void) {

	inicializacion((uint8_t)9600, 1);

    while(1) {
    	if((0==Pulsador.Read()) && (0==flagPanico))
    	{
    		flagPanico = 1;
    		trama = ALERTA;
    		ledR.Set(0);
    	}
		else if ((0==Pulsador.Read()) && (1==flagPanico))
		{
			ledR.Set(1);
			flagPanico = 0;
			trama = OK;
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


void disparoADC(void){
	static uint8_t 		CanalADC = 0;

	ADC_Disparo(CanalADC); //TENEMOS DOS SENSORES CON ADC
	CanalADC++;
	if(CanalADC > 1)
		CanalADC = 0;
}

void enviarTrama(void)
{
	switch (trama)
	{
		case ALERTA:
			//uart0Send( (uint8_t *)"<-37.2-0.1-99-100-236.3->", (uint32_t)0);
			uart0Send( (uint8_t *)"¡ALERTA!", (uint32_t)0);
			break;
		case OK:
			armarTrama(0,0,0,0);
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
	static uint8_t tempAnterior = 20;
	static uint8_t tempPromedio;
	uint8_t tempLectura;
	static uint8_t tempIndex;
	static uint8_t gasAnterior = 1;
	static uint8_t gasPromedio;
	static uint8_t gasIndex;
	uint8_t gasLectura;


	if (0 == CanalADC) //TEMPERATURA
	{
		tempLectura = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		if(tempLectura > tempAnterior + TEMP_DELTA)
			tempLectura = tempAnterior;
		else if (tempLectura > tempAnterior + TEMP_DELTA && tempIndex < N)
			tempLectura = tempAnterior;

		tempPromedio += tempLectura;
		tempIndex++;
		if(tempIndex > N)
		{
			tempIndex = 0;
			temp = tempPromedio/N;
		}

		CanalADC++;
	}
	else if (1 == CanalADC) //GAS
	{
		gasLectura = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		if(gasLectura > gasAnterior + GAS_DELTA)
			gasLectura = gasAnterior;
		else if (gasLectura > gasAnterior + GAS_DELTA && gasIndex < N)
			gasLectura = gasAnterior;

		gasPromedio += gasLectura;
		gasIndex++;
		if(gasIndex > N)
		{
			gasIndex = 0;
			gas = gasPromedio/N;
		}
		CanalADC = 0;
	}
	else
	{
		temp = -1;
		gas = -1;
		CanalADC = 0;
	}
}

void armarTrama(float temp, float gas, uint8_t oxi, uint8_t pulso)
{
	//sprintf(bufferTrama, "<-%03d-%02f-%03f-%03f-%04f->",temp, gas, oxi, pulso,temp+gas+oxi+pulso);
	sprintf(bufferTrama, "hola");
}

void inicializacion(uint8_t baudrate, uint8_t leds)
{
    ADC_Inicializar(); //HABILITO EL DEL PIN07, DONDE ESTA EL POTE
	uart0Init(baudrate); //inicializamos la uart a utilizar

	timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	timerLecturaADC.Start(200, 200, leerData); //CADA 0.2 SEG LO ANALIZA Y MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(2000,2000, enviarTrama); //CADA 2 SEG ENVIA

	//SETEO DE LEDS APAGADOS
	ledG.Set(leds);
	ledB.Set(leds);
	ledR.Set(leds);
}


