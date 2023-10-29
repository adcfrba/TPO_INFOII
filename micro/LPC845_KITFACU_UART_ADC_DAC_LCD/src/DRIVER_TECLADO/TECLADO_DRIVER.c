// =========================================================================================
//  Modulo: OS_TECLADO_driver.C
//  Proposito: Funciones de lectura de teclado
//  Fecha: 26-09-2011
//  Autor: Ing. Gustavo Fresno
//=========================================================================================

#include "Defines.h"

// Declaro las colas de datos de recepcion y transmision
uint8_t		CodigoTecla_Presionada = NO_KEY;

void TECLADO_Inicializacion(void)
{
	IOCON_config_t	Temporal;

	Temporal.open_drain = 0;
	Temporal.mode = PULL_UP;
	Temporal.clk_sel = IOCON_CLK_DIV_0;
	Temporal.iic_mode = 0;
	Temporal.dac_mode = 0;
	Temporal.sample_mode = 0;

	IOCON_config_io(IOCON_INDEX_PIO0_27, &Temporal);
	GPIO_Dir(TECLADO_FILA_1, 1);
	GPIO_Set(TECLADO_FILA_1, 0);

	IOCON_config_io(IOCON_INDEX_PIO0_29, &Temporal);
	GPIO_Dir(TECLADO_FILA_2, 1);
	GPIO_Set(TECLADO_FILA_2, 0);

	IOCON_config_io(IOCON_INDEX_PIO0_30, &Temporal);
	GPIO_Dir(TECLADO_COLUMNA_1, 0);
	GPIO_Set(TECLADO_COLUMNA_1, 0);

	IOCON_config_io(IOCON_INDEX_PIO0_31, &Temporal);
	GPIO_Dir(TECLADO_COLUMNA_2, 0);
	GPIO_Set(TECLADO_COLUMNA_2, 0);

	IOCON_config_io(IOCON_INDEX_PIO0_8, &Temporal);
	GPIO_Dir(TECLADO_COLUMNA_3, 0);
	GPIO_Set(TECLADO_COLUMNA_3, 0);
}

//==============================================================================================
//		-		Proposito: Analisis del hardware del teclado. Se cuelga de una interruocion de timer
//		-		Parametros:   void
//		-		Retorna: void
//==============================================================================================
void TECLADO_Barrido(void)
{
	uint8_t CodigoActual ;

	CodigoActual = TECLADO_Barrido_HW();						// Se Compromete con el HW
	TECLADO_Barrido_SW(CodigoActual);							//  No se compromete con el HW
}

//==============================================================================================
//		-		Proposito: Analiza el rebote del teclado
//		-		Parametros:
//		-				CodigoActual : Ultima lectura
//		-		Retorna: void
//==============================================================================================
uint8_t CodigoAnterior = NO_KEY;
uint16_t EstadosEstables = 0;
void TECLADO_Barrido_SW( uint8_t CodigoActual )
{
	if( CodigoActual == NO_KEY )								// No hay tecla presionada o hubo un rebote
	{
		CodigoAnterior = NO_KEY;

		EstadosEstables = 0;
		return;
	}

	if( EstadosEstables == 0  )										// Se detecto una tecla por primera vez
	{
		CodigoAnterior = CodigoActual;
		EstadosEstables = 1;
		return;
	}

	if( CodigoActual != CodigoAnterior )						// Pregunto si la tecla sigue pulsada
	{
		CodigoAnterior = NO_KEY;
		EstadosEstables = 0;
		return;
	}

	if( EstadosEstables == CANTIDAD_DE_REBOTES )
	{
		CodigoTecla_Presionada = (uint8_t)CodigoActual;

		EstadosEstables++;

		return;
	}

	if( EstadosEstables == CANTIDAD_DE_REBOTES_REP)
	{
		CodigoTecla_Presionada = (uint8_t)CodigoActual | 0x80;

		EstadosEstables++;

		return;
	}

	if( EstadosEstables >= CANTIDAD_DE_REBOTES_REP + 1)
	{
		return;
	}

	EstadosEstables ++;

	return;
}

//==============================================================================================
//		-		Proposito: Lectura de las entradas para ver el estado de las teclas
//		-		Parametros: void
//	Retorna
//		-		Codigo de tecla si hubo tecla
//		-		NO_KEY si no hubo tecla
//==============================================================================================
uint8_t TECLADO_Barrido_HW(void)
{
	// Funcion de barrido de teclado de 3x2
	// Barro fila 1
	GPIO_Set(TECLADO_FILA_1, 0);
	GPIO_Set(TECLADO_FILA_2, 1);

	if(!GPIO_Read(TECLADO_COLUMNA_1))
		return 0;
	if(!GPIO_Read(TECLADO_COLUMNA_2))
		return 1;
	if(!GPIO_Read(TECLADO_COLUMNA_3))
		return 2;

	// Barro fila 2
	GPIO_Set(TECLADO_FILA_1, 1);
	GPIO_Set(TECLADO_FILA_2, 0);

	if(!GPIO_Read(TECLADO_COLUMNA_1))
		return 3;
	if(!GPIO_Read(TECLADO_COLUMNA_2))
		return 4;
	if(!GPIO_Read(TECLADO_COLUMNA_3))
		return 5;

  	return NO_KEY;
}

uint8_t TECLADO_Read_1_key_driver(void)
{
	uint8_t 	Data = CodigoTecla_Presionada;

	CodigoTecla_Presionada = NO_KEY;

	return Data;
}
