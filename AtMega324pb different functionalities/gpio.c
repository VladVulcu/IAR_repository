#ifndef GPIO_C 
#define GPIO_C

#include "gpio.h"

void gpio_halfSec_delay (void) {
  for(int i=0;i<50;i++){
    for(int j=0;j<10000;j++) {
    }
  }
}

void gpio_160ms_delay(void) {
  for(int i=0;i<16;i++){
    for(int j=0;j<10000;j++){
    }
  }
}

void gpio_twoSec_delay (void) {
  for(int k=0;k<200;k++) {
    for(int l=0;l<10000;l++) {
    }
  }
}

void gpio_oneSec_delay (void) {
  for(int m=0;m<100;m++) {
    for(int n=0;n<10000;n++) {
    }
  }
}

void gpio_set_pin(volatile unsigned char *PORT, int x) {
  *PORT |= (1 << x);
}

void gpio_reset_pin(volatile unsigned char *PORT, int x) {
  *PORT &= ~(1 << x);
}

void gpio_toggle_pin(volatile unsigned char *PORT, int x) {
  *PORT ^= (1 << x);
}

void set_pin_switch(int x) {
  switch(x) {
    case 0:
      DDRC |= 0x01;
      PORTC_PORTC0 = 1;
      break;
    case 1:
      DDRC |= 0x02;
      PORTC_PORTC1 = 1;
      break;
    case 2:
      DDRC |= 0x04;
      PORTC_PORTC2 = 1;
      break;
    case 3:
      DDRC |= 0x08;
      PORTC_PORTC3 = 1;
      break;
    case 4:
      DDRC |= 0x10;
      PORTC_PORTC4 = 1;
      break;
    case 5:
      DDRC |= 0x20;
      PORTC_PORTC5 = 1;
      break;
    case 6:
      DDRC |= 0x40;
      PORTC_PORTC6 = 1;
      break;
    case 7:
      DDRC |= 0x80;
      PORTC_PORTC7 = 1;
      break;
  }
}

void reset_pin_switch(int x) {
  switch(x) {
    case 0:
      DDRC |= 0x01;
      PORTC_PORTC0 = 0;
      break;
    case 1:
      DDRC |= 0x02;
      PORTC_PORTC1 = 0;
      break;
    case 2:
      DDRC |= 0x04;
      PORTC_PORTC2 = 0;
      break;
    case 3:
      DDRC |= 0x08;
      PORTC_PORTC3 = 0;
      break;
    case 4:
      DDRC |= 0x10;
      PORTC_PORTC4 = 0;
      break;
    case 5:
      DDRC |= 0x20;
      PORTC_PORTC5 = 0;
      break;
    case 6:
      DDRC |= 0x40;
      PORTC_PORTC6 = 0;
      break;
    case 7:
      DDRC |= 0x80;
      PORTC_PORTC7 = 0;
      break;
  }
}



#endif