#ifndef DEFINES_H_
#define DEFINES_H_

#include <cr_section_macros.h>

#include <LPC845.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <GPIO.h>
#include <CALLBACK.h>
#include <SYSTICK.h>
#include <TIMERSW.h>
#include <GPIOF.h>
#include <uart0.h>
#include <LCD.h>
#include <ADC.h>
#include <i2c.h>
#include <SpO2Calculator.h>
#include <max30102.h>

#define TEMPERATURA 1
#define GAS 0
#define RL 1000 //LA CAMBIAMOS EN EL MODULO
#define RO 6880 //ANALIZAR
#define ALERTA 0
#define OK 1
#define DESCONECTADO 2
#define GASMAX 3000
#define TEMPMAX 410
#define OXIMIN 90
#define OXI_DELTA 5
#define TEMP_DELTA 100
#define GAS_DELTA 500
#define N 3

#endif /* DEFINES_H_ */
