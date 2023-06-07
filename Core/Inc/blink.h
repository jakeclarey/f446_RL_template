#ifndef __BLINK__
#define __BLINK__

#include <stm32f446xx.h>

void doBlink(void);
void sysTick_init(void);
void ms_delay(int n);

#endif
