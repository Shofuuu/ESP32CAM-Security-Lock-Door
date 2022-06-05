#include <Arduino.h>
#include <esp32-hal-ledc.h>

void gpio_init_system(){
    pinMode(14,OUTPUT);  
    digitalWrite(14,0);

    ledcAttachPin(4, 4);  
    ledcSetup(4, 5000, 8);
}

void gpio_set_relay(uint8_t state){
    digitalWrite(14, state);
}