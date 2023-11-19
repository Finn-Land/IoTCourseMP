# Reflection day 3
## Lecture reflection
This lecture was the introduction to using MQTT. 

## MQTT basics
The MQTT basics are the following. MQTT uses a publish and subscribe protocol, which means that devices can publish data to a topic. Every other device that is also subscribed to that topic can read the data.

Here are the basic commands used on the command line:

**Initialize cmd to use MQTT commands:**

    iot 

**To see all options:**

    MQTT + TAB --> 

**Subscribes to a topic:**

    mqtt_listen sandbox/test 

**Subscribe to a wildcard on a topic:**

    mqtt_listen sandbox/#

Now you'll get every message on every topic that starts it's hierarchy on the sandbox/ topic.
    
**Publishes "Hello World" to sandbox/test:**

    mqtt_send sandbox/test Hello World 

"/sanbox" will disrupts the hierarchy and just listens on ip/sanbox. This is only done when using the "/" in front of the topic

**React on messages with mqtt_action:**

    mqtt_action sandbox payload on mqtt_send sandbox/switch01 

## Lab reflection

## MQTT simulation
This assignment was easy to do since I have experience with Node-Red. We made it at first with a function block but I apparently wasn't allowed to use it so we used switch and change blocks. It was very easy for me to do this

[MQTT Simulation](/Teamfolder/Group1/exercises/exercise03/README.md#mqtt-simulation)

## MQTT with hardware
This just replaced our original simulation with the actual hardware. So we used a DHT11 as temperature sensor, and an LED to simulate an AC to turn on and off. For the DHT code we used an existing template for communicating over MQTT amde by me, for the LED we just used a .ino file.

[MQTT with hardware](/Teamfolder/Group1/exercises/exercise03/README.md#mqtt-on-microcontroller)
