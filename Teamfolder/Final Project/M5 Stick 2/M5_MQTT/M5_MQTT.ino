#include <M5StickCPlus.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const char* mqtt_topic = "magnusp/LCD";

unsigned long previous_time = 0;
int period = 2000;
int color[] = {0xfd79, 0xe8e4, 0xfbe4, 0xff80, 0x2589, 0x51d, 0x3a59, 0xa254, 0x7bef, 0xffff};
int currentColor = 0;
bool shouldChangeColor = true;
bool isIncomingCall = false;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  M5.begin();
  setupWifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (shouldChangeColor && millis() - previous_time >= period) {
    previous_time = millis();
    M5.Lcd.fillScreen(color[currentColor]);
    currentColor = (currentColor + 1) % 10;
  }

  if (isIncomingCall) {
    M5.Lcd.setTextFont(2);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);
    M5.Lcd.setCursor(20, 100);
    M5.Lcd.print("Incoming call");
  }
}

void setupWifi() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  int messageValue = message.toInt();
  if (messageValue == 0) {
    shouldChangeColor = false;
    M5.Lcd.fillScreen(TFT_BLACK);
    isIncomingCall = false;
  } else if (messageValue == 1) {
    shouldChangeColor = true;
    isIncomingCall = true;
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("M5StickCPlusClient")) {
      Serial.println("connected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
