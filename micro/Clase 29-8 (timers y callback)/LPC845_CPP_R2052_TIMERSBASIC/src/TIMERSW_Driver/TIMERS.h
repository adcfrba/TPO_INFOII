/*
 * TIMERS.h
 *
 *  Created on: 29 ago. 2023
 *      Author: gusta
 */

#ifndef TIMERSW_DRIVER_TIMERS_H_
#define TIMERSW_DRIVER_TIMERS_H_

class TIMERS {
private:
	std::vector<TIMERSW> vTimer;
public:
	void Start(uint32_t tiempo, uint32_t tiempoRecarga, void (*func)(void));
	bool del(void (*func)(void));
	void Descontar(void);
	void Accion(void);
};

#endif /* TIMERSW_DRIVER_TIMERS_H_ */
