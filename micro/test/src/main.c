/*
===============================================================================
 Name        : ServoSG90.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <misc.h>
#include <lcd.h>

#define PRIMERA_FILA 0x00
uint8_t flag = 0;

int main(void)
{

	//uint8_t estado = 0, i, data;
	//uint32_t add = 0;
		Inicializar();
		LCD_Inicializar();

	    uint8_t Oxigeno_y_TEMP[15] = "SpO2:97% T:36C";
	    uint8_t Monoxido_de_carbono[12]="CO2:600ppm ";
	    uint8_t msg[11]="P_M";



	    //LCD_Display((uint8_t*)"HOLA", 1 , 0);
	    LCD_Display(Monoxido_de_carbono, 0 , 0);

    while(1)
    {
    	if(flag == 5)
    	{
    		GPIO_Set(PIN_ROJO, 1);
    	}
    	if(flag<5)
    	{
    		GPIO_Set(PIN_ROJO, 0);
    		flag++;
    	}

    	LCD_Display(msg, 1 , 0x06);



    }

    return 0 ;
}

