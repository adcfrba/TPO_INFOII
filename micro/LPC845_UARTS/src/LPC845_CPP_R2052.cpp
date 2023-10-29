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

//TIMERSW Timer1;

//TIMERSW Timer2;

int main(void) {

	uart0Init(9600); //inicializamos la uart a utilizar

	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1) {
    	//tecla = TECLADO_LEER(); //leemos desde el teclado
    	//puedo agregar un switch y dependiendo de la tecla, hago tal cosa

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
