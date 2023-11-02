#include <M5StickC.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  M5.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  M5.IMU.Init();
  Serial.begin(115200);
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
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);

//  Serial.print("Gyro X: ");
//  Serial.print(gyroX);
//  Serial.print("  Gyro Y: ");
//  Serial.print(gyroY);
//  Serial.print("  Gyro Z: ");
//  Serial.println(gyroZ);
 if (gyroZ >= 45){
        Serial.println("Z is higher");
        Serial.println(gyroZ);
        client.publish("Value Z", "ON");
}


  delay(1000); // Wacht 1 seconde voordat de volgende meting wordt uitgevoerd
}
