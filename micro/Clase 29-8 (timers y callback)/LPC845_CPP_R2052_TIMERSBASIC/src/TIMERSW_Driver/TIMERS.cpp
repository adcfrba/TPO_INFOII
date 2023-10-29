/*
 * TIMERS.cpp
 *
 *  Created on: 29 ago. 2023
 *      Author: gusta
 */

#include <Defines.h>

TIMERS Timers;

void TIMERS::Start(uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void)){
	TIMERSW temp;
	temp.Start(tiempo, tiempoRecarga, func);
	vTimer.push_back(temp);
}

bool TIMERS::del(void (*func)(void)){

	std::vector<TIMERSW>::iterator it;

	for ( it= vTimer.begin(); it != vTimer.end(); ++it) {
		if((*it).func == func){
			vTimer.erase(it);
			return true;
		}
	}

	return false;
}

void TIMERS::Descontar(void){
    for (auto& timer : vTimer) {
    	timer.Descontar();
    }
}

void TIMERS::Accion(void){
    for (auto& timer : vTimer) {
    	timer.Accion();
    }

//	std::vector<TIMERSW>::iterator it;
//
//	for ( it= vTimer.begin(); it != vTimer.end(); ++it) {
//		(*it).Accion();
//	}
}

