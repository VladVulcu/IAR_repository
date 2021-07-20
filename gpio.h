#ifndef GPIO_H
#define GPIO_H

#include "iom324pb.h"

extern void gpio_halfSec_delay(void);
extern void gpio_oneSec_delay(void);
extern void gpio_twoSec_delay(void);
extern void gpio_160ms_delay(void);
extern void gpio_set_pin(volatile unsigned char *PORT, int x);
extern void gpio_reset_pin(volatile unsigned char *PORT, int x);
extern void gpio_toggle_pin(volatile unsigned char *PORT, int x);
extern void set_pin_switch(int x);
extern void reset_pin_switch(int x);



#endif