#ifndef LCD_DRIVER_LCD_H_
#define LCD_DRIVER_LCD_H_

//MACROS PARA CONFIGURAR O PARA PONER DATOS
#define 	LCD16x2_CONTROL		1
#define 	LCD16x2_DATA		0
#define		CANT_DIGITOS_DEFAULT	2
#define		CANT_DIGITOS_LCD 		40

//PINES
#define		PIN_LCD16X2_RS		0,15
#define		PIN_LCD16X2_E		0,14
#define		PIN_LCD16X2_D7		0,13
#define		PIN_LCD16X2_D6		0,11
#define		PIN_LCD16X2_D5		0,10
#define		PIN_LCD16X2_D4		0,4

//COMANDOS SEGUN LA TABLA PARA EL 16X2
#define		CLEAR_LCD			0x01
#define 	RESETEAR_CURSOR		0x02
#define		APAGAR_LCD			0x08
#define		NUESTRO_LCD			0x06
#define		PREPARAR_TODO		0x0C

class LCD {
public:
	LCD(void);
	void clear(void);
	LCD& operator<<(const char *text);
	LCD& operator<<(uint8_t number);
	LCD& operator<<(char caracter);
	LCD& row(uint8_t __row);
	LCD& pos(uint8_t __pos);
	LCD& digits(uint8_t cantDigitos);
	static const char *uiToStr(uint32_t num, uint8_t cantDigitos = 0, uint8_t puntoDesplazado = 0);

private:
	Gpio pinRS;
	Gpio pinE;
	Gpio pinD7;
	Gpio pinD6;
	Gpio pinD5;
	Gpio pinD4;
	uint8_t _row{}, _pos{}, _cantDigitos{CANT_DIGITOS_DEFAULT};
	void LCD_delay(void);
	void LCD_Escribir(uint8_t data , uint8_t control);
	void LCD_Display(const char *text , uint8_t row = 0, uint8_t pos = 0);
	void LCD_Display(uint32_t number, uint8_t row , uint8_t pos = 0, uint8_t cantDigitos = 0);
	void LCD_Display(char character, uint8_t row , uint8_t pos);

};

#endif /* LCD_DRIVER_LCD_H_ */
