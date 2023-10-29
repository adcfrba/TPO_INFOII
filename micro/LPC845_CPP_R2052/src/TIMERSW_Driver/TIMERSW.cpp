/*
 * TIMERSW.cpp
 *
 *  Created on: 22 ago. 2023
 *      Author: notebook
 */
#include "Defines.h"

TIMERSW::TIMERSW() {
	// TODO Auto-generated constructor stub

}

TIMERSW::~TIMERSW() {
	// TODO Auto-generated destructor stub
}

void TIMERSW::start(uint32_t tiempoTotal, uint32_t tiempoRec, void (*func)(void))
{
	this->tiempo = tiempoTotal;
	this->tiempoRecarga = tiempoRec;
	this->fin = 0;
	this->func = func;
}

void TIMERSW::descontar(void)
{
	if(tiempo>0)
		tiempo--;
	if(0 ==tiempo)
	{
		fin =1;
		tiempo = tiempoRecarga;
	}
}

void TIMERSW::accion(void)
{
	if(fin)
	{
		fin=0;
		func();
	}
}

