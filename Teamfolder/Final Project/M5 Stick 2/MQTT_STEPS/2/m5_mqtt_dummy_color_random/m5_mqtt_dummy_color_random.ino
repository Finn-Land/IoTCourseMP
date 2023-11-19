#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <M5StickCPlus.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const char* mqtt_topic = "magnusp/LCD";
const int mqtt_port = 1883;

// Display color array
unsigned long previous_time = 0;
int period = 2000;
int color[] = { 0xfd79, 0xe8e4, 0xfbe4, 0xff80, 0x2589, 0x51d, 0x3a59, 0xa254, 0x7bef, 0xffff };
int currentColor = 0;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {
  M5.begin();
  connectToWiFi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  subscribeToMQTT();
}

void loop() {
  if (!client.connected()) {
    reconnectToMQTT();
  }
  client.loop();

  // Check if the message is "1" and change colors every 2 seconds
  if (M5.Lcd.readPixel(0, 0) != 0x0000 && millis() - previous_time >= period) {
    previous_time = millis();
    int a = random(0, 9);
    M5.Lcd.fillScreen(color[a]);
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  if (strcmp(topic, mqtt_topic) == 0) {
    // Convert the payload to a string
    String message = "";
    for (int i = 0; i < length; i++) {
      message += (char)payload[i];
    }

    // Parse the message and change the display color
    int messageValue = message.toInt();
    if (messageValue == 0) {
      M5.Lcd.fillScreen(0xfffff);
    }
    else {
      int a = random(0, 9);
      if (millis() - previous_time >= period) {
        previous_time = millis();
        M5.Lcd.fillScreen(color[a]);
      }
    }
  }
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void subscribeToMQTT() {
  while (!client.connected()) {
    if (client.connect("M5StickCPlusClient")) {
      client.subscribe(mqtt_topic);
    } else {
      delay(1000);
    }
  }
}

void reconnectToMQTT() {
  while (!client.connected()) {
    if (client.connect("M5StickCPlusClient")) {
      client.subscribe(mqtt_topic);
    } else {
      delay(1000);
    }
  }
}
