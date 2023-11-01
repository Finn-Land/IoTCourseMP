#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <M5StickCPlus.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const char* mqtt_topic = "magnusp/LCD";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set MQTT server and callback function
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  int value = message.toInt(); // Convert the message to an integer

  // Update the M5Stick Plus screen text based on the received value
  if (value == 0) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawString("Message: 0", 10, 10);
  } else if (value == 1) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawString("Message: 1", 10, 10);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (client.connect("M5StickClient")) {
      Serial.println("Connected to MQTT broker");
      client.subscribe(mqtt_topic);
    } else {
      Serial.println("Connection failed. Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
