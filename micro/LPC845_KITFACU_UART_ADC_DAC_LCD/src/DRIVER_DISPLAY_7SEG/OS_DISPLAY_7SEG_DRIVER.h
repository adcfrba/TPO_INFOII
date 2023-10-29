#ifndef OS_DISPLAY_7SEG_DRIVER_H_
#define OS_DISPLAY_7SEG_DRIVER_H_

#define		PIN_BCD_A		0,20
#define		PIN_BCD_B		0,23
#define		PIN_BCD_C		0,22
#define		PIN_BCD_D		0,21

#define		PIN_RST_7SEG	0,18
#define		PIN_CK_7SEG		0,19

#define		CANTIDAD_DIGITOS	6

void DISPLAY_7SEG_Inicializar(void);
void DISPLAY_7SEG_Barrido(void);
void DISPLAY_7SEG_Print(uint32_t Dato);

#endif /* OS_DISPLAY_7SEG_DRIVER_H_ */
