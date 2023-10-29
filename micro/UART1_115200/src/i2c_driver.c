// =========================================================================================
//  Modulo: i2c_driver.C
//  Proposito: Funciones de lectura y grabacion de memorias IIC
//  Fecha: 26-07-2011
//  Autor: Ing. Gustavo Fresno
//=========================================================================================

#ifdef __USE_CMSIS
#include "LPC845.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "tipos.h"
//#include <lpc17xx_gpio.h>
//#include <lpc17xx_pinsel.h>

#define NO_ACK  					0       /* lack of acknowledgment          */
#define ACK     					1       /* acknowledgment                  */
#define	TIEMPO_IIC					10000	// Tiempos entre grabacion
#define	TIEMPO_IIC_1				1000	// Tiempo para la lectura de un cambio de estado en el puerto

#define	SDA							0,19
#define	SCL							0,20

#define	TAMANIO_MEMORIA				(1024 * 8)

//-------------------------------------------
void IIC_Start(void)
{
	/*PINSEL_CFG_Type PinCfg;

	// Configuro los pines del micro con pullup
	PinCfg.Funcnum = PINSEL_FUNC_0;
	PinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;
	PinCfg.Pinmode = PINSEL_PINMODE_PULLUP;
	PinCfg.Pinnum = 19;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	PinCfg.Funcnum = PINSEL_FUNC_0;
	PinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;
	PinCfg.Pinmode = PINSEL_PINMODE_PULLUP;
	PinCfg.Pinnum = 20;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);
*/
	// Configuro los pines del micro como salida
	GPIO_Dir(SDA, 1);
	GPIO_Dir(SCL, 1);

	// Seteo los pines
	GPIO_Set(SDA, 1);
	GPIO_Set(SCL, 1);

	// Envio señales de Start
	Demora_FOR(TIEMPO_IIC);

	GPIO_Set(SDA, 0);

	Demora_FOR(TIEMPO_IIC);

	GPIO_Set(SCL, 0);
}
//--------------------------------------------------------------
void IIC_Stop(void)
{
	GPIO_Set(SDA, 0);
	GPIO_Set(SCL, 1);

	Demora_FOR(TIEMPO_IIC);

	GPIO_Set(SDA, 1);
}

//--------------------------------------------------------------
// Funcion donde se envia el clock y se realiza la lectura del pin SDA
//--------------------------------------------------------------
uint8_t IIC_Read_Clock(void)
{
	uint8_t Level;         	/* linea de SDA */
	
	Demora_FOR(TIEMPO_IIC_1);

	// Seteo el pin CLK
	GPIO_Set(SCL, 1);
	
	// Se configura como entrada, para realizar la lectura
	GPIO_Set(SDA, 0);

	Demora_FOR(TIEMPO_IIC_1);

	// Realizo la lectura del SDA
	Level = GPIO_Read(SDA);

	Demora_FOR(TIEMPO_IIC_1);

	// Se configura SDA como salida nuevamente
	GPIO_Dir(SDA, 1);

	GPIO_Set(SCL, 0);

	Demora_FOR(TIEMPO_IIC_1);

	return(Level);
}

//--------------------------------------------------------------
// Funcion donde se envia el clock
//--------------------------------------------------------------
void IIC_Clock(void)
{
	Demora_FOR(TIEMPO_IIC_1);

	GPIO_Set(SCL, 1);

	Demora_FOR(TIEMPO_IIC_1);

	GPIO_Set(SCL, 0);

	Demora_FOR(TIEMPO_IIC_1);
}

//--------------------------------------------------------------
// Funcion donde se envia un byte a la memoria
//--------------------------------------------------------------
uint8_t IIC_Write(uint8_t byte)
{
	uint8_t 	mask = 0x80;
	
	while(mask)
	{
		if (byte & mask)
			GPIO_Set(SDA, 1);
		else
			GPIO_Set(SDA, 0);

		IIC_Clock();
		mask >>= 1;
	}
	GPIO_Set(SDA, 1);
	return(IIC_Read_Clock());
}
//--------------------------------------------------------------
// Funcion donde se lee un byte de la memoria
//--------------------------------------------------------------
uint8_t IIC_Read(uint8_t acknowledgment)
{
	uint8_t mask = 0x80,byte = 0x00;
	
	while(mask)
	{
		if (IIC_Read_Clock())
			byte |= mask;
		mask >>= 1;
	}

	if(acknowledgment)
	{
		// Esto es para lectura consecutivas
		GPIO_Set(SDA, 0);
		IIC_Clock();
		GPIO_Set(SDA, 1);
	}
	else
	{
		GPIO_Set(SDA, 1);
		IIC_Clock();
	}
	return(byte);
}
//--------------------------------------------------------------
// Funcion para escribir una posicion de memoria
// Parametros:
//	Direccion: es una direccion de la memoria desde 0 a TAMANIO_MEMORIA
//	Memoria: es la direccion fisica de la memoria
// 	byte: dato a grabar en la memoria
//--------------------------------------------------------------
uint8_t IIC_Escribir(uint32_t Direccion, uint8_t Memoria, uint8_t byte)
{
	uint8_t 	status;
	
	status = 0;               /* falla por default */

	IIC_Start();
	if (!IIC_Write(Memoria))
	{
		if (!IIC_Write((unsigned char)(Direccion >> 8)))
		{
			if (!IIC_Write((unsigned char)(Direccion)))
			{
				if (!IIC_Write(byte))
					status = 1;          /* success */
			}
		}
	}
	IIC_Stop();

	return(status);
}
//--------------------------------------------------------------
// Funcion para leer una posicion de memoria
// Parametros:
//	Direccion: es una direccion de la memoria desde 0 a TAMANIO_MEMORIA
//	Memoria: es la direccion fisica de la memoria
// Devuelve: uchar dato leido
//--------------------------------------------------------------
uint8_t IIC_Leer(uint32_t Direccion, uint8_t Memoria)
{
	uint8_t	Dato_Leido = 0xff;
	
	IIC_Start();
	if (!IIC_Write(Memoria))
	{
		if (!IIC_Write((unsigned char)(Direccion >> 8)))
		{
			if (!IIC_Write((unsigned char)Direccion))
			{
				IIC_Start();
				if (!IIC_Write(Memoria | 0x01))
				{
					Dato_Leido = IIC_Read(NO_ACK);
				}
			}
		}
	}
	IIC_Stop();

	return(Dato_Leido);
}

//--------------------------------------------------------------
// Funcion para tener una demora
//--------------------------------------------------------------
void Demora_FOR(uint32_t demora)
{
	uint32_t	tiempo;

	for(tiempo = 0; tiempo < demora ; tiempo++);
  	for(tiempo = 0; tiempo < demora ; tiempo++);
}					

//--------------------------------------------------------------
// Funcion para borrar toda las memorias del log
//--------------------------------------------------------------
/* void Borrar_Memoria(void)
{
	unsigned long i;

	for( i = 0 ; i < TAMANIO_MEMORIA ; i++)
	{
		IIC_Escribir(i , EEPROM, 0 );
	}
}																					                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
*/
