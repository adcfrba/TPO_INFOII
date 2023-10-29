/*
 * TIMERSW.cpp
 *
 *  Created on: 22 ago. 2023
 *      Author: gusta
 */

#include "Defines.h"

STRUCT_TIMERSW Timers[CANTIDAD_TIMERS];

void TIMERSW_Inicializacion(){
	for(int i = 0 ; i < CANTIDAD_TIMERS ; i++){
		Timers[i].tiempo = 0;
		Timers[i].tiempoRecarga = 0;
		Timers[i].fin = 0;
		Timers[i].func = 0;
	}
}

void TIMERSW_Start(uint32_t nro, uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void)){
	if(nro >= CANTIDAD_TIMERS)
		return;

	Timers[nro].tiempo = tiempo;
	Timers[nro].tiempoRecarga = tiempoRecarga;
	Timers[nro].fin = 0;
	Timers[nro].func = func;
}

void TIMERSW_Descontar(void){
	for(int nro = 0 ; nro < CANTIDAD_TIMERS ; nro++){
		if(Timers[nro].tiempo > 0){
			Timers[nro].tiempo--;
			if(0 == Timers[nro].tiempo){
				Timers[nro].fin = 1;
				Timers[nro].tiempo = Timers[nro].tiempoRecarga;
			}
		}
	}
}

void TIMERSW_Accion(void){
	for(int nro = 0 ; nro < CANTIDAD_TIMERS ; nro++){
		if(1 == Timers[nro].fin){
			Timers[nro].fin = 0;
			Timers[nro].func();
		}
	}
}



