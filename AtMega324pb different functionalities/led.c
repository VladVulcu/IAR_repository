#ifndef LED_C
#define LED_C

#include "led.h"
#include "gpio.h"

void set_direction_ouput(volatile unsigned char *DDR, int x) {
  *DDR |= (1 << x);
}

void set_direction_input(volatile unsigned char *DDR, int x) {
  *DDR &= ~(1 << x);
}

void power_led_on(int x) {
  switch(x) {
  case 0: {
    DDRC |= 0x80;
    PORTC_PORTC7 = 0;
    break;
  }
  case 1: {
    DDRD |= 0x20;
    PORTD_PORTD5 = 0;
    break;
  }
  case 2: {
    DDRD |= 0x10;
    PORTD_PORTD4 = 0;
    break;
  }
  case 3: {
    DDRA |= 0x08;
    PORTA_PORTA3 = 0;
    break;
  }
  case 4: {
    DDRB |= 0x08;
    PORTB_PORTB3 = 0;
  }
  }
}

void power_led_off(int x) {
  switch(x) {
  case 0: {
    DDRC |= 0x80;
    PORTC_PORTC7 = 1;
    break;
  }
  case 1: {
    DDRD |= 0x20;
    PORTD_PORTD5 = 1;
    break;
  }
  case 2: {
    DDRD |= 0x10;
    PORTD_PORTD4 = 1;
    break;
  }
  case 3: {
    DDRA |= 0x08;
    PORTA_PORTA3 = 1;
    break;
  }
  case 4:
    DDRB |= 0x08;
    PORTB_PORTB3 = 1;
  }
}

void led_blink_fast(int x) {
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_160ms_delay();
  gpio_oneSec_delay();
}

void led_blink_slow(int x) {
  power_led_on(x);
  power_led_off(x);
  gpio_halfSec_delay();
  power_led_on(x);
  power_led_off(x);
  gpio_halfSec_delay();
  gpio_oneSec_delay();
}

void led_on_button_pressed(int x) {

   switch (x) {
      case 0: {
        if (PINC_PINC6 == 0) {
          DDRC = 0x80;
          PORTC |= 0xC0;
          DDRB |= 0x08;
          PORTB |= 0x08;
          PORTD_PORTD5 = 1;
          PORTD_PORTD4 = 1;
          PORTA_PORTA3 = 1;
          PORTC_PORTC7 = 1;
          PORTB_PORTB3 = 0;
          
          if (PORTB_PORTB3 == 0) {
            PORTD_PORTD5 = 1;
            PORTD_PORTD4 = 1;
            PORTA_PORTA3 = 1;
          }
          
        }
         break; 
      }
      case 1: {
        if (PORTD_PORTD5 == 0 && PINC_PINC1 == 0) {
          PORTD_PORTD5 = 1;
        }
        else if (PINC_PINC1 == 0) {
          DDRD |= 0x20;
          PORTD |= 0x20;
          PORTC |= 0x02;
          PORTD_PORTD5 = 0;
          }
          break;
      }
      
      case 2: {
        if (PORTD_PORTD4 == 0 && PINA_PINA0 == 0) {
          PORTD_PORTD4 = 1;
        }
        else if (PINA_PINA0 == 0) {
        DDRD |= 0x30;
        PORTD |= 0x10;
        PORTA |= 0x01;
        PORTD_PORTD4 = 0;
        }
        break;
   }
      case 3: {
        if (PORTA_PORTA3 == 0 && PINA_PINA1 == 0) {
          PORTA_PORTA3 = 1;
        }
        else if (PINA_PINA1 == 0) {
        DDRA |= 0x08;
        PORTA |= 0x0A;
        PORTA_PORTA3 = 0;    
        }
        break;
      }
   }
}

void ob2_ex6() {
    set_direction_ouput(&DDRD,5); // aprinde LED1
    set_direction_ouput(&DDRD,4); // aprinde LED2
    set_direction_input(&DDRA,3); // stinge LED3
    gpio_halfSec_delay();
    set_direction_input(&DDRD,5); // stinge LED1
    set_direction_ouput(&DDRA,3); // aprinde LED3
    gpio_halfSec_delay();
    set_direction_input(&DDRD,4); // stinge LED2
    set_direction_ouput(&DDRD,5); // aprinde LED1
    gpio_halfSec_delay();
}



#endif