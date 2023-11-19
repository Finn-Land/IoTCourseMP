#include "ESP32_Impl.h"

ESP32_Imp::ESP32_Imp() : wifiClient(), mqttClient(wifiClient)
{
    pinMode(RGB_BLUE, OUTPUT);
    pinMode(RGB_RED, OUTPUT);
    pinMode(RGB_GREEN, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void ESP32_Imp::connect(const char *ssid, const char *password)
{
    Serial.print("Connecting to: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        curTime = millis();
        if (curTime - prevTime > 500)
        {
            Serial.print(".");
            prevTime = curTime;
        }
    }
    Serial.println("Connected.");
}

void ESP32_Imp::setupMQTT(char *broker, int port)
{
    mqttClient.setServer(broker, port);
    // mqttClient.setCallback(mqttCallback);
    mqttClient.connect("MagnusP");
    mqttClient.subscribe("magnusp/#");
}

void ESP32_Imp::reconnect()
{
    // Loop until we're reconnected
    while (!mqttClient.connected())
    {
        Serial.println("Attempting MQTT connection...");
        // Attempt to connect, with client id
        if (mqttClient.connect("MagnusP"))
        {
            Serial.println("Connected to MQTT");
            mqttClient.subscribe("magnusp/#");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println("Trying again in 5 seconds");
            // Wait 5 seconds before retrying
            curTime = millis();
            if (this->curTime - this->prevTime > 5000)
            {
                this->prevTime = this->curTime;
            }
        }
    }
}

void ESP32_Imp::sendMessage(char *topic, char *message)
{
    mqttClient.publish(topic, message);
}

void ESP32_Imp::setRGBLed(const RGBPins &pins)
{
    analogWrite(RGB_RED, pins.red);
    analogWrite(RGB_GREEN, pins.green);
    analogWrite(RGB_BLUE, pins.blue);
}

void ESP32_Imp::soundBuzzer(String mode)
{
    if (mode == "on")
    {
        tone(BUZZER, 500);
    }
    else if (mode == "off")
    {
        noTone(BUZZER);
    }
}