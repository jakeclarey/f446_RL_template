#include <stdio.h>
#include <stm32f446xx.h>

void sysTick_init(void);
void ms_delay(int n);

int main(void) {
  sysTick_init();
  RCC->AHB1ENR |= 1;
  GPIOA->MODER &= ~3 << (2 * 5U);
  GPIOA->MODER |= 1 << (2 * 5U);
  while (1) {
    GPIOA->ODR |= 1 << 5U;
    ms_delay(500);
    GPIOA->ODR &= ~1 << 5U;
    ms_delay(500);
  } // end of while (1)
} // end of main(void)

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
