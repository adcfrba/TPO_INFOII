
#ifndef I2c_Driver_
#define I2c_Driver_

#define NO_ACK  					0       /* lack of acknowledgment          */
#define ACK  						1

#define	TIEMPO_IIC					30	// Tiempos entre grabacion
#define	TIEMPO_IIC_1				20		// Tiempo para la lectura de un cambio de estado en el puerto

#define	CANTIDAD_REINTENTOS_I2C		5

#define	SDA							0,19		//Pin 4 stick
#define	SCL							0,18	//Pin 3 stick

#define	TAMANIO_MEMORIA				(1024 * 8)

void IIC_Start(void);
void IIC_Stop(void);
uint8_t IIC_Read_Clock(void);
void IIC_Clock(void);
uint8_t IIC_Write(uint8_t );
uint8_t IIC_Read(uint8_t );
uint8_t IIC_Escribir(uint32_t , uint8_t , uint8_t );
uint8_t IIC_Leer(uint32_t , uint8_t );
void IIC_Demora(uint32_t demora);
void Borrar_Memoria(uint8_t);
void IIC_Inicializacion(void);
uint8_t GetDemora_IIC( void );
void SetDemora_IIC( uint8_t value );



uint8_t IIC_Write_Driver(uint32_t Direccion, uint8_t Memoria, uint8_t byte);
uint8_t IIC_Read_Driver(uint32_t Direccion, uint8_t Memoria);

void IIC_Write_Driver_32b(uint32_t Direccion, uint8_t Memoria, uint32_t Dato);
uint32_t IIC_Read_Driver_32b(uint32_t Direccion, uint8_t Memoria);

uint16_t IIC_Read_Driver_16b(uint32_t Direccion, uint8_t Memoria);
void IIC_Write_Driver_16b(uint32_t Direccion, uint8_t Memoria, uint16_t Dato);

void IIC_Leer_Bloque(uint32_t Direccion, uint8_t* Datos, uint32_t Tamanio);
void IIC_Guardar_Bloque(uint32_t Direccion, uint8_t* Datos, uint32_t Tamanio);

#endif /* PROYECTO_LPC1768_H_ */
