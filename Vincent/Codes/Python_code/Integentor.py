import paho.mqtt.client as mqtt

# MQTT broker details
broker_address = "192.168.12.1"
broker_port = 1883
topic = "sensor/temperatuur"

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.subscribe(topic)
    else:
        print("Connection failed with code", rc)

def on_message(client, userdata, message):
    payload = message.payload.decode("utf-8")
    try:
        random_number = float(payload)
        print("Received random number:", random_number)

        if random_number >= 27:
            print("Random number exceeds 20. Sending MQTT publish command...")
            topic = "switch"
            client.publish(topic, "on")
        else:
            print("Random number does not 20. Sending MQTT publish command...")
            topic = "switch"
            client.publish(topic, "off")
    except ValueError:
        print("Received an invalid random number:", payload)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(broker_address, broker_port, 60)

client.loop_forever()