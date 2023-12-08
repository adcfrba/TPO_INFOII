/*
 * GPIOF.h
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */
#include "defines.h"
#ifndef GPIOF_DRIVER_GPIOF_H_
#define GPIOF_DRIVER_GPIOF_H_
#define CANT_ESTADOS_ESTABLES 6
#define CANT_ENTRADAS 8

class GPIOF : public Gpio, public CALLBACK{
private:
	uint8_t contador;
	uint8_t estAnterior;
	uint8_t estFiltrado;
	void Antirebote(void);
public:
	GPIOF();
	GPIOF(uint32_t _port,uint32_t _pin, uint32_t _direccion);
	virtual ~GPIOF();
	void Callback(void); //lo tenemos que declarar tambien aca, aunque lo heredamos de la clase
	uint32_t Read(void);
};

#endif /* GPIOF_DRIVER_GPIOF_H_ */
