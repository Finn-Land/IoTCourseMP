#pragma once
#ifndef ESP32_IMP
#define ESP32_IMP
#include "ESP32interface.h"
#include "WiFiClient.h"
#include "PubSubClient.h"
#include "WiFi.h"
#include "M5StickC.h"

#define DHTpin 15
#define DHTTYPE DHT22
#define RGB_BLUE 27
#define RGB_GREEN 25
#define RGB_RED 32
#define BUZZER 4

class ESP32_Imp : public ESP32_Iface
{
private:
public:
    struct RGBPins
    {
        int red;
        int green;
        int blue;
    };
    WiFiClient wifiClient;
    PubSubClient mqttClient;
    long curTime;
    long prevTime;
    ESP32_Imp();
    virtual void connect(const char *ssid, const char *pwd = nullptr) override;
    virtual void setupMQTT(char *broker, int port) override;
    virtual void reconnect() override;
    virtual void sendMessage(char *topic, char *message) override;
    // void static mqttCallback(char *topic, byte *message, unsigned int length);
    void setRGBLed(const RGBPins &pins);
    void soundBuzzer(String mode);
};
#endif //  ESP32_IMP
