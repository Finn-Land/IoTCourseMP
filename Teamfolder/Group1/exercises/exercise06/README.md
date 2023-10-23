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
We connected the RFID-RC522 RFID tag reader via SPI to a Wemos D1 Mini, adjusted its setup.cpp by adding the line:
	
	mfrc522(reader);

After that, we flashed the Wemos D1 Mini.

We then created a Node-Red flow wit an mqtt_in on the topic /RFID_FJJ/reader/#. Then we added a switch, to detect either if the acces is granted or not. After that we change the payloads to a more readable text. We then added a button that resets the text and colors.

### How to begin
1. Wire the RFID-RC522 to the Wemos D1 Mini
2. Adjust the setup.cpp
3. Flash the Wemos D1 Mini
4. Create a Node-Red flow
5. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise05/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise05/text-receiver/)


## Access Control System -> New Actors -> 1
For this activity

First, we created a new node called "LED_PWM"

### How to begin
1. Wire a LED with a resistor to the Wemos D1
2. Adjunst seup.cpp to use PWM on this GPIO
3. Flash
4. Create a node-red flow with a slider to control the brightness od the LED