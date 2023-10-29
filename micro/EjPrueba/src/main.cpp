

#include <cr_section_macros.h>
#include "Defines.h"
#define APAGADO 0
#define ENCENDIDO 1
#define COMENZAR 3 //tecla comenzar de F3
#define LENTO_MIN 2 //cualquier tecla de F2
#define LENTO_MID 4 //cualquier tecla de F2
#define LENTO_MAX 5 //cualquier tecla de F2
#define MAX_POTENCIA 400
#define MID_POTENCIA 300
#define MIN_POTENCIA 100

SYSTICK systick(1000);
Gpio sensorTemp(1,0,1); //como entrada
Gpio calefactor(1,1,0); //como salida

Gpio teclaC0(0,0,1); //columnas son las salidas
Gpio teclaC1(0,1,1);
Gpio teclaC2(0,2,1);
Gpio teclaC3(0,3,1);
Gpio teclaC4(0,4,1);
Gpio teclaF0(0,5,0); //y las filas son las que funcionan como entrada
Gpio teclaF1(0,6,0);
Gpio teclaF2(0,7,0);
Gpio teclaF3(0,8,0);
Gpio teclaF4(0,9,0);

Gpio displayC0(0,10,0); //todos como salida
Gpio displayC1(0,11,0);
Gpio displayC2(0,12,0);
Gpio displayC3(0,13,0);
Gpio displayF0(0,14,0);
Gpio displayF1(0,15,0);
Gpio displayF2(0,16,0);
Gpio displayF3(0,17,0);
Gpio displayF4(0,18,0);
Gpio displayF5(0,19,0);
Gpio displayF6(0,20,0);

TIMERSW timerRapido;
TIMERSW timerTiempo;
uint8_t temperatura;
uint8_t flag = 0;
teclado tecla;

int main(void) {

	int8_t caracter;
	uint8_t estado;
	uint8_t potencia;
	uint8_t tiempo;

	uart0Init(9600); //inicializamos la uart a usar para mandar las tramas
	setupInicial();

    while(1) {
    	maqEstado();

    }
    return 0 ;
}

void setupInicial(void)
{
	estado = 0;
	potencia = 0;
	tiempo = 0;

	calefactor.Set(0);
	teclaC0.Set(0);
	teclaC1.Set(0);
	teclaC2.Set(0);
	teclaC3.Set(0);
	teclaC4.Set(0);
	displayC0.Set(0);
	displayC1.Set(0);
	displayC2.Set(0);
	displayC3.Set(0);
	displayF0.Set(0);
	displayF1.Set(0);
	displayF2.Set(0);
	displayF3.Set(0);
	displayF4.Set(0);
	displayF5.Set(0);
	displayF6.Set(0);
}

void maqEstado(void)
{
	estado = tecla.TECLADO_LEER(); //leo constantemente el teclado
	switch(estado)
	{
	case APAGADO:
		estadoApagado();
		break;
	case COMENZAR:
		estadoRapido();
		break;
	case LENTO:
		estadoLento();
		break;
	case ENCENDIDO:
		estadoEncendido();
		break;
	default:
		setupInicial();
		break;
	}
}


void estadoApagado(void)
{
	if(RAPIDO == tecla.TECLADO_LEER())
	{
		potencia = MAX_POTENCIA;
		tiempo += 30;
		estado = RAPIDO;
	}
	if(LENTO_MIN == tecla.TECLADO_LEER())
	{
		potencia = MIN_POTENCIA;
		tiempo = segundos();
		estado = LENTO;
	}
	if(LENTO_MID == tecla.TECLADO_LEER())
	{
		potencia = MID_POTENCIA;
		tiempo = segundos();
		estado = LENTO;
	}
	if(LENTO_MAX == tecla.TECLADO_LEER())
	{
		potencia = MAX_POTENCIA;
		tiempo = segundos();
		estado = LENTO;
	}
}

void estadoLento(void)
{
	if(COMENZAR == tecla.TECLADO_LEER())
	{
		estado = COMENZAR;
	}
	if(NUMEROS == tecla.TECLADO_LEER()) //PREGUNTAR
	{
		tiempo = lecturaNum();
		if (tiempo< 10 || tiempo>3600)
		{
			tiempo = 0;
			estado = APAGADO;
		}
		estado = COMENZAR;

	}
}

void estadoRapido(void)
{
	if(COMENZAR == tecla.TECLADO_LEER())
	{
		if((tiempo+30)<3600)
			tiempo += 30;

		estado = COMENZAR;
	}
	timerRapido(5000,5000,estadoEncendido()); //si no espero 5 seg y lo empiezo
}

void estadoEncendido(void)
{
	if(0 == flag)
	{
		flag = 1;
		calefactor.Set(1);
		timerTiempo.start(tiempo, tiempo, estadoEncendido());
	}
	else //VUELVE CUANDO TERMINA EL TIMER
	{
		flag = 0;
		calefactor.Set(0);
		estado = APAGADO;
	}
}

