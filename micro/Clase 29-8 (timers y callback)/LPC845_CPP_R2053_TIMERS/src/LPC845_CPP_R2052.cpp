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

	//Timer1.Start(1000, 1000, Led);

	//Timer2.Start(2000, 2000, Print);

	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1) {
    	if(0==Pulsador.Read())//pullup->cuando lo pulsamos vemos 0
    		ledB.Set(0);
    	else
    		ledB.Set(1);
    }
    return 0 ;
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
