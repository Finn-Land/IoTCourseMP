import paho.mqtt.client as mqtt

# MQTT broker details
broker_address = "192.168.12.1"
broker_port = 1883
topic = "switch"


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.subscribe(topic)
    else:
        print("Connection failed with code", rc)

client = mqtt.Client()
client.on_connect = on_connect

client.connect(broker_address, broker_port, 60)


def on_message(client, userdata, message):
    payload = message.payload.decode("utf-8")
    try:
        on_off = str(payload)

        if on_off == "on":
            print("turning on the AC")
        if on_off == "off":
            print("turning off the AC")   
    except ValueError:
        print("Received an invalid random number:", payload)


client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(broker_address, broker_port, 60)

client.loop_forever()