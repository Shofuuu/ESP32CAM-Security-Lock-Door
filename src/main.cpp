#define NO_DEBUG   1

#include <Arduino.h>

#ifdef NO_DEBUG
#include <ArduinoJson.h>
#include "self_gpio.h"
#include "self_sdcard.h"
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
    sdmmc_init_system();
    startTele();
    camera_init_system();

    // testing
    camera_set_server(START_CAMERA_SERVER);
}

void loop() {
}

#else
#include <FS.h>
#include <SD_MMC.h>

void setup(){
    Serial.begin(115200);

    if(!SD_MMC.begin()){
        Serial.println("Card mount failed!");
        return;
    }

    uint8_t card_type = SD_MMC.cardType();
    if(card_type == CARD_NONE){
        Serial.println("SD Card Not attached!");
        return;
    }

    String str;
    switch(card_type){
        case CARD_MMC : str = "MMC"; break;
        case CARD_SD : str = "SDSC"; break;
        case CARD_SDHC : str = "SDHC"; break;
        default : str = "UNKNOWN"; break;
    }

    Serial.println("SD Card type : " + str);
}

void loop(){}
#endif