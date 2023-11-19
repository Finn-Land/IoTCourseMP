#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#define USE_SERIAL Serial
 
#define BUTTON_PIN 4

WiFiMulti wifiMulti;
bool ledState = LOW;
bool buttonState = LOW;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  USE_SERIAL.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  wifiMulti.addAP("RipForFire", "Welkom01!#");
}

void loop() {
  if (wifiMulti.run() == WL_CONNECTED) {
    // Read the state of the button with debouncing
    int reading = digitalRead(BUTTON_PIN);
    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == LOW) {
          // Toggle the LED state and send an HTTP request
          ledState = !ledState;
          controlLED(ledState);
        }
      }
    }
    lastButtonState = reading;
  }
  delay(1000); // Adjust the delay as needed
}

void controlLED(bool newState) {
  HTTPClient http;
  USE_SERIAL.print("[HTTP] begin...\n");
  if (newState == HIGH) {
    http.begin("http://192.168.68.124/on"); // HTTP
    USE_SERIAL.print("[HTTP] Turning LED ON...\n");
  } else {
    http.begin("http://192.168.68.124/off"); // HTTP
    USE_SERIAL.print("[HTTP] Turning LED OFF...\n");
  }

  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    USE_SERIAL.println(payload);
    if (payload == "LED ON" && newState == HIGH) {
      USE_SERIAL.println("LED is ON");
    } else if (payload == "LED OFF" && newState == LOW) {
      USE_SERIAL.println("LED is OFF");
    } else {
      USE_SERIAL.println("Unknown response");
    }
  } else {
    USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
