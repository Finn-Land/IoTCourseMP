#include <dht11.h>
#include <WiFi.h>
#include <PubSubClient.h>
#define DHT11PIN 4

dht11 DHT11;

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void  setup()
{
  Serial.begin(115200);
  setup_wifi();
   client.setServer(mqtt_server, mqtt_port);
 
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



void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  int chk = DHT11.read(DHT11PIN);
  float testvalue = DHT11.temperature;
  char temp [5];
  snprintf(temp, 5, "%f", testvalue);
  client.publish("sensor/temperatuur", temp);
  delay(2000);
}
