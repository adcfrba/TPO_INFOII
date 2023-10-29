#ifndef DRIVER_TIMER_TIMER_DRIVER_H_
#define DRIVER_TIMER_TIMER_DRIVER_H_

#define FREQ_PRINCIPAL					(24000000UL)
#define FREQ_SYSTICK					(1000)

#define CANTIDAD_TIEMPO_SYSTICK_1SEG	(1000)
#define MAX_TICKS 						0xffffff

void PLL_Init(void);
uint32_t SysTick_Inic( uint32_t ticks );

#endif /* DRIVER_TIMER_TIMER_DRIVER_H_ */

