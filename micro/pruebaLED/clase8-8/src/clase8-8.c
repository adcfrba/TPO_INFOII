
#include 	"Defines.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#define 	PIN_LED_VERDE	1,0
#define		PIN_TECLA_USR	0,4

int main(void)
{
	uint32_t cont = 0, flag = 0;

	// Encendemos modulos de GPIO
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20);

	// Inicializacion pin de salida
	GPIO_Dir(PIN_LED_VERDE, SALIDA);
	GPIO_Dir(PIN_TECLA_USR, ENTRADA);
	GPIO_Set(PIN_LED_VERDE,1);


    while(1)
    {
    	if(GPIO_Read(PIN_TECLA_USR) == 0)
    	{
    		// TECLA PRESIONADA
    		if(flag == 0)
    		{
    			flag = 1;
				cont++;

				//printf("Cont=%d", cont);
    		}
    	}
    	else
    		flag = 0;

    }
    return 0 ;
}
