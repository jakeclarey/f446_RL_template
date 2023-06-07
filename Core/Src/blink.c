#include "blink.h"

void doBlink(void) {
  GPIOA->ODR |= 1 << 5U;
  ms_delay(200);
  GPIOA->ODR &= ~1 << 5U;
  ms_delay(200);
}

void sysTick_init(void) {
  SysTick->CTRL = 0;          // disable SysTick while configuring
  SysTick->LOAD = 0x00FFFFFF; // load max value
  SysTick->VAL = 0; // clears current value register by writing anything to it
  SysTick->CTRL = 0x00000005; // enable SysTick
}

void ms_delay(int n) {
  SysTick->LOAD = ((n * 16000) - 1); // load ms value for 16Mhz clock
  SysTick->VAL = 0;                  // clear current value register
  while ((SysTick->CTRL & 0x00010000) == 0)
    ; // wait until COUNTFLAG is set
}
