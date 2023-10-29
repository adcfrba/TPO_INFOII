//************************************************************************************************
// Archivo:				OS_GPIO_DRIVER.c
//
// Descripcion:
//
// Realizado por:		Ing. Fresno Gustavo (13/09/11)
//
//************************************************************************************************

#include "Defines.h"

STRUCT_GPIO				Gpio;
//uint8_t 				Led_1_Intensidad;
//uint8_t 				Led_2_Intensidad;
//uint8_t 				Led_3_Intensidad;

void GPIO_Inicializacion(void)
{
	uint32_t		i;

	SYSCON->SYSAHBCLKCTRL0 |= (1 << 7);					// 7 = SWM

	SYSCON->SYSAHBCLKCTRL0 |= (1 << 6) | (1 << 20) | (1 << 18);		// 6 = GPIO0	20 = GPIO1	18 = IOCON

	//IOCON->PIO[IOCON_INDEX_PIO1_0]

//	SWM0->PINENABLE0

//	SYSAHBCLKCTRL0
//
//	LPC_IOCON->PIO0_3 = 0;
	GPIO_Dir( PIN_AZUL, 1 );
	GPIO_Set( PIN_AZUL, 1 );

	GPIO_Dir( PIN_VERDE, 1 );
	GPIO_Set( PIN_VERDE, 1 );

	GPIO_Dir( PIN_ROJO, 1 );
	GPIO_Set( PIN_ROJO, 1 );


//	GPIO.Estados_Entradas_Digitales	= ESTADO_INICIAL_ENTRADAS;
//
//	for(i = 0 ; i < CANTIDAD_DE_ENTRADAS_DIGITALES ; i++)
//	{
//		 GPIO.Cantidad_Aceptar_Estado_N[i] = TIEMPO_ACTIVACION_ESTADO_NEGATIVO;
//		 GPIO.Cantidad_Aceptar_Estado_P[i] = TIEMPO_ACTIVACION_ESTADO_POSITIVO;
//	}
}

//void GPIO_Seteo_Salidas_Digitales(uint32_t Numero, uint32_t Estado)
//{
//	if(Estado)
//		GPIO.Estados_Salidas_Digitales |= (0x01 << Numero);
//	else
//		GPIO.Estados_Salidas_Digitales &= ~(0x01 << Numero);
//}
//
//uint8_t GPIO_Estado_Entradas_Digitales(void)
//{
//	return (uint8_t)GPIO.Estados_Entradas_Digitales;
//}
//
//void GPIO_Barrido_Salidas(void)
//{
//#ifdef SALIDA_0
//	GPIO_Value(SALIDA_0, (uint32_t)(GPIO.Estados_Salidas_Digitales & 0x01));
//#endif
//
//#ifdef SALIDA_1
//	GPIO_Value(SALIDA_1, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 1) & 0x01));
//#endif
//
//#ifdef SALIDA_2
//	GPIO_Value(SALIDA_2, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 2) & 0x01));
//#endif
//
//#ifdef SALIDA_3
//	GPIO_Value(SALIDA_3, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 3) & 0x01));
//#endif
//
//#ifdef SALIDA_4
//	GPIO_Value(SALIDA_4, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 4) & 0x01));
//#endif
//
//#ifdef SALIDA_5
//	GPIO_Value(SALIDA_5, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 5) & 0x01));
//#endif
//
//#ifdef SALIDA_6
//	GPIO_Value(SALIDA_6, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 6) & 0x01));
//#endif
//
//#ifdef SALIDA_7
//	GPIO_Value(SALIDA_7, (uint32_t)((GPIO.Estados_Salidas_Digitales >> 7) & 0x01));
//#endif
//}

/*********************************************************************************************/
/*                             Funcion de Debounce (antirebote de las entradas)		         */
/*********************************************************************************************/
//void GPIO_Barrido_Entradas(void)
//{
//	uint8_t 		Temporal, cambios;
//	uint8_t			Entrada_Actual;
//	uint32_t		j;
//
//	Entrada_Actual = 0;
//
//#ifdef ENTRADA_0
//	if(!GPIO_Read(ENTRADA_0))
//		Entrada_Actual |= 0x01;
//#endif
//
//#ifdef ENTRADA_1
//	if(GPIO_Read(ENTRADA_1))
//		Entrada_Actual |= 0x02;
//#endif
//
//#ifdef ENTRADA_2
//	if(GPIO_Read(ENTRADA_2))
//		Entrada_Actual |= 0x04;
//#endif
//
//#ifdef ENTRADA_3
//	if(GPIO_Read(ENTRADA_3))
//		Entrada_Actual |= 0x08;
//#endif
//
//#ifdef ENTRADA_4
//	if(GPIO_Read(ENTRADA_4))
//		Entrada_Actual |= 0x10;
//#endif
//
//#ifdef ENTRADA_5
//	if(GPIO_Read(ENTRADA_5))
//		Entrada_Actual |= 0x20;
//#endif
//
//#ifdef ENTRADA_6
//	if(GPIO_Read(ENTRADA_6))
//		Entrada_Actual |= 0x40;
//#endif
//
//#ifdef ENTRADA_CONTACTO
//	if(GPIO_Read(ENTRADA_CONTACTO) == 0)
//		Entrada_Actual |= 0x80;
//#endif
//
//	cambios = GPIO.Estados_Entradas_Digitales ^ Entrada_Actual;
//
//	if(cambios)
//	{
//		for(j = 0 ; j < CANTIDAD_DE_ENTRADAS_DIGITALES ; j++)
//		{
////			if(j == ENTRADA_Contador)
////				continue;
//			Temporal = (0x01 << j);
//
//			if(cambios & Temporal)
//			{
//				GPIO.ContadorEstados[j] ++;
//
//				if(GPIO.Estados_Entradas_Digitales & Temporal)
//				{
//					if(GPIO.ContadorEstados[j] >= GPIO.Cantidad_Aceptar_Estado_N[j])
//					{
//						GPIO.ContadorEstados[j] = 0;
//						if(Entrada_Actual & Temporal)
//							GPIO.Estados_Entradas_Digitales |= Temporal;
//						else
//							GPIO.Estados_Entradas_Digitales &= ~Temporal;
//					}
//				}
//				else
//				{
//					if(GPIO.ContadorEstados[j] >= GPIO.Cantidad_Aceptar_Estado_P[j])
//					{
//						GPIO.ContadorEstados[j] = 0;
//						if(Entrada_Actual & Temporal)
//							GPIO.Estados_Entradas_Digitales |= Temporal;
//						else
//							GPIO.Estados_Entradas_Digitales &= ~Temporal;
//					}
//				}
//
//			}
//			else
//			{
//				GPIO.ContadorEstados[j] = 0;
//			}
//		}
//	}
//	else
//	{
//		for(j = 0 ; j < CANTIDAD_DE_ENTRADAS_DIGITALES ; j++)
//		{
////			if(j == ENTRADA_Contador)
////				continue;
//
//			GPIO.ContadorEstados[j] = 0;
//		}
//	}
//}

// Funcion para la escritura de un puerto
void GPIO_Set(uint32_t Port, uint32_t Pin, uint32_t Valor)
{
	if(Valor)
		GPIO->SET[Port] |= 1<<Pin;
	else
		GPIO->CLR[Port] |= 1<<Pin;

}

// Funcion para configurar un puerto como entrada o salida
void GPIO_Dir(uint32_t Port, uint32_t Pin, uint32_t Valor)
{
	if(Valor)
		GPIO->DIRSET[Port] |= 1<<Pin;
	else
		GPIO->DIRCLR[Port] |= 1<<Pin;
}

// Funcion para la lectura de un puerto
uint32_t GPIO_Read(uint32_t Port, uint32_t Pin)
{
	uint32_t	Lectura;

	Lectura = GPIO->PIN[Port];

	Lectura = (Lectura >> Pin ) & 1 ;

	return Lectura;
}

int32_t IOCON_config_io(uint32_t Indice_PortPin, IOCON_config_t *pin_config)
{
	IOCON_PIO_reg_t *pio_reg;
	IOCON_PIO_reg_t pio_reg_to_write;

	// Mantengo configuraciones de DAC/IIC de haberlas
	pio_reg = (IOCON_PIO_reg_t *)&IOCON->PIO[Indice_PortPin];

	pio_reg_to_write = *pio_reg;

	if(pin_config->iic_mode > 0)
		pio_reg_to_write.I2CMODE = pin_config->iic_mode;

	if(pin_config->dac_mode > 0)
		pio_reg_to_write.DACMODE = pin_config->dac_mode;

	if(pin_config->mode != 0xff)
		pio_reg_to_write.MODE = pin_config->mode & 0x03;

	pio_reg_to_write.HYS = pin_config->hysteresis;
	pio_reg_to_write.INV = pin_config->invert_input;
	pio_reg_to_write.OD = pin_config->open_drain;
	pio_reg_to_write.S_MODE = pin_config->sample_mode;
	pio_reg_to_write.CLK_DIV = pin_config->clk_sel;

	*pio_reg = pio_reg_to_write;

	return IOCON_CONFIG_SUCCESS;
}


//uint32_t ENTRADA_Leer(uint32_t	Entrada)
//{
//	if(GPIO.Estados_Entradas_Digitales & Entrada)
//		return 1;
//	else
//		return 0;
//}

//uint32_t ENTRADA_Leer_Todas(void)
//{
//	return GPIO.Estados_Entradas_Digitales;
//}


//uint32_t CONTACTO_Get(void)
//{
//	if(GPIO.Estados_Entradas_Digitales & 0x80)
//		return 1;
//	else
//		return 0;
//}

//uint32_t Temporal_SPI;

//uint32_t ENTRADA_Analizar(void)
//{
//	uint32_t i, Cambio_Detectado = 0;
//	static uint32_t 	Estado_Anterior = 0;
//	static uint8_t 		Primer_Lectura = 0;
//
//	for(i = 0 ; i < CANTIDAD_DE_ENTRADAS_DIGITALES ; i++)
//	{
//		if((Estado_Anterior & (1 << i)) != (GPIO.Estados_Entradas_Digitales & (1 << i)))
//		{
//			// Hubo cambios en esta entrada (i)
//			if(i == 7)
//			{
//				if((GPIO.Estados_Entradas_Digitales & (1 << i)) == 0)
//				{
//					// 1 a 0
//					EVENTOS_Agregar(CONTACTO_OFF, 0);
//				}
//				else
//				{
//					// 0 a 1
//					EVENTOS_Agregar(CONTACTO_ON, 0);
//				}
//			}
//
//			Cambio_Detectado |= (1 << i);

//			LOG_GPIO_Analisis(i);
//		}
//	}

//	if((Cambio_Detectado & 0x3f) > 0 && Primer_Lectura == 1)
//	{
//		EVENTOS_Agregar(CAMBIO_ENTRADA_DIGITAL, Cambio_Detectado);
//	}
//
//	Primer_Lectura = 1;
//	Estado_Anterior = GPIO.Estados_Entradas_Digitales;
//
//	return Cambio_Detectado;
//}


