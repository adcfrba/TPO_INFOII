/*
 * GPIO.h
 *
 *  Created on: Jul 13, 2021
 *      Author: Gustavo
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

// Aca declaramos los pines
#define 	PIN_LED_VERDE	1,0
#define 	PIN_LED_AZUL	1,1
#define 	PIN_LED_ROJO	1,2

#define		PIN_TECLA_USR	0,4

// Defines
#define 	SALIDA		1
#define 	ENTRADA 	0

void GPIO_Set(uint32_t Puerto, uint32_t Pin, uint32_t Estado);
void GPIO_Dir(uint32_t Puerto, uint32_t Pin, uint32_t Direccion);
uint32_t GPIO_Read(uint32_t Puerto, uint32_t Pin);

#endif /* GPIO_GPIO_H_ */
