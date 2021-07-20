#ifndef LED_H
#define LED_H

#include "iom324pb.h"

extern void set_direction_ouput(volatile unsigned char *DDR, int x);
extern void set_direction_input(volatile unsigned char *DDR, int x);
extern void power_led_on(int x);
extern void power_led_off(int x);
extern void led_blink_fast(int x);
extern void led_blink_slow(int x);
extern void led_on_button_pressed(int x);
extern void ob2_ex6();



#endif