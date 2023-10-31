# Exercise 06
For the first exercise we wrote three small Arduino programs.

## Overview

## Improved Scenarios
First task we did was update the scenarios to make them more suitable torwards our IoT project and or overall project.

First, we asked Ulno for guidance regarding our project idea, and we agreed to
use a gyroscope in one hand and a deviced somehow like a smartwatch on the other. When doing a specific movement with the gyroscope, it sends a topic to someone else's watch, which vibrates and displays a message. After pressing a button on the watch, this sends a topic to the first person's watch and vibrates.

After that, we created a new user scenario related with our project adn the persona we already had. 

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise06/Scenario/)

## RFID reader
We connected the RFID-RC522 RFID tag reader via SPI to a Wemos D1 Mini. Created a new node named "RFID_FJJ" and  adjusted its setup.cpp by adding the line:
	
	mfrc522(reader);

After that, we flashed the Wemos D1 Mini.

We then created a Node-Red flow wit an mqtt_in on the topic /RFID_FJJ/reader/#. Then we added a switch, to detect either if the acces is granted or not. After that we change the payloads to a more readable text. We then added a button that resets the text and colors.

### How to begin
1. Wire the RFID-RC522 to the Wemos D1 Mini
2. Create new Node
3. Adjust the setup.cpp
4. Flash the Wemos D1 Mini
5. Create a Node-Red flow
6. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise06/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise06/)


## Access Control System -> New Actors -> 1
For this activity we wired a LED with a resistor to the Wemos D1. After that, created a new node called "PWM_FJJ". Once there, we adjusted the setup.cpp to use PWM on the pin with the following code:

	pwm(pwm, 7, 2000);

Then we created a Node-Red flow with a slider to control the brightness of the LED. 
To do so, we added a mqtt_in node, on the topic "PWM_FJJ/blue/set". After that we 

We encounter a big problem related with the Wemos D1 not working, so we spend a huge amount of time stucked in this activity trying everything we could think of.

At the end, we managed to finish the activity and successfully created a slider on node-red that sent the payload to the topic, modifying the brightness of the LED.

### How to begin
1. Wire a LED with a resistor to the Wemos D1
2. Create new node
3. Adjust seup.cpp to use PWM on this GPIO
4. Flash Wemos D1
5. Create a node-red flow with a slider to control the brightness of the LED
6. Check if it works

## Access Control System -> New Actors -> 2
For this activity we wired a Buzzer where the LED was to the Wemos D1. We also had to modify the node-red flow, adding another slider that changes the frequency sending the payload to the topic "PWM_FJJ/pwm/frequency/set".

The result is a Wemos D1 connected to a buzzer that can change it's intensity and frequency based on two sliders on node-red.

### How to begin
1. Wire a Buzzer to the Wemos D1
2. Modify the Node-red flow to add a slider for the frequency
2. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise06/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise06/)
