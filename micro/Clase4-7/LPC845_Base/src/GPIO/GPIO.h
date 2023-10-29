/*
 * GPIO.h
 *
 *  Created on: 4 jul. 2023
 *      Author: notebook
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

class ClaseGPIO
{
private:
	uint8_t port, pin, direccion;

public:
	ClaseGPIO();
	ClaseGPIO(uint32_t port, uint32_t pin, uint32_t direccion);
	void set(uint32_t status);
	void dir(uint32_t status);
	uint32_t read(uint32_t port, uint32_t pin);
};

#endif /* GPIO_GPIO_H_ */
