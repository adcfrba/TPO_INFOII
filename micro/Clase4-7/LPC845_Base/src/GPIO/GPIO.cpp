/*
 * GPIO.cpp
 *
 *  Created on: 4 jul. 2023
 *      Author: notebook
 */
#include "define.h"

ClaseGPIO::ClaseGPIO()
{
	//setear lo necesario

	SYSCON->SYSAHBCLKCTRL0 |= (1<<7); //Habilitamos la matriz que organiza todo
	SYSCON->SYSAHBCLKCTRL0 |= (1<<6) | (1<<20) | (1<<18); //GPIO0 GPIO1 y las interrupt
}

ClaseGPIO::ClaseGPIO(uint32_t _port, uint32_t _pin, uint32_t _direccion)
{
	SYSCON->SYSAHBCLKCTRL0 |= (1<<7); //Habilitamos la matriz que organiza todo
	SYSCON->SYSAHBCLKCTRL0 |= (1<<6) | (1<<20) | (1<<18); //GPIO0 GPIO1 y las interrupt

	port = _port;
	pin = _pin;
	direccion = _direccion;

	dir(direccion); //importante darle la direccion como salida
}


void ClaseGPIO::set(uint32_t status)
{
	if (status)
		GPIO->SET[port] = (1<<pin); //le ponemos un 1 para poder setear el pin del puerto indicado como un 1
	else
		GPIO->CLR[port] = (1<<pin);
}

void ClaseGPIO::dir(uint32_t status)
{
	if(status)
		GPIO->DIRSET[port] = (1<<pin);
	else
		GPIO->DIRCLR[port] = (1<<pin);
}

uint32_t ClaseGPIO::read(uint32_t port, uint32_t pin)
{
	if(GPIO->PIN[port] & (1<<pin)) //le damos un 1 en el pin del puerto indicado
		return 1;
	else
		return 0;
}
