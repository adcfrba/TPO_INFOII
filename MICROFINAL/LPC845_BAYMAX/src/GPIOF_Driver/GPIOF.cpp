/*
 * GPIOF.cpp
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */

#include "GPIOF.h"
extern std::vector<CALLBACK*> vCallBack;

GPIOF::GPIOF(uint32_t _port,uint32_t _pin, uint32_t _direccion) : Gpio(_port, _pin, _direccion) //se inicializa el obj de gpio y luego va a la funcion
{
	contador = 0;
	estAnterior = 0;
	estFiltrado = 0;

	vCallBack.push_back(this);
}

/*
GPIOF::GPIOF() {
	contador = 0;
	estAnterior = 0;
	estFiltrado = 0;
}
*/
void GPIOF::Callback(void)
{
	Antirebote();
}
uint32_t GPIOF::Read(void)
{
	return(estFiltrado);
}

GPIOF::~GPIOF() {
	// TODO Auto-generated destructor stub
}
void GPIOF::Antirebote(void)
{
	uint8_t estActual;

	estActual = Gpio::Read(); //importante que sea la funcion original

	if(estActual == estAnterior)
	{
		contador++; //vamos subiendo el contador
		if(contador >= CANT_ESTADOS_ESTABLES)
			estFiltrado = estActual; //asigno el estado "real" despues de verificarlo
	}
	else
		contador = 0; //empezamos desde el principio

	estAnterior = estActual;
}


