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

extern TIMERS Timers;

void Led(void);

SYSTICK Systick(1000);
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

int main(void) {

	Timers.Start(1000, 1000, Led);

	ledG.Set(1);
	ledB.Set(1);
	ledR.Set(1);

    while(1) {
    	Timers.Accion();
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
