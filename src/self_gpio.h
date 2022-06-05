#include <Arduino.h>

void gpio_init_system(){
    pinMode(14,OUTPUT);  
    digitalWrite(14,0);
}

void gpio_set_relay(uint8_t state){
    digitalWrite(14, state);
}