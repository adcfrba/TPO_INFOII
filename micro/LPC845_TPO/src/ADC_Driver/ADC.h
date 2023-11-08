/*
 * ADC.h
 *
 *  Created on: 14 oct. 2023
 *      Author: notebook
 */

#ifndef ADC_DRIVER_ADC_H_
#define ADC_DRIVER_ADC_H_

void ADC_Inicializar(void); //toda la configuración necesaria
void ADC_Disparo(uint8_t Canal); //se elige un canal y se pone en 1 para que empiece

extern "C" {
	void ADC_SEQA_IRQHandler(void);
}
#endif /* ADC_DRIVER_ADC_H_ */
