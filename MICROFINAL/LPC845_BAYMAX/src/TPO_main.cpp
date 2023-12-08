#include "Defines.h"

//VARIABLES GLOBAL
uint8_t flag = 0;
uint8_t flagPanico =0;
uint8_t bufferTrama[30];
uint32_t temp = 100;
uint8_t oxi = 0;
uint32_t gas = 100;
uint8_t trama = DESCONECTADO; //Inicialmente
float checksum;
static uint8_t CanalADC = 0;
uint8_t Buffer_linea_1[30];
uint8_t Buffer_linea_2[30];

//FILTRO DE DATA
static uint32_t tempAnterior = 50000; //fuera de rango
static uint32_t tempPromedio = 0;
static uint32_t tempIndex = 0;
static uint32_t gasAnterior = 10000; //fuera de rango
static uint32_t gasPromedio = 0;
static uint32_t gasIndex = 0;
static uint8_t oxiAnterior = 200; //fuera de rango
static uint8_t oxiPromedio = 0;
static uint8_t oxiIndex = 0;

//ADC
extern uint32_t	ADC_Cuentas[2];

//MAX30102
extern uint8_t demora_i2c;
extern uint8_t leerMAX30102;

//SYSTICK
SYSTICK systick(1000);

//LEDS
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

//PULSADOR EMERGENCIA
GPIOF Pulsador(0,3,0); //PIN0_15

//UART

//TIMERS
TIMERSW timerDisparoADC;
TIMERSW timerUART0;
TIMERSW timerLecturaADC;
TIMERSW timerLecturaMAX;
TIMERSW timerLCD;

//LDC
LCD miLcd;

//FUNCIONES A USAR
void disparoADC(void);
void enviarTrama(void);
void leerData(void);
void armarTrama(uint32_t, uint32_t, uint8_t);
void inicializacion(int, uint8_t);
void demorai2c (void);
void imprimirLCD(void);

/*********************************************************************************************
 *** MAIN
 *********************************************************************************************/
int main(void) {

	//SETUP
	inicializacion(9600, 1);
	miLcd.row(0).pos(5) << "BAYMAX";
	miLcd.row(1) << "(Anto-Gabi-Eze)";

	//LOOP
	while(1)
	{
    	if((1==Pulsador.Read()) && (0==flagPanico))
    	{
    		flagPanico = 1;
    		trama = ALERTA;
    		ledR.Set(0);
    	}
		else if ((5==flagPanico))
		{
			ledR.Set(1);
			flagPanico = 0;
			trama = OK;
		}
	}
    return 0 ;
}

//FUNCIONES

void disparoADC(void){
	static uint8_t 		CanalADC = 0;

	ADC_Disparo(CanalADC); //TENEMOS DOS SENSORES CON ADC
	CanalADC++;
	if(CanalADC > 1)
		CanalADC = 0;
}

void leerData(void)
{
	//analisis uno por uno del sensor + filtros
	uint32_t tempLectura;
	uint32_t gasLectura;
	uint8_t oxiLectura;

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

			if(flagPanico == 0)
				trama = OK;

			if(gas > (uint32_t)GASMAX)
				trama = ALERTA;
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

			if(flagPanico == 0)
				trama = OK;

			if(temp > TEMPMAX)
				trama = ALERTA;
		}

		CanalADC = 0;
	}
	else
	{
		temp = tempAnterior;
		gas = gasAnterior;
		CanalADC = 0;
	}

	//OXIGENO
	oxiLectura = MAX30102();
	if((0 == oxiLectura) && (flagPanico == 0))
		trama = DESCONECTADO;
	else if (oxiLectura < OXIMIN)
		trama = ALERTA;
	else
	{
		oxi = oxiLectura;
		trama = OK;
	}

}

void enviarTrama(void)
{
	switch (trama)
	{
		case ALERTA:
			uart0Send((uint8_t *)" <-¡ALERTA!->", (uint32_t)0);
			miLcd.clear();
			miLcd.row(0).pos(5) << "ALERTA";
			flagPanico++;
			break;
		case OK:
			armarTrama(temp,gas,oxi);
			uart0Send((uint8_t *)bufferTrama, (uint32_t)0);
			miLcd.clear();
			miLcd.row(0) << (const char*)Buffer_linea_1;
			miLcd.row(1) << (const char*)Buffer_linea_2;
			break;
		case DESCONECTADO:
			uart0Send((uint8_t *) " <-DESCONECTADO->", (uint32_t)0); //avisamos que no hay nadie conectado a los sensores
			miLcd.clear();
			miLcd.row(0).pos(2) << "DESCONECTADO";
			break;
		default:
			trama = OK;
			break;
	}

}

void armarTrama(uint32_t temp, uint32_t gas, uint8_t oxi)
{
	checksum = ((float) temp/10) + ((float)gas/100) + (float)oxi;
	sprintf((char*)bufferTrama, " <-%d.%d-%d.%d-%d-%.2f->",temp/10, temp%10, gas/100, gas%100, oxi, checksum);
	sprintf((char *)Buffer_linea_1, "sPO2:%d T:%d.%dC",oxi,temp/10, temp%10);
	sprintf((char *)Buffer_linea_2, "CO2:%d.%dppm",gas/100, gas%100);
}

void inicializacion(int baudrate, uint8_t leds)
{
	//ADC
    ADC_Inicializar(); //HABILITO EL DEL PIN07 Y EL 6
    IIC_Inicializacion( );

    //UART
	uart0Init(baudrate); //inicializamos la uart a utilizar
	uart0Send( (uint8_t *)"AT+NAMEbaymaxINFO2023", (uint32_t)0);

	//TIMERS
	timerDisparoADC.Start(200,200, disparoADC); //CADA 0.2 SEG LEE
	timerLecturaADC.Start(200, 200, leerData); //CADA 0.2 SEG LO ANALIZA Y MANDA A UN BUFFER TEMPORAL
	timerUART0.Start(3000,3000, enviarTrama); //CADA 3 SEG ENVIA
	timerLecturaMAX.Start(1,1,demorai2c);

	//SETEO DE LEDS APAGADOS
	ledG.Set(leds);
	ledB.Set(leds);
	ledR.Set(leds);

}

void demorai2c (void)
{
	leerMAX30102=1;
	if( demora_i2c )
			demora_i2c --;
}

void imprimirLCD(void)
{
	switch (trama)
	{
		case ALERTA:
			miLcd.clear();
			miLcd.row(0).pos(5) << "ALERTA";
			break;
		case OK:
			miLcd.clear();
			miLcd.row(0) << (const char*)Buffer_linea_1;
			miLcd.row(1) << (const char*)Buffer_linea_2;
			break;
		case DESCONECTADO:
			miLcd.clear();
			miLcd.row(0).pos(2) << "DESCONECTADO";
			break;
	}
}





