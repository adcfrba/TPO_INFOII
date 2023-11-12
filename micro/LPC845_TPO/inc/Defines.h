
#ifndef DEFINES_H_
#define DEFINES_H_

#include "LPC845.h"
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include "GPIO.h"
#include "CALLBACK.h"
#include "SYSTICK.h"
#include "TIMERSW.h"
#include "GPIOF.h"
#include "teclado.h"
#include "ADC.h"
#include "uart0.h"
#include <math.h>

#define TEMPERATURA 1
#define GAS 0
#define RL 1000 //LA CAMBIAMOS EN EL MODULO
#define RO 520 //ANALIZAR
#define ALERTA 0
#define OK 1
#define TEMP_DELTA 10
#define GAS_DELTA 5
#define N 5
#include <stdint.h>


#endif /* DEFINES_H_ */
