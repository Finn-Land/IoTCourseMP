/*
Example code to connect to MQTT and Wi-Fi using ESP32.
Written by Finn Bosma(2022), public domain
*/
#include "ESP32_Impl.h"

ESP32_Imp esp32;

// Wifi settings
char *SSID = "iotempire-magnusperfectus";
char *PWD = "iotempire";

// MQTT settings
char *mqttServer = "192.168.12.1";
int mqttPort = 1883;

// Timing variables
long curTime;
long prevTime;

static void mqttCallback(char *topic, byte *message, unsigned int length);

void setup()
{
  Serial.begin(115200);
  esp32.connect(SSID, PWD);
  esp32.setupMQTT(mqttServer, mqttPort);
  esp32.mqttClient.setCallback(mqttCallback);
}

static void mqttCallback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.println("Message: ");

  String value;
  for (int i = 0; i < length; i++)
  {
    value += ((char)message[i]);
    Serial.print((char)message[i]);
  }
  if (strcmp(topic, "magnusp/rgb/red") == 0)
  {
    esp32.setRGBLed({value.toInt(), -1, -1});
  }
  else if (strcmp(topic, "magnusp/rgb/green") == 0)
  {
    esp32.setRGBLed({-1, value.toInt(), -1});
  }
  else if (strcmp(topic, "magnusp/rgb/blue") == 0)
  {
    esp32.setRGBLed({-1, -1, value.toInt()});
  }
  else if (strcmp(topic, "magnusp/buzzer") == 0)
  {
    if (value.toInt() == 1)
    {
      esp32.soundBuzzer("on");
    }
    else
    {
      esp32.soundBuzzer("off");
    }
  }
  Serial.println();
}

void loop()
{
  if (!esp32.mqttClient.connected())
  {
    esp32.reconnect();
  }
  esp32.mqttClient.loop();

  // Non-Blocking delay to publish to MQTT
  curTime = millis();
  if (curTime - prevTime > 2000)
  {
    // Enter topic here and message here
    prevTime = curTime;
  }
}
