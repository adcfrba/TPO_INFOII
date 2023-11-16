/*
 * lcd.h
 *
 *  Created on: 31 oct. 2023
 *      Author: notebook
 */
#include "Defines.h"
#ifndef LCD_DRIVER_LCD_H_
#define LCD_DRIVER_LCD_H_

class lcd {
public:
	void escribir(uint8_t control,uint8_t comando);
	void inicializar(void);
	void escribirTexto(uint8_t *);
	void escribirTextoEspecifico(uint8_t *, uint8_t, uint8_t);
};

#endif /* LCD_DRIVER_LCD_H_ */
