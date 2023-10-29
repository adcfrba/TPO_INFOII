//son los prototipos de las funciones necesarias
//evitamos el trabajo con punteros y posibles errores

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#define SALIDA		1
#define ENTRADA 	0

void GPIO_Set(uint32_t Puerto, uint32_t Pin, uint32_t Estado);
void GPIO_Dir(uint32_t Puerto, uint32_t Pin, uint32_t Direccion);
uint32_t GPIO_Read(uint32_t Puerto, uint32_t Pin);

#endif /* GPIO_GPIO_H_ */
