/*
 * ADC.cpp
 *
 *  Created on: 14 oct. 2023
 *      Author: notebook
 */

#include "Defines.h"


uint32_t	ADC_Cuentas[2]; //PORQUE TENEMOS DOS SENSORES

#define IOCON0_6_BASE (0x40044040u)
#define IOCON0_6 *((uint32_t*)IOCON0_6_BASE)

void ADC_Inicializar()
{
	SYSCON->PDRUNCFG &= ~(1 << 4);	// Enciendo el modulo del ADC que esta apagado por default
	SYSCON->SYSAHBCLKCTRL0 |= (1 << 24);	// 24 = ADC

	SWM0->PINENABLE0 &= ~(1 << 14);	// ADC_0 enabled on pin PIO0_7 GAS
	SWM0->PINENABLE0 &= ~(1 << 15);	// ADC_1 enabled on pin PIO0_6 TEMPERATURA

	IOCON0_6 = 0;

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
	float	Valor_Temporal;
	float	RS;

//	Temporal = Temporal >> 4;
//	Temporal &= 0xfff;
	Valor_Temporal = (Temporal >> 4) & 0xfff;

	switch(Canal)
	{
	case GAS:
		Valor_Temporal = (Valor_Temporal * 3.3) / 4096; //VOLTAJE
		RS = ((3.3-Valor_Temporal)/Valor_Temporal)*RL; //usamos la ecuacion calculada 124
		Valor_Temporal = 125*pow(RS/RO, -1.607); //ppm
		Valor_Temporal = Valor_Temporal * 100; //para tener un digito y dos decimales
		break;
	case TEMPERATURA:

		Valor_Temporal = (Valor_Temporal *3300) / 4096; //LM35 10mV=1C lo mandamos en mili
		Valor_Temporal = Valor_Temporal - 40.0;
		break;
	default:
		return;
	}

	ADC_Cuentas[Canal] = (uint32_t)Valor_Temporal; //Devolvemos el valor multiplicado por mil para evitar los decimales
}
