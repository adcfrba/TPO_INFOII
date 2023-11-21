
#ifndef DEFINES_H_
#define DEFINES_H_

#include <cr_section_macros.h>

#include <vector>
//#include <string.h>
#include <stdio.h>
#include <math.h>
//#include <stdint.h>
//#include <algorithm>
//#include <functional>
#include "LPC845.h"
#include "tipos.h"
#include "GPIO.h"
#include "CALLBACK.h"
#include "SYSTICK.h"
#include "TIMERSW.h"
#include "GPIOF.h"
#include "teclado.h"
#include "ADC.h"
#include "uart0.h"
#include "timers.h"
#include "lcd.h"

#include "i2c.h"
#include "SpO2Calculator.h"
//#include "io.h"

#include "../MAX30102/max30102.h"





#define TEMPERATURA 1
#define GAS 0
#define RL 1000 //LA CAMBIAMOS EN EL MODULO
#define RO 550 //ANALIZAR
#define ALERTA 0
#define OK 1
#define DESCONECTADO 2
#define GASMAX 3000
#define TEMPMAX 450
#define OXIMIN 90
#define OXI_DELTA 5
#define TEMP_DELTA 10
#define GAS_DELTA 500
#define N 5


#endif /* DEFINES_H_ */
