#ifndef SOS_C
#define SOS_C

#include "led.h"
#include "gpio.h"

void point() {
  power_led_on(0);
  power_led_off(0);
  gpio_halfSec_delay();
}

void line() {
  power_led_on(0);
  gpio_oneSec_delay();
  power_led_off(0);
  gpio_halfSec_delay();
}

void morse_code() {
    point();
    point();
    point();
    line();
    line();
    line();
    point();
    point();
    point();
    gpio_oneSec_delay();
}

extern void morse_code_sw0_pressed() {
    
    DDRC |= 0x80;
    PORTC |= 0xC0;
    if (PINC_PINC6 == 0) {
      while(PINC_PINC6 != 0) {
        morse_code();
        gpio_oneSec_delay();
     }
    }
}
#endif