#include "iom324pb.h"
#include "gpio.h"
#include "led.h"
#include "button.h"
#include "sos.h"


void main(void)  {

  while(1){
  
  led_on_button_pressed(0);
  led_on_button_pressed(1);
  led_on_button_pressed(2);
  led_on_button_pressed(3);
  }
}