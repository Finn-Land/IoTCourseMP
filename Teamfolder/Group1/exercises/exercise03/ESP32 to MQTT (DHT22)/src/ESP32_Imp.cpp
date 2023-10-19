#include "ESP32_Impl.h"

ESP32_Imp::ESP32_Imp() : wifiClient(), mqttClient(wifiClient), dht(DHTpin, DHTTYPE)
{
}

void ESP32_Imp::connect(const char *ssid, const char *password)
{
    Serial.print("Connecting to: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        curTime = millis();
        if (curTime - prevTime > 500)
        {
            Serial.print(".");
            prevTime = curTime;
        }
    }
    Serial.println("Connected.");
}

void ESP32_Imp::setupMQTT(char *broker, int port)
{
    mqttClient.setServer(broker, port);
    // mqttClient.setCallback(mqttCallback);
    mqttClient.connect("FOINTBOINT");
    mqttClient.subscribe("magnusp/discord_led_control");
}

void ESP32_Imp::reconnect()
{
    // Loop until we're reconnected
    while (!mqttClient.connected())
    {
        Serial.println("Attempting MQTT connection...");
        // Attempt to connect, with client id
        if (mqttClient.connect("FOINTBOINT"))
        {
            Serial.println("Connected to MQTT");
            mqttClient.subscribe("magnusp/discord_led_control");
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println("Trying again in 5 seconds");
            // Wait 5 seconds before retrying
            curTime = millis();
            if (this->curTime - this->prevTime > 5000)
            {
                this->prevTime = this->curTime;
            }
        }
    }
}

void ESP32_Imp::sendMessage(char *topic, char *message)
{
    mqttClient.publish(topic, message);
}

void ESP32_Imp::readAndSendData(char *topic)
{
    /*StaticJsonDocument<256> doc;
    char output[256];
    JsonObject doc_0 = doc.createNestedObject();
    Serial.println(dht.readTemperature());
    Serial.println(dht.readHumidity());
    doc_0["Temperature"] = 12; // dht.readTemperature();
    //doc_0["Humidity"] = dht.readHumidity();

    serializeJson(doc, output);
    */
    char msg[MSG_BUFFER_SIZE];
    float tempVal = dht.readTemperature();
    snprintf(msg, MSG_BUFFER_SIZE, "%f", tempVal);

    sendMessage(topic, msg);
}

void ESP32_Imp::readButton()
{
    lastButtonState = currentButtonState;
    currentButtonState = digitalRead(BUTTON);
    if (lastButtonState == HIGH && currentButtonState == LOW)
    {
        delay(50);
        if (lastButtonState == HIGH && currentButtonState == LOW)
        {
            char msg[MSG_BUFFER_SIZE];
            if (buttonState == LOW)
            {
                buttonState = HIGH;
                int temp = 1;
                sprintf(msg, "%d", temp);
                sendMessage("magnusp/emergency_button", msg);
            }
            else
            {
                int temp = 0;
                buttonState = LOW;
                sprintf(msg, "%d", temp);
                sendMessage("magnusp/emergency_button", msg);
            }
        }
    }
}