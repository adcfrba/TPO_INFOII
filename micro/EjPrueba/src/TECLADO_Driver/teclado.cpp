/*
 * teclado.cpp
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */

#include "teclado.h"
extern std::vector<CALLBACK*> vCallBack;

teclado::teclado() {
	buffer.clear();
	contador = 0;
	codTeclaAnterior = NO_TECLA;

	vCallBack.push_back(this);
}

teclado::~teclado() {
	// TODO Auto-generated destructor stub
}
void teclado::antirebote()
{
	uint8_t codTeclaActual;

	//codTeclaActual = TECLADO_Read();

	if(codTeclaActual == NO_TECLA)
	{
		contador=0;
		codTeclaAnterior = NO_TECLA;
		return;
	}
	if(codTeclaActual == codTeclaAnterior)
	{
		contador++;
		if(contador >= CANT_ESTADOS_ESTABLES)
			buffer.push_back(codTeclaActual); //agrego la tecla leida
	}
	else
		contador=0;

	codTeclaAnterior = codTeclaActual;

}
void teclado::Callback(void)
{

}
uint8_t teclado::leer(void)
{
	if(buffer.empty())
	{
		uint8_t elemento = buffer.back();
		buffer.pop_back();
		return elemento; //devuelvo siempre el valor real presionado
	}
}

uint8_t teclado::TECLADO_Read(void)
{
	/*
	 * Columna1.Set(0); //escribimos
	 * Columna2.Set(1);
	 *
	 * if(0 == Fila1.Get())
	 * 	return COD_T1; //LEO
	 *
	 * if(0 == Fila2.Get())
	 * 	return COD_T2; //LEO Y DEVUELVO CODIGO
	 *
	 * Columna1.Set(1); //escribimos pero la otra combinacion de columna
	 * Columna2.Set(0);
	 *
	 * if(0 == Fila1.Get())
	 * 	return COD_T3;
	 *
	 * if(0 == Fila2.Get())
	 * 	return COD_T4;
	 */
}
