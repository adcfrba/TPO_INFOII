/*
 * TIMERSW.h
 *
 *  Created on: 22 ago. 2023
 *      Author: notebook
 */
#ifndef TIMERSW_DRIVER_TIMERSW_H_
#define TIMERSW_DRIVER_TIMERSW_H_

class TIMERSW {

public:
	TIMERSW();
	virtual ~TIMERSW();

	uint32_t tiempo;//atributos pub para evitar los set y get
	uint32_t fin;
	uint32_t tiempoRecarga;
	void (*func)(void);

	void start(uint32_t, uint32_t, void*());
	void descontar(void);
	void accion(void);
};

#endif /* TIMERSW_DRIVER_TIMERSW_H_ */
