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
  esp32.dht.begin();
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

static void mqttCallback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.println("Message: ");

  // Don't need this since we are always expecting JSON?
  String value;
  for (int i = 0; i < length; i++)
  {
    value += (char)message[i];
    Serial.print((char)message[i]);
  }
  if (value == "on")
  {
    digitalWrite(LED, HIGH);
  }
  else if (value == "off")
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    Serial.println("Command not known.");
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

  esp32.readButton();

  // Non-Blocking delay to publish to MQTT
  curTime = millis();
  if (curTime - prevTime > 2000)
  {
    // esp32.readAndSendData("magnusp/DHTtemp");
    prevTime = curTime;
  }
}
