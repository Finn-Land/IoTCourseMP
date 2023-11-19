### Reflection Day 3

# Exchange Formats

IoT data can be formatted in various ways through protocols. Among the most notable formats are:

- **Text**: Text-based formats like plain text or CSV are generally less suitable for IoT applications due to their lack of standardized structure and inefficiency in data size. Parsing and processing text data can also be slower compared to more structured formats.

- **XML (Extensible Markup Language)**: XML is a flexible, human-readable format suitable for IoT in some cases. However, it can have high overhead, leading to increased data transmission and storage requirements, which may be a concern for resource-constrained IoT devices.

- **JSON (JavaScript Object Notation)**: JSON is widely used in IoT due to its lightweight and easy-to-parse structure, striking a balance between human-readability and efficiency. It's well-suited for IoT where fast and efficient data interchange is essential.

- **YAML (Yet Another Markup Language)**: Similar to JSON in structure, YAML is more human-readable and has some configurability advantages. However, like JSON, it's text-based and may be less efficient in resource-constrained IoT scenarios.

- **Binary**: Binary formats are highly efficient in terms of data size and parsing speed, making them suitable for IoT applications where quick data transmission and minimal overhead are crucial, especially for resource-constrained devices.

These are the most common data formatting methods in IoT.

# Which one is the best?

Personally, I find JSON and YAML to be the most suitable. The reasons include:

- Both are common standards.
- Both are human-readable and easy to format.

**But are they suitable for IoT systems?**

Yes, JSON has become the standard format for collecting and storing semi-structured data from IoT, mobile, and web devices. In the past, specific JSON databases were required for semi-structured storage and analysis.

**Which one is less suitable for IoT systems?**

While all data formats can be used in IoT applications depending on specific requirements, binary formats are generally the most suitable for resource-constrained devices and scenarios requiring high performance and minimal overhead. Text-based formats like plain text, XML, JSON, and YAML are more appropriate when human-readability and ease of debugging are essential but may not be ideal for extremely resource-constrained IoT devices or highly efficient applications.

# MQTT

**MQTT** (Message Queuing Telemetry Transport) is a lightweight and efficient messaging protocol designed for reliable communication between devices in IoT (Internet of Things) and other low-bandwidth, high-latency, or unreliable network environments. It operates on a publish-subscribe model, allowing devices to send and receive messages, making it ideal for real-time data exchange and remote monitoring in IoT applications. MQTT minimizes network overhead and is widely used in IoT for its simplicity and scalability.

## MQTT Commands

MQTT COMMANDS

**Check if mosquitto is running**
ps ax|grep mosq

you need the following:

- Host
- Topic
- Name

**Test**: Mosquitto_sub -t sandbox/test -h 192.168.12.1 (gateway)

mosquitto_pub -t sandbox/test -h 192.168.12.1 (gateway) -m "hello world"

(-m is message)

mosquitto_pub -t sandbox/test -h 192.168.12.1 (gateway) -m "hello world"

Mosquitto_sub -t sandbox/# -h 192.168.12.1 (gateway)
(this (#) means it listens to everything under sandbox)

Mosquitto_sub -t sandbox/test -h 192.168.12.1 (gateway)

Mosquitto_sub -v -t sandbox/test -h 192.168.12.1 (gateway)
(gets the topic)

# Second Part

Notes on the video that was shown:

One essential component of MQTT is the mosquitto_sub command, which allows you to subscribe and listen to messages. For instance, to subscribe to a topic like "sandbox/test," you would use the command mosquitto_sub -t sandbox/# -h 192.168.12.1 when connecting through a gateway.

When working with MQTT, it's worth noting that topic hierarchies are significant. If you prepend a forward slash (/) to a topic, it can have a significant impact. Without the slash, it inherits the structure of previous topics. However, by using the slash, you ensure that the topic is distinct and does not inherit any prior hierarchy.

Additionally, you should be aware that message content does not require quotation marks (" "). You can send a message like "hello world" simply as mosquitto_pub -t sandbox/test -h 192.168.12.1 -m "hello world".

Furthermore, MQTT and Mosquitto, the MQTT broker, work in harmony to facilitate communication within an IoT environment.

Another useful command in MQTT is mqtt_action. As the name implies, this command reacts to specified events. For example, you can use the following command: mqtt_action sandbox payload on mqtt_send sandbox/switch01 1. This command triggers the action of sending the message "1" to the "sandbox/switch01" topic when the "sandbox" topic's payload meets certain criteria.

## Lab Tasks

**Link to the results of the lab tasks:**

[Link To Lab Tasks](/Vincent/Days/Thirdday#-First-MQTT-exercise)