#ifndef BUTTON_C
#define BUTTON_C

#include "iom324pb.h"

extern void gpio_sw0_on_off() {
    DDRC |= 0x80;
    PORTC |= 0xC0;
    
    if (0 == PINC_PINC6)
      PORTC_PORTC7 = 0;
    else
      PORTC_PORTC7 = 1;
}

#endif