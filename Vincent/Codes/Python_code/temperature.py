import paho.mqtt.client as mqtt
import random
import time

# MQTT broker details
broker_address = "192.168.12.1"
broker_port = 1883
topic = "Temperature"  # Replace with the desired MQTT topic

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
    else:
        print("Connection failed with code", rc)

client = mqtt.Client()
client.on_connect = on_connect

client.connect(broker_address, broker_port, 60)

while True:
    # Generate a random number between 1 and 100
    random_number = random.randint(10, 30)
    print("Generated random number:", random_number)
    
    client.publish(topic, str(random_number))
    print(f"Published random number {random_number} to topic {topic}")

    time.sleep(10)  # Wait for 5 seconds before generating the next random number