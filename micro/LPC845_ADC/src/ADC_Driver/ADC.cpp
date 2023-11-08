/*
 * ADC.cpp
 *
 *  Created on: 14 oct. 2023
 *      Author: notebook
 */

#include "Defines.h"

uint32_t	ADC_Cuentas[2]; //PORQUE TENEMOS DOS SENSORES

void ADC_Inicializar(uint8_t nADC)
{
	SYSCON->PDRUNCFG &= ~(1 << 4);	// Enciendo el modulo del ADC que esta apagado por default
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 24);	// 24 = ADC

	SWM0->PINENABLE0 &= ~(1 << (14 + nADC));	// ADC_0 enabled on pin PIO0_7 TEMPERATURA
	//SWM0->PINENABLE0 &= ~(1 << 15);	// ADC_1 enabled on pin PIO0_6 GAS

	ADC0->CTRL 	= (1)		// CLKDIV minimo si no hay una necesidad de velocidad
			| (0 << 8)		// ASYNCMODE
			| (0 << 10)		// LPWRMODE
			| (0 << 30);		// CALMODE

	// A/D Conversion Sequence A Control Register

	ADC0->SEQ_CTRL[0] 	= (0)		// CANAL, seleccionar al momento de disparar la conversion
			| (0 << 12)		// TRIGGER
			| (1 << 18)		// TRIGPOL								0=FLANCO NEGATIVO DE LOS TRIGGERS 1=FLANCO POSITIVO DE LOS TRIGGERS
			| (0 << 19)		// SYNCBYPASS
			| (0 << 26)		// START OF CONVERSION	1=SOC 0=STOP
			| (0 << 29)		// SINGLESTEP
			| (0 << 30)		// MODE
			| (1 << 31);		// SEQA_ENA	0=SECUENCIA A DESHABILITADA 1=HABILITADA

	ADC0->INTEN = (1 << 0);		// Sequence A interrupt enable

	NVIC->ISER[0] = (1 << 16); 		//Enable interrupt ISE_ADC_SEQA

}

void ADC_Disparo(uint8_t Canal)
{
	ADC0->SEQ_CTRL[0] 	&= ~(0xfff);			// Limpio los bits de seleccion del canal
	ADC0->SEQ_CTRL[0] 	|= (1 << Canal)			// Seleccion del canal
						| (1 << 26);			// START OF CONVERSION		1=SOC 0=STOP
}

void ADC_SEQA_IRQHandler(void)
{

	uint32_t	Temporal = ADC0->SEQ_GDAT[0];
	uint32_t 	Canal = (Temporal >> 26) & 0x0f;
	uint32_t	Valor_Temporal;
	uint32_t	lectura;
	uint32_t	voltaje;
	uint32_t	temp;
	//uint32_t	RS;

//	Temporal = Temporal >> 4;
//	Temporal &= 0xfff;
	switch(Canal)
	{
	case GAS:
		//Valor_Temporal = (Temporal >> 4) & 0xfff;
		//Valor_Temporal = (Valor_Temporal * 3300) / 4096; //VOLTAJE en mV
		//RS = ((3300-Valor_Temporal)/Valor_Temporal)*RL; //usamos la ecuacion calculada 124
		//Valor_Temporal = 125*pow(RS, -1,607); //REVISAR ESTO, NO DA ENTERO
		break;
	case TEMPERATURA:
		lectura = (Temporal >> 4) & 0xfff;
		voltaje = (lectura *5000) / 4096;
		temp = (voltaje *1000) / 50;//LM35 10mV=1C
		break;
	default:
		return;
	}

	ADC_Cuentas[Canal] = lectura;
}
