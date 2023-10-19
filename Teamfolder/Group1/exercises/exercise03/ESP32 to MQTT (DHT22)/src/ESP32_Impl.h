#pragma once
#ifndef ESP32_IMP
#define ESP32_IMP
#include "ESP32interface.h"
#include "WiFiClient.h"
#include "PubSubClient.h"
#include "ArduinoJson.h"
#include "DHT.h"
#include "WiFi.h"

#define DHTpin 19
#define BUTTON 21
#define LED 18
#define BUILTINLED 2
#define DHTTYPE DHT11
#define MSG_BUFFER_SIZE (50)

class ESP32_Imp : public ESP32_Iface
{
public:
    WiFiClient wifiClient;
    PubSubClient mqttClient;
    DHT dht;
    long curTime;
    long prevTime;
    int currentButtonState;
    int lastButtonState;
    int buttonState;
    ESP32_Imp();
    virtual void connect(const char *ssid, const char *pwd = nullptr) override;
    virtual void setupMQTT(char *broker, int port) override;
    virtual void reconnect() override;
    virtual void sendMessage(char *topic, char *message) override;
    // void static mqttCallback(char *topic, byte *message, unsigned int length);
    virtual void readAndSendData(char *topic) override;
    void readButton();
};
#endif //  ESP32_IMP
