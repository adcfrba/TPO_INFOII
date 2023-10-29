#include 	"Define.h"

void GPIO_Set(uint32_t Puerto, uint32_t Pin, uint32_t Estado)
{
	if(Estado)
		GPIO->SET[Puerto] = (1 << Pin);
	else
		GPIO->CLR[Puerto] = (1 << Pin);
}

void GPIO_Dir(uint32_t Puerto, uint32_t Pin, uint32_t Direccion)
{
	if(Direccion)
		GPIO->DIRSET[Puerto] = (1 << Pin);
	else
		GPIO->DIRCLR[Puerto] = (1 << Pin);
}

uint32_t GPIO_Read(uint32_t Puerto, uint32_t Pin)
{
	if(GPIO->PIN[Puerto] & (1 << Pin))
	{
		// Entro por 1
		return 1;
	}
	else
	{
		// Entro por 0
		return 0;
	}
}

