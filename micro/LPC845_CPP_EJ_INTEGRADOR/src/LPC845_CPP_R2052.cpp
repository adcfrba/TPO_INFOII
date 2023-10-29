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

void Led(void);
void Print(void);

SYSTICK Systick(1000);
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

GPIOF Pulsador(0,4,0);

Gpio Motor1(,,);
Gpio Motor2(,,); //inicializo lso gpios que voy a usar para los motores
teclado Teclado1;


int main(void) {

	//Timer1.Start(1000, 1000, Led);

	//Timer2.Start(2000, 2000, Print);

	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1) {
    	//EJERCICIO DEL MOTOR CON EL TECLADO
    	Tecla = Teclado1.leer(); //leer el buffer
    	switch(Tecla)
    	{
    	case COD_TECLA_ARRIBA:
    		MOVER_ARRIBA();
    		break;
    		
    	case COD_TECLA_ABAJO:
    		MOVER_ABAJO();
    		break;
    		
    	default:
    		ENCENDER_MAQ();
    		break;
    	}

    }
}

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

void Print(void){
	static uint8_t status = 0;

	if(status){
		status = 0;
		ledG.Set(1);
	}else{
		status = 1;
		ledG.Set(0);
	}
}


void maqEstados(void)
{


}
