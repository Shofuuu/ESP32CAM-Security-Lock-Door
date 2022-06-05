#include <WiFi.h>

#define WIFI_SSID_STR   "Rainy"
#define WIFI_PWD_STR    ""

#define GET_MS_TICK(x)  (millis() - elapsed_time) > x

static uint32_t elapsed_time = 0;

void wifi_init_system(){
    WiFi.begin((const char*)WIFI_SSID_STR, (const char*)WIFI_PWD_STR);
    elapsed_time = millis();

    uint8_t flag_connected = 0;

    while(WiFi.status() != WL_CONNECTED){
        flag_connected = 1;

        if(GET_MS_TICK(5000)){
            flag_connected = 0;
            Serial.println("\n[WIFI] WiFi connect timeout!");
            break;
        }

        delay(500);
    }

    if(flag_connected){
        Serial.println("\n[WIFI] WiFi connected");
        Serial.println("[WIFI] IP Address : " + WiFi.localIP().toString());
    }
}