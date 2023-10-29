/*
 * TIMERSW.cpp
 *
 *  Created on: 22 ago. 2023
 *      Author: gusta
 */

#include "Defines.h"

extern SYSTICK Systick;

TIMERSW::TIMERSW(const TIMERSW& other) {
    tiempo = other.tiempo;
    fin = other.fin;
    tiempoRecarga = other.tiempoRecarga;
    func = other.func;
}

TIMERSW::TIMERSW() {
	this->tiempo = 0;
	this->tiempoRecarga = 0;
	this->fin = 0;
	this->func = nullptr;
}

void TIMERSW::Start(uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void)){
	this->tiempo = tiempo;
	this->tiempoRecarga = tiempoRecarga;
	this->fin = 0;
	this->func = func;
}

void TIMERSW::Descontar(void){
	if(tiempo > 0){
		tiempo--;
		if(0 == tiempo){
			fin = 1;
			tiempo = tiempoRecarga;
		}
	}
}

void TIMERSW::Accion(void){
	if(fin){
		fin = 0;
		func();
	}
}


