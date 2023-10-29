/*
 * TIMERSW.h
 *
 *  Created on: 22 ago. 2023
 *      Author: gusta
 */

#ifndef TIMERSW_DRIVER_TIMERSW_H_
#define TIMERSW_DRIVER_TIMERSW_H_

#define CANTIDAD_TIMERS 20

void TIMERSW_Inicializacion();
void TIMERSW_Start(uint32_t nro, uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void));
void TIMERSW_Descontar(void);
void TIMERSW_Accion(void);

typedef struct  {
	uint32_t tiempo;
	uint8_t fin;
	uint32_t tiempoRecarga;
	void (*func)(void);
}STRUCT_TIMERSW;

#endif /* TIMERSW_DRIVER_TIMERSW_H_ */
