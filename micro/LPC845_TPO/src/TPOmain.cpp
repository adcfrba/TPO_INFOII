/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "Defines.h"


//FUNCIONES A USAR
void LedR(void);
void LedV(void);
void disparoADC(void);
void enviarTrama(void);
void leerData(void);
void armarTrama(uint32_t, uint32_t, uint8_t, uint8_t);
void inicializacion(int, uint8_t);

//SYSTICK
SYSTICK Systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,1,0); //PIN0_6

//AUXILIARES GLOBALES
uint8_t flag = 0;
uint8_t flagPanico =0;
uint8_t bufferTrama[30];
uint32_t temp = 100;
uint8_t oxi = 0;
uint8_t pulso = 0;
uint32_t gas = 100;
uint8_t trama =1;
float checksum;
static uint8_t CanalADC = 0;
static uint32_t tempAnterior = 50000;
static uint32_t tempPromedio = 0;
static uint32_t tempIndex;
static uint32_t gasAnterior = 10000;
static uint32_t gasPromedio = 0;
static uint32_t gasIndex;

//ADC
extern uint32_t	ADC_Cuentas[2];

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;

int main(void) {

	inicializacion(9600, 1);

    while(1) {
    	if((1==Pulsador.Read()) && (0==flagPanico))
    	{
    		trama = ALERTA;
    		ledR.Set(0);
    	}
		else if ((15==flagPanico)) //en 30 seg se apaga
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

void leerData(void)
{
	//analisis uno por uno del sensor
	uint32_t tempLectura;
	uint32_t gasLectura;

	if (0 == CanalADC) //GAS
	{
		gasLectura = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		if(gasLectura > gasAnterior + GAS_DELTA)
			gasLectura = gasAnterior;
		else if ((gasLectura > gasAnterior + GAS_DELTA) && (gasIndex < N))
			gasLectura = gasAnterior;

		if(gasLectura != 0)
		{
			gasPromedio += gasLectura;
			gasAnterior = gasLectura;
			gasIndex++;
		}

		if(gasIndex > N)
		{
			gasIndex = 0;
			gas = gasPromedio/(N+1);
			gasAnterior = (uint32_t)gas;
			gasPromedio = 0;
		}

		CanalADC++;
	}
	else if (1 == CanalADC) //TEMPERATURA
	{

		tempLectura = ADC_Cuentas[CanalADC];
		//ANALISIS DE VALORES VALIDOS
		if(tempLectura > tempAnterior + TEMP_DELTA)
			tempLectura = tempAnterior;
		else if ((tempLectura > tempAnterior + TEMP_DELTA) && (tempIndex < N))
			tempLectura = tempAnterior;

		if(tempLectura != 0)
		{
			tempPromedio += tempLectura;
			tempAnterior = tempLectura;
			tempIndex++;
		}

		if(tempIndex > N)
		{
			tempIndex = 0;
			temp = tempPromedio/(N+1);
			tempAnterior = (uint32_t)temp;
			tempPromedio = 0;
		}

		CanalADC = 0;
	}
	else
	{
		temp = tempAnterior;
		gas = gasAnterior;
		CanalADC = 0;
	}

	oxi = MAX30102();
}

void enviarTrama(void)
{
	switch (trama)
	{
		case ALERTA:
			//uart0Send( (uint8_t *)"<-37.2-0.1-99-100-236.3->", (uint32_t)0);
			uart0Send( (uint8_t *)"<-¡ALERTA!->", (uint32_t)0);
			flagPanico++;
			break;
		case OK:
			armarTrama(temp,gas,0,0);
			uart0Send( (uint8_t *)bufferTrama, (uint32_t)0);
			break;
		case DESCONECTADO:
			uart0Send((uint8_t *) "<-DESCONECTADO->", (uint32_t)0); //avisamos que no hay nadie conectado a los sensores
		default:
			trama = OK;
			break;
	}

}

void armarTrama(uint32_t temp, uint32_t gas, uint8_t oxi, uint8_t pulso)
{
	/*
	bufferTrama[0] = '<';
	bufferTrama[1] = '-';
	bufferTrama[2] = (temp/1000) + '0';
	bufferTrama[3] = '-';
	bufferTrama[4] = (gas/1000) + '0';
	bufferTrama[5] = '-';
	bufferTrama[6] = oxi;
	bufferTrama[7] = '-';
	bufferTrama[8] = pulso;
	bufferTrama[9] = '-';
	for (int i = 0; i<10; i++)
		bufferTrama[10] ^= bufferTrama[i];
	bufferTrama[11] = '-';
	bufferTrama[12] = '>';
	bufferTrama[10] ^= 	bufferTrama[11];
	bufferTrama[10] ^= 	bufferTrama[12];

	*/
	checksum = ((float)(temp/10)+(float)(gas/100)+oxi+pulso);
	sprintf((char*)bufferTrama, "<-%d.%d-%d.%d-%d-%d-%1f->",temp/10, temp%10, gas/100, gas%100, oxi, pulso, checksum);
	//sprintf(bufferTrama, "hola");
}

void inicializacion(int baudrate, uint8_t leds)
{
    ADC_Inicializar(); //HABILITO EL DEL PIN07 Y EL 6
    TimerStart(0, 1, MAX30102_Leer , DEC );
    IIC_Inicializacion( );

	uart0Init(baudrate); //inicializamos la uart a utilizar

	timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	timerLecturaADC.Start(200, 200, leerData); //CADA 0.2 SEG LO ANALIZA Y MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(5000,5000, enviarTrama); //CADA 2 SEG ENVIA

	//SETEO DE LEDS APAGADOS
	ledG.Set(leds);
	ledB.Set(leds);
	ledR.Set(leds);
}


