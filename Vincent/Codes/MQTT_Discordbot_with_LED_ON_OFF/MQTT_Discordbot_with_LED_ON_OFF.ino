#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "iotempire-magnusperfectus";
const char* password = "iotempire";
const char* mqtt_server = "192.168.12.1";
const int mqtt_port = 1883;

// Onderwerp waar de Arduino naar luistert
const char* topic = "on/off";

// Pin voor de LED
const int ledPin = 32;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received message on topic: ");
  Serial.println(topic);
  Serial.print("Message content: ");
  
  // Create a character array to store the payload as a string
  char message[length + 1];
  for (int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0'; // Null-terminate the string
  
  Serial.println(message);

  // Check if the received message is "MP ON" to turn on the LED
  if (strcmp(message, "MP ON") == 0) {
    digitalWrite(ledPin, HIGH); // Turn the LED on
    Serial.println("LED is ON");
  } 
  // Check if the received message is "MP OFF" to turn off the LED
  else if (strcmp(message, "MP OFF") == 0) {
    digitalWrite(ledPin, LOW); // Turn the LED off
    Serial.println("LED is OFF");
  }
  // Handle other cases or messages here if needed
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // Configureer de pin als uitgang voor de LED
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Verbinding maken met ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi verbonden");
  Serial.println("IP-adres: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Poging tot MQTT-verbinding...");
    if (client.connect("ArduinoClient")) {
      Serial.println("Verbonden met MQTT-broker");
      client.subscribe(topic);
    } else {
      Serial.print("Mislukt, rc=");
      Serial.print(client.state());
      Serial.println(" opnieuw proberen in 5 seconden");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // Voer hier andere taken van de Arduino uit
}
