/*
 * TIMERSW.cpp
 *
 *  Created on: 22 ago. 2023
 *      Author: notebook
 */
#include "Defines.h"

STRUCT_TIMERSW timers[CANTIDAD_TIMERS];

void TIMERS_Ini() //para cada timer del vector le doy los valores iniciales
{
	for(int i = 0; i < CANTIDAD_TIMERS; i++)
	{
		Timers[i].tiempo = 0;
		Timers[i].fin = 0;
		Timers[i].func = 0;
		Timers[i].tiempoRecarga = 0;
	}
}

void start(uint32_t nro, uint32_t tiempoTotal, uint32_t tiempoRec, void* func(void))
{
	if(nro >= CANTIDAD_TIMERS)
	{
		Timers[nro].tiempo = tiempoTotal;
		Timers[nro].fin = 0;
		Timers[nro].func = func;
		Timers[nro].tiempoRecarga = tiempoRec;
	}
}

void descontar(void)
{
	for(int i = 0; i < CANTIDAD_TIMERS; i++)
	{
		if(Timers[i].tiempo>0)
			Timers[i]--;
		if(Timers[i].tiempo==0)
		{
			Timers[i].fin = 1;
			Timers[i].tiempo = Timers[i].tiempoRecarga;
		}
	}
}

void accion(void)
{
	for(int i=0; i<CANTIDAD_TIMERS;i++)
	{
		if(0==Timers[i].fin) //espero a cada uno de los timers a que finalice
		{
			Timers[i].fin=0;
			Timers[i].func();
		}
	}

}

