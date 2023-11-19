#include <M5StickCPlus.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  M5.begin(); // Initialisatie van M5StickCPlus
  M5.IMU.Init(); // Initialisatie van de IMU-module (gyroscoop)
  M5.Lcd.setRotation(3); // Draai het scherm 270 graden
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(40, 80);
  M5.Lcd.print("Gyroscope");
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP-adres: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Trying to MQTT-connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected witht MQTT-broker");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println("Retry in 5 secondes");
      delay(5000);
    }
  }
}


void loop() {
    if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  float gyroX, gyroY, gyroZ;

  // Lees de gyroscoopgegevens
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  // Toon de gyroscoopgegevens op het scherm
  M5.Lcd.setCursor(0, 0);
//  M5.Lcd.print("Gyro X: ");
//  M5.Lcd.println(gyroX);
//  M5.Lcd.print("Gyro Y: ");
//  M5.Lcd.println(gyroY);
//  M5.Lcd.print("Gyro Z: ");
//  M5.Lcd.println(gyroZ);
  delay(1000);
  if (gyroZ >= 65){
        Serial.println("Z is higher");
        Serial.println(gyroZ);
        client.publish("Status", "ON");
        delay(10000);
        client.publish("Status", "OFF");
}
}
