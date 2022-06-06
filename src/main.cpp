#include <Arduino.h>

#include <ArduinoJson.h>
#include "self_gpio.h"
// #include "self_sdcard.h"
#include "soc/soc.h"             
#include "soc/rtc_cntl_reg.h"
#include "camera_pins.h"
#include "camera_server.h"
#include "tele.h"
#include "self_wifi.h"

void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);  
    Serial.println();

    gpio_init_system();
    wifi_init_system();
    // sdmmc_init_system();
    startTele();
    camera_init_system();

    // testing
    camera_set_server(START_CAMERA_SERVER);
}

void loop() {
}
