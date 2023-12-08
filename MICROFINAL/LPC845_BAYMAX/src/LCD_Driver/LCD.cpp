#include "Defines.h"

LCD::LCD(void) :pinRS(PIN_LCD16X2_RS,1),pinE(PIN_LCD16X2_E,1),pinD7(PIN_LCD16X2_D7,1),pinD6(PIN_LCD16X2_D6,1),pinD5(PIN_LCD16X2_D5,1),pinD4(PIN_LCD16X2_D4,1)
{
	uint32_t i, j;
	IOCON_config_t	Temporal;

	Temporal.open_drain = 1;
	Temporal.mode = PULL_NONE;
	Temporal.clk_sel = IOCON_CLK_DIV_0;
	Temporal.iic_mode = IIC_MODE_STANDARD;
	Temporal.dac_mode = 0;
	Temporal.sample_mode = SAMPLE_MODE_BYPASS;


	pinRS.IOCON_config_io(IOCON_INDEX_PIO0_15, &Temporal);
	pinRS.Set(0);
	pinE.IOCON_config_io(IOCON_INDEX_PIO0_14, &Temporal);
	pinE.Set(0);
	pinD7.IOCON_config_io(IOCON_INDEX_PIO0_13, &Temporal);
	pinD7.Set(0);
	pinD6.IOCON_config_io(IOCON_INDEX_PIO0_11, &Temporal);
	pinD6.Set(0);
	pinD5.IOCON_config_io(IOCON_INDEX_PIO0_10, &Temporal);
	pinD5.Set(0);
	pinD4.IOCON_config_io(IOCON_INDEX_PIO0_4, &Temporal);
	pinD4.Set(0);

	for( i = 0 ; i < 3 ; i++ )
		{
			pinE.Set(0);;
			LCD_delay();
			pinD7.Set(0);
			pinD6.Set(0);
			pinD5.Set(1);
			pinD4.Set(1);
			pinRS.Set(0);
			pinE.Set(1);

			for( j = 0 ; j < 10000 ; j++ );//4500
			pinE.Set(0);;
		}
		pinE.Set(0);
		LCD_delay();
		pinD7.Set(0);
		pinD6.Set(0);
		pinD5.Set(1);
		pinD4.Set(0);
		pinRS.Set(0);
		pinE.Set(1);

		for( j = 0 ; j < 10000 ; j++ );//4500
		pinE.Set(0);;

		// A partir de aca pasa a 4 bits
		LCD_Escribir( 0x28 , LCD16x2_CONTROL);
		LCD_Escribir( APAGAR_LCD , LCD16x2_CONTROL);
		LCD_Escribir( CLEAR_LCD , LCD16x2_CONTROL);
		LCD_Escribir( NUESTRO_LCD , LCD16x2_CONTROL);
		LCD_Escribir( PREPARAR_TODO , LCD16x2_CONTROL);

}

void LCD::LCD_Display(const char *text , uint8_t row , uint8_t pos )
{
	unsigned char i ;

	if( row )
        pos = pos + 0xc0 ;
	else
		pos = pos + 0x80 ;

	LCD_Escribir( pos , LCD16x2_CONTROL );
	for( i = 0 ; text[ i ] != '\0' ; i++ )
		LCD_Escribir((uint8_t)(text[ i ]) , LCD16x2_DATA );
}

void LCD::clear(void)
{
	LCD_Escribir(CLEAR_LCD, LCD16x2_CONTROL);
	_row = 0;
	_pos = 0;
}

void LCD::LCD_Display(char character, uint8_t row , uint8_t pos)
{
	if( row )
        pos = pos + 0xc0 ;
	else
		pos = pos + 0x80 ;
	LCD_Escribir( pos , LCD16x2_CONTROL );
	LCD_Escribir( character , LCD16x2_DATA );
}

void LCD::LCD_Display(uint32_t num, uint8_t row , uint8_t pos, uint8_t cantDigitos)
{
	uint32_t i = 1, c;

	if(cantDigitos == 0){
		while(num > i){
			i*=10;
			cantDigitos++;
		}
	}
	else
	{
		for(uint8_t j = 0 ; j < cantDigitos ; j++)
			i *= 10;
	}
	if(num >= i) num = i-1;
	i /= 10;
	char cadena[cantDigitos+1];

	for(uint8_t j = 0; j < cantDigitos ; j++){
		c = num / i;
		cadena[j] = '0'+(char)c;
		num -= c * i;
		i /= 10;
	}
	cadena[cantDigitos] = '\0';
	LCD_Display(cadena, row , pos );
}

void LCD::LCD_Escribir(uint8_t data , uint8_t control)
{
	int32_t q , i = 1;

	do
	{
		pinD7.Set((data >> ( 3 + i * 4 ) ) & 0x01);
		pinD6.Set((data >> ( 2 + i * 4 ) ) & 0x01);
		pinD5.Set((data >> ( 1 + i * 4 ) ) & 0x01);
		pinD4.Set((data >> ( 0 + i * 4 ) ) & 0x01);

		if( control )
			pinRS.Set(0);
		else
			pinRS.Set(1);

		pinE.Set(1);

		for( q = 0 ; q < 400 ; q++ ){};

		pinE.Set(0);

		for( q = 0 ; q < 14000 ; q++ ){};
	}
	while ( i-- );
	if(control == LCD16x2_DATA)
		_pos++;
}

void LCD::LCD_delay( void )
{
  uint32_t 	i;
  for ( i = 0 ; i < 500000 ; i++ ); // 300000
}


LCD& LCD::operator<<(const char *text)
{
	LCD_Display(text , _row, _pos);
	return *this;
}


LCD& LCD::operator<<(uint8_t number)
{
	uint8_t digitos = 0;
	uint32_t i = 1;
	do{
		i *= 10;
		digitos++;
	}
	while( i < number);

	LCD_Display(number, _row, _pos, digitos);
	return *this;
}


LCD& LCD::operator<<(char caracter)
{
	LCD_Display(caracter, _row , _pos);
	return *this;
}

LCD& LCD::row(uint8_t __row)
{
	_row = __row == 0 ? 0 : 1;
	_pos = 0;
	return *this;
}

LCD& LCD::pos(uint8_t __pos)
{
	_pos = __pos < 40 ? __pos : 0;
	return *this;
}

LCD& LCD::digits(uint8_t cantDigitos)
{
	_cantDigitos = cantDigitos;
	return *this;
}

const char *LCD::uiToStr(uint32_t num, uint8_t cantDigitos, uint8_t puntoDesplazado)
{
	uint32_t i = 1, c;

	static char cadena[10];

	for(uint32_t j = 0 ; j < 6 ; j++)
		cadena[j] = 0;

	if(cantDigitos == 0){
		while(num > i){
			i*=10;
			cantDigitos++;
		}
	}
	else
	{
		for(uint8_t j = 0 ; j < cantDigitos ; j++)
			i *= 10;
		puntoDesplazado = puntoDesplazado < cantDigitos ? puntoDesplazado : cantDigitos-1;

	}
	if(num >= i) num = i-1;
	i /= 10;

	for(uint8_t j = 0; j < cantDigitos ; j++){
		c = num / i;
		if(j < cantDigitos - puntoDesplazado)
			cadena[j] = '0'+(char)c;
		else if(j == cantDigitos - puntoDesplazado)
		{
			cadena[j] = '.';
			cadena[j+1] = '0'+(char)c;
		}
		else
			cadena[j+1] = '0'+(char)c;
		num -= c * i;
		i /= 10;
	}
	if (puntoDesplazado != 0)
		cadena[cantDigitos+1] = '\0';
	else
		cadena[cantDigitos] = '\0';
	return cadena;
}

