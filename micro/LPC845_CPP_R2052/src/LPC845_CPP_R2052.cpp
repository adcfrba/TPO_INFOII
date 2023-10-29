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

SYSTICK Systick(1000);
Gpio ledG(1, 0, 1);
Gpio ledB(1, 1, 1);
Gpio ledR(1, 2, 1);

TIMERSW TimerLed;

int main(void) {

	TimerLed.start(1000,1000,led);
    while(1) {

    }
    return 0 ;
}
