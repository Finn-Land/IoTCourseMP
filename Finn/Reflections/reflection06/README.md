# Reflection 06

## Lecture reflection

### IoTEmpower basics

#### Create and initialize new node
- Start with creating a new node folder
- Edit board if needed
- Add sensors and actuators to setup.cpp, the code for these can be found in the "Documentation"tab.
- Initialize code on board

#### Finding documentation
- Documentation can be found on the GIT repo, under the "doc" folder

#### Finding scripts
- Scripts can be found under the "bin" folder in the GIT repo

### System in folders

#### Which topic to be called for:
- Switch on the coffee machine?
    - myhouse/kitchen/coffee-machine/switch
- Set all the lights in living room to blue?
    - myhouse/living_room/leds1/blue
    - myhouse/living_room/leds2/blue
- Turn the main power off?
    - myhouse/main/switch

#### General rule for forming topics in IoTempower?
- Make them super general, and clear on what they are meant to do 

#### When to change something in system.conf?
- When changing the access point
- When changing WiFi
- When changing the MQTT server

There are others as well, but these are the most important

#### What role does the location of system.conf play?
- To connect the node to WiFi and MQTT

### Nodes
- What needs to/can go into node.conf?
    - Everything that can be in the other config files as well
    - node.conf overwrites system.conf, system.conf overwrites etc/iotempower.conf

### Compilation
- Deploy
    - Deploy can be done via internet, can only be done one at a time to not decrease the deploy speed
- Initialize serial
    - Initialize serial must be done via a wired Raspberry Pi connection

### Filters

- What is a common problem when we measure?
    - Too much of the same data at the same time, will flow graphs 
- How can we do graphs in node-red?
    - We use the nodes from the dashboard library
- What are filters and how do they work (in Node-Red and IoTempower)?
    - Filters in Node-Red prevent the same value from being sent too my times
    - Filters in IoTEmpower can be set in the sensor configuration
- What is offered and what other generic filters would be nice?
    - Avergae, median, round, time_filter and more
- What is the “fluent” style?
    - The filter chaining 

### Feature list update
The feature I wanted the most was an easy-to-read log

IotEmpower provides what I would say is an easy to read log. It has descriptive error codes, and has a similair log to the one that platform IO uses.

## Lab reflection
We worked on the following assignments:

### 1. RFID Reader

The RFID reader was a simple exercise, we hooked it up to the Wemos D1 mini, ran the code and it could read the card UID on the MQTT topic. We then made the logic for "Access granted" and "Access denied".

[RFID Reader](/Teamfolder/Group1/exercises/exercise06/README.md#rfid-reader)

### 2. LED with PWM

We used the ESP32 minikit for this exercise, we struggled doing it on the Wemos because the PWM didn't want to work. So when we switched to the ESP32, changed the pin it did finally work.

[LED with PWM](/Teamfolder/Group1/exercises/exercise06/README.md#access-control-system---new-actors---1)

### 3. Buzzer with PWM

This exercise was easy to do since we already used PWM with an LED, so using a buzzer was just replacing the LED with a buzzer and it worked.

[Buzzer with PWM](/Teamfolder/Group1/exercises/exercise06/README.md#access-control-system---new-actors---2)

###  4. RGB LED

I didn't do this exercise during the lab, but in our final project that we are presenting on the last day. It's a simple porgram that receives the RGB values on seperate topics, and changes the color of the LED based on the color value that was just changed.

[RGB LED](/Teamfolder/Final%20Project/README.md)

###  5. Group project

The group project took some more time, I did the RFID reader with the traffic lights. I gave the flow with the components to Vincent who made the rest of the assignment.

[Group project](/Vincent/Days/Sixthday.md#project-1-group)

Overall the exercises were pretty easy, they just took some time. As mentioned we also had some issues with PWM on the ESP32 minikit, which we swapped with normal ESP32. The exercises for me up until this point are very simple, but since I'm working with someone else without experience it can be tiring to make the simple assignment and having to explain it to someone with minimal coding experience.


