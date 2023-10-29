/*
 * TIMERSW.h
 *
 *  Created on: 22 ago. 2023
 *      Author: notebook
 */
#ifndef TIMERSW_DRIVER_TIMERSW_H_
#define TIMERSW_DRIVER_TIMERSW_H_

typedef struct { //pasamos a generar una estructura
	uint32_t tiempo;
	uint32_t fin;
	uint32_t tiempoRecarga;
	void (*func)(void);
}STRUCT_TIMERSW;

void TIMERS_Ini();
void accion(void);
void descontar(void);
void start(uint32_t nro, uint32_t tiempoTotal, uint32_t tiempoRec, void* func(void));


#endif /* TIMERSW_DRIVER_TIMERSW_H_ */
