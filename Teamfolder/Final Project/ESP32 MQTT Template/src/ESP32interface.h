#pragma once
#ifndef ESP32_MQTT_SRC_ESP32INTERFACE_H
#define ESP32_MQTT_SRC_ESP32INTERFACE_H
#include <Arduino.h>

class ESP32_Iface
{
public:
    virtual void connect(const char *ssid, const char *pwd = nullptr) = 0;
    virtual void setupMQTT(char *broker, int port) = 0;
    virtual void reconnect() = 0;
    virtual void sendMessage(char *topic, char *message) = 0;
};

#endif // 'ESP32_MQTT_SRC_ESP32INTERFACE_H'
