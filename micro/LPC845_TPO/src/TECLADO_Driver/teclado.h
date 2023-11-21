/*
 * teclado.h
 *
 *  Created on: 5 sep. 2023
 *      Author: notebook
 */

#ifndef TECLADO_DRIVER_TECLADO_H_
#define TECLADO_DRIVER_TECLADO_H_

#define NO_TECLA 0xff
#define	CANTIDAD_DE_REBOTES		10

// Definicion de los pines del teclado 2X3
#define	TECLADO_FILA_1		0,27
#define	TECLADO_FILA_2		0,29 //FILAS LEO

#define	TECLADO_COLUMNA_1	0,30 //COLUMNAS SETEO
#define	TECLADO_COLUMNA_2	0,31
#define	TECLADO_COLUMNA_3	0,8

#define COD_T1 1
#define COD_T2 2
#define COD_T3 3
#define COD_T4 4
#define COD_T5 5
#define COD_T6 6

class teclado : public Gpio,public CALLBACK{
private:
	uint8_t contador;
	uint8_t codTeclaAnterior;
	std::vector<uint8_t>buffer;
	void antirebote(void);
	Gpio Fila1; //LEO
	Gpio Fila2;
	Gpio Columna1; //SETEO
	Gpio Columna2;
	Gpio Columna3;

public:
	teclado();
	virtual ~teclado();
	void Callback(void); //lo tenemos que declarar tambien aca, aunque lo heredamos de la clas
	uint8_t leer(void);
	uint8_t TECLADO_Read(void);
};

#endif /* TECLADO_DRIVER_TECLADO_H_ */
