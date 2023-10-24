# Reflection day 3
## Lecture reflection
The first part of the lecture was to compare 5 data formats  used in IoT:
Text Data Format:
Text-based formats like plain text or CSV can be used in IoT for simple data exchange, especially when the data is human-readable and doesn't need complex structuring. However, they might not be efficient for transmitting large amounts of data or structured data.

XML (eXtensible Markup Language):
XML is a structured and extensible data format that can be suitable for IoT applications where data needs to be well-defined, organized, and easily parseable. However, XML can be more verbose compared to other formats like JSON and may require more bandwidth for communication.

JSON (JavaScript Object Notation):
JSON is an efficient data format for IoT due to its lightweight, human-readable, and easy-to-parse structure. It's well-suited for IoT applications where data needs to be transmitted efficiently between devices and applications.

YAML (YAML Ain't Markup Language):
YAML is a human-readable and easily writable data serialization format. It's less verbose compared to XML and allows for a clear and structured representation of data. YAML can be a good choice in scenarios where human readability is important, and the data structures are moderately complex.

Binary Data Format:
Binary formats can be highly efficient for transmitting large amounts of data in IoT. They are compact and can significantly reduce bandwidth usage. However, they are not human-readable, which can make debugging and understanding the data more challenging.

## Lab reflection
## MQTT basics
The MQTT basics are the following. MQTT uses a publish and subscribe protocol, which means that devices can publish data to a topic. Every other device that is also subscribed to that topic can read the data.

Here are the basic commands used on the command line:

iot 

MQTT + TAB --> To see all options

mqtt_listen sandbox/test --> Subscribes to a topic

mqtt_send sandbox/test Hello World --> Publishes "Hello World" to sandbox/test

"/sanbox" will disrupts the hierarchy and just listens on ip/sanbox. This is only done when using the "/" in front of the topic

mqtt_action sandbox payload on mqtt_send sandbox/switch01 --> used to react on messages

## MQTT Simulation
The assignment can be found here -->

This assignment was easy to do since I have experience with Node-Red. I made it at first with a function block but I apparently wasn't allowed to use it so we used switch and change blocks.
