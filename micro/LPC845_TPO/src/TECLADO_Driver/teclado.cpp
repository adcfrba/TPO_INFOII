/*
 * teclado.cpp
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */

#include "defines.h"
extern std::vector<CALLBACK*> vCallBack;

teclado::teclado(): Fila1(TECLADO_FILA_1, 0), Fila2(TECLADO_FILA_2, 0), Columna1(TECLADO_COLUMNA_1, 1), Columna2(TECLADO_COLUMNA_2, 1),Columna3(TECLADO_COLUMNA_3, 1)
{
	Fila1.Set(0);
	Fila2.Set(0);
	Columna1.Set(0);
	Columna2.Set(0);
	Columna3.Set(0);

	contador = 0;
	codTeclaAnterior = NO_TECLA;
	buffer.clear();
	vCallBack.push_back(this);
}

teclado::~teclado() {
	// TODO Auto-generated destructor stub
}
void teclado::antirebote()
{
	uint8_t codTeclaActual;

	codTeclaActual = TECLADO_Read();

	if(codTeclaActual == codTeclaAnterior)
	{
		contador++;
		if(contador >= CANTIDAD_DE_REBOTES)
			buffer.push_back(codTeclaActual); //agrego la tecla leida
	}
	else
		contador=0;

	codTeclaAnterior = codTeclaActual;
}

void teclado::Callback(void)
{
	antirebote();
}

uint8_t teclado::leer(void)
{
	if(buffer.empty()) //si no esta vacio
	{
		uint8_t elemento = buffer.back();
		buffer.pop_back();
		return elemento; //devuelvo siempre el valor real presionado
	}
	else
		return(NO_TECLA);
}

uint8_t teclado::TECLADO_Read(void) //BARRIDO 3X2
{
	//COLUMNA 1
	 Columna1.Set(0); //escribimos
	 Columna2.Set(1);
	 Columna3.Set(1);

	 if(0 == Fila1.Read())
		 return COD_T1; //LEO Y DEVUELVO CODIGO
	 if(0 == Fila2.Read())
		 return COD_T2;

	 //COLUMNA 2
	 Columna1.Set(1); //escribimos pero la otra combinacion de columna
	 Columna2.Set(0);
	 Columna3.Set(1);

	 if(0 == Fila1.Read())
	 	return COD_T3;
	 if(0 == Fila2.Read())
	  	return COD_T4;

	 //COLUMNA 3
	 Columna1.Set(1);
	 Columna2.Set(2);
	 Columna3.Set(3);

	 if(0 == Fila1.Read())
		 return COD_T5;
	 if(0 == Fila2.Read())
		 return COD_T6;

	 return NO_TECLA; //si no se apreto nada
}
