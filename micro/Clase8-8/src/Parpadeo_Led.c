/*
#include 	"Defines.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define 	PIN_LED_VERDE	1,0
#define 	PIN_LED_AZUL	1,1
#define 	PIN_LED_ROJO	1,2

#define		PIN_TECLA_USR	0,4

int main(void)
{
	uint32_t i, cont = 0, flag = 0;

	// Encendemos modulos de GPIO
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20);

	// Inicializacion pin de salida
	GPIO_Dir(PIN_LED_AZUL, SALIDA);
	GPIO_Dir(PIN_LED_ROJO, SALIDA);

	GPIO_Dir(PIN_TECLA_USR, ENTRADA);

    while(1)
    {
    	// Loop
    	GPIO_Set(PIN_LED_AZUL, 0);
    	GPIO_Set(PIN_LED_ROJO, 1);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    	GPIO_Set(PIN_LED_AZUL, 1);
    	GPIO_Set(PIN_LED_ROJO, 0);

    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);
    	for(i = 0 ; i < 50000 ; i++);

    }
    return 0 ;
}
*/
