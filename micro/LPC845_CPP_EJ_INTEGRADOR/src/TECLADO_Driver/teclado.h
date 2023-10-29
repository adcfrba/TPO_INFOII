/*
 * teclado.h
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */

#ifndef TECLADO_DRIVER_TECLADO_H_
#define TECLADO_DRIVER_TECLADO_H_
#define NO_TECLA 255
#include "defines.h"

class teclado : public CALLBACK{
private:
	uint8_t contador;
	uint8_t codTeclaAnterior;
	std::vector<uint8_t>buffer;
public:
	teclado();
	virtual ~teclado();
	void antirebote(void);
	void Callback(void);
	uint8_t leer(void);
	uint8_t TECLADO_Read(void);
};

#endif /* TECLADO_DRIVER_TECLADO_H_ */
