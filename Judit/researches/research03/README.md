# Research records 03
[Other Researches](../README.md)

## Contents

1. [MQTT](README.md#mqtt)
    - [Design Patterns](README.md#design-patterns)
    - [Publish / Subscribe](README.md#publish--subscribe)
    - [MQTT Action CLI](README.md#mqtt-action-cli)
        - [Main Steps](README.md#main-steps)
        - [What are the main CLI commands for MQTT?](README.md#what-are-the-main-cli-commands-for-mqtt)
        - [What stands out?](README.md#what-stands-out)
    - [MQTT Integration](README.md#mqtt-integration)
        - [Why and how does MQTT simplify integration of IoT systems?](README.md#why-and-how-does-mqtt-simplify-integration-of-iot-systems)
        - [What are the differences of MQTT commands in IoTempower to regular CLI commands?](README.md#what-are-the-differences-of-mqtt-commands-in-iotempower-to-regular-cli-commands)
        - [Does IoTempower help you with integration and how?](README.md#does-iotempower-help-you-with-integration-and-how)
    - [MQTT Simulation](README.md#mqtt-simulation)
        - [Why and how should MQTT be used for simulation and testing?](README.md#why-and-how-should-mqtt-be-used-for-simulation-and-testing)
2. [Lab](README.md#lab)

## MQTT

### Design patterns
Most people use the same path to resolve a system

### Publish / Subscribe
Devices can share information without needing to know who specifically wants it. Subscribers simply listen for the updates they care about, and publishers send updates as they have them

- Devices or sensors (like a weather sensor or a security camera) act as publishers. They might "publish" data like temperature readings or security alerts.
- Other devices or systems (like your smartphone or computer) act as subscribers. They "subscribe" to receive updates from specific sensors or devices.
- Using a broker (like in the MQTT protocol), devices publish their data/messages to specific "topics". Other devices that have subscribed to those topics will automatically receive those messages.

### MQTT Action CLI

#### Main Steps

**Terminal 1**
1. Open the cmd
2. ssh iot@192.168.12.1 --> connects to rb pi / out gateway
3. mosquitto_sub -t magnusp -h 192.168.12.1 (subscibe to the magnusp topic in that host)

**Terminal 2**
1. Open a new cmd
2. ssh iot@192.168.12.1 --> connects to rb pi / out gateway
3. mosquitto_pub -t magnusp -h 192.168.12.1 -m "Hello" (sends a message to the magnusp topic on that host)

The first terminal recives the message. 

**Wildcards:** if you put on the topic "magnusp/#" you subscibe to everything in magnusp.

#### What are the main CLI commands for MQTT?
The main CLI commands for MQTT are:

1. **mosquitto_pub:** 

    This command-line tool is part of the Mosquitto MQTT broker and is used to publish (send) messages to MQTT topics. Here's a basic usage example:

   ```shell
   mosquitto_pub -h <broker_hostname> -t <topic> -m <message>
   ```

2. **mosquitto_sub:** 

    This command-line tool is also part of Mosquitto and is used to subscribe to MQTT topics and receive messages. Example:

   ```shell
   mosquitto_sub -h <broker_hostname> -t <topic>
   ```

3. **mqtt-cli:** 

    mqtt-cli is a popular MQTT client for the command line that provides a range of MQTT-related features and can be used to both publish and subscribe to MQTT topics.

   Example for publishing:

   ```shell
   mqtt-cli publish -h <broker_hostname> -t <topic> -m <message>
   ```

   Example for subscribing:

   ```shell
   mqtt-cli subscribe -h <broker_hostname> -t <topic>
   ```
#### What stands out?

For me, someone who did not know anything of this before starting this module, is amazing to finally light some light on how IoT works. 

It seems to be simple and straight forward, and I am curios to try some implementations of if.

### MQTT Integration

#### Why and how does MQTT simplify integration of IoT systems?
MQTT simplifies IoT integration by optimizing data exchange, ensuring reliable communication, and providing a standardized approach to messaging, which is vital for the diverse and often resource-constrained devices in IoT ecosystems.

1. **Low Overhead**: MQTT minimizes the amount of data transmitted, reducing network and resource usage.

2. **Publish-Subscribe Model**: Devices communicate by publishing messages to topics and subscribing to topics, simplifying message routing.

3. **Asynchronous Communication**: Enables real-time data exchange without devices needing to be constantly connected.

4. **QoS Levels**: Offers Quality of Service levels for message delivery, ensuring reliability in varying network conditions.

5. **Last Will and Testament**: Allows devices to specify a message to be sent upon unexpected disconnect, enhancing reliability.

6. **Retained Messages**: Provides the ability to store and retrieve the last message on a topic, simplifying state management.

7. **Scalability**: MQTT scales easily to accommodate a growing number of devices and data sources.

8. **Broker-Based Architecture**: The MQTT broker handles message routing, reducing complexity for connected devices.

#### What are the differences of MQTT commands in IoTempower to regular CLI commands?
The key differences between the MQTT commands in IoTempower and the regular CLI commands are:

1. **Environment Variables:** 
    
    IoTempower uses environment variables to automatically determine the MQTT broker's host and configuration. This means you don't always need to specify the host in IoTempower's MQTT commands, making it more user-friendly.

2. **Simplified Command Structure:** 
    
    IoTempower simplifies the syntax of MQTT commands. For example, it uses commands like "mqtt listen" and "mqtt send," which are more intuitive and user-friendly than some traditional MQTT CLI commands.

3. **MQTT Action:** 
    
    IoTempower introduces the concept of "mqtt action," allowing you to easily react to MQTT messages based on payload content. This can be used for automation without the need for complex programming.

4. **Hierarchy Awareness:** 
    
    IoTempower is aware of the hierarchical structure of MQTT topics. When specifying a topic, it can consider the context of your current environment or folder, making it easier to work with specific topics within a hierarchy.

5. **Integration and Automation:** 
    
    IoTempower MQTT commands provide a simplified way to integrate IoT devices and perform automation tasks, such as forwarding messages and reacting to specific payloads.

Overall, IoTempower aims to make working with MQTT commands more user-friendly and streamlined, particularly in the context of IoT and home automation. These distinctions may make it more accessible to users who are unfamiliar with the complexities of traditional MQTT CLI commands.

#### Does IoTempower help you with integration and how?

IoTempower provides features that can help with integration in IoT and home automation scenarios. One of the key features is the "mqtt action" command, which enables you to react to MQTT messages based on their payload content. This can be particularly useful for integration and automation in the following ways:

1. **Automated Responses:** You can set up rules to trigger specific actions or responses when certain MQTT messages with defined payloads are received. For example, you can automatically switch on a device or perform a task when a particular message is received.

2. **IoT Device Interaction:** IoTempower can act as a bridge or middleware that allows different IoT devices and systems to communicate with each other. You can use the "mqtt action" command to define how devices should interact based on the messages they exchange.

3. **Custom Logic:** It provides a way to implement custom logic and workflows without the need for extensive programming. By reacting to MQTT payloads, you can define the behavior of your IoT system based on the data it receives.

4. **Event-Driven Automation:** IoTempower allows you to create event-driven automation scenarios. When specific events occur (as indicated by MQTT messages), you can trigger corresponding actions, which can be helpful for various IoT use cases.

Overall, IoTempower's MQTT commands, particularly the "mqtt action" feature, simplify integration and automation within an IoT ecosystem. It makes it easier to define how devices should respond to incoming MQTT messages, making it more accessible to users who may not have extensive programming skills but want to create smart and responsive IoT systems.

### MQTT Simulation
#### Why and how should MQTT be used for simulation and testing?
MQTT (Message Queuing Telemetry Transport) can be a useful tool for simulation and testing in a variety of contexts, particularly IoT (Internet of Things) and distributed systems. Here's why MQTT is appropriate for simulation and testing, as well as how to use it effectively:

**Why MQTT for Simulation and Testing:**

1. **Lightweight Protocol:** MQTT is designed to be lightweight and efficient, making it well-suited for resource-constrained devices and simulation environments where resources are limited.

2. **Publish-Subscribe Model:** MQTT's publish-subscribe model allows for decoupled communication between devices. In simulation and testing, this can mimic real-world scenarios more accurately as devices can publish and subscribe to topics as needed.

3. **Scalability:** MQTT supports the concept of topics, which makes it easy to scale and simulate different devices or data streams. Each device can subscribe to the topics it's interested in, allowing for easy simulation of diverse device interactions.

4. **Message Retention:** MQTT brokers can be configured to retain messages sent to a topic, allowing new devices to retrieve the latest available data when they subscribe. This is useful for testing scenarios where a device needs to catch up on historical data.

5. **QoS Levels:** MQTT offers different Quality of Service (QoS) levels, allowing you to test scenarios with varying levels of message reliability and delivery assurance.

**How to Use MQTT for Simulation and Testing:**

1. **Scenario Emulation:** MQTT can be used to emulate real-world scenarios by simulating the behavior of devices, sensors, or systems. Devices can publish data to topics, and other devices or systems can subscribe to those topics to receive and react to the data.

2. **Load Testing:** MQTT can be used to simulate a large number of devices or clients connecting to a broker simultaneously. This helps in testing the broker's scalability and performance under heavy loads.

3. **Interoperability Testing:** In IoT and distributed systems, different devices and platforms may need to communicate with each other. MQTT can be used to test interoperability between different MQTT clients, brokers, and devices.

4. **Failover and Redundancy Testing:** MQTT is useful for testing failover and redundancy scenarios. By disconnecting clients or brokers, you can simulate network interruptions and test how well the system recovers.

5. **Message Validation:** During testing, you can use MQTT to validate the correctness of messages. This can include checking message formats, content, and compliance with protocols.

6. **Real-time Data Testing:** MQTT is well-suited for testing scenarios that involve real-time data, such as monitoring and control applications. It allows you to simulate real-time data flow and responses.

7. **Security Testing:** MQTT can be used to test security features and vulnerabilities, including authentication, encryption, and access control.

8. **Data Persistence Testing:** MQTT brokers can be configured to store messages for a certain period. This is valuable for testing scenarios where devices need to retrieve historical data.

In conclusion, MQTT's lightweight and flexible nature, as well as its publish-subscribe model, make it an effective protocol for simulating and testing IoT and distributed systems. It enables you to simulate real-world scenarios, test performance, and validate the dependability and security of your applications and devices.

## Lab
Activities can be found in the Group1 folder: 
[Activities](/Teamfolder/Group1/exercises/exercise03/README.md)