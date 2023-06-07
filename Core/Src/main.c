#include "blink.h"
#include <stdio.h>
#include <stm32f446xx.h>

int main(void) {
  sysTick_init();
  RCC->AHB1ENR |= 1;
  GPIOA->MODER &= ~3 << (2 * 5U);
  GPIOA->MODER |= 1 << (2 * 5U);
  while (1) {
    doBlink();
  } // end of while (1)
} // end of main(void)
