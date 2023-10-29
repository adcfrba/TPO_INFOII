
#include "define.h"

ClaseGPIO ledGreen(1,0,1); //global
ClaseGPIO ledBlue(1,1,1);
ClaseGPIO ledRed(1,2,1);

int main(void)
{
    while(1)
    {
    	ledBlue.set(0);
    	ledGreen.set(1); //le seteamos un 1 y un 0 en el port y pin
    	ledRed.set(1);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);

    	ledBlue.set(1);
    	ledGreen.set(0); //le seteamos un 1 y un 0 en el port y pin
    	ledRed.set(1);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);

    	ledBlue.set(1);
    	ledGreen.set(1); //le seteamos un 1 y un 0 en el port y pin
    	ledRed.set(0);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);
    	for(int i = 0; i<10000;i++);

    }
    return 0 ;
}
