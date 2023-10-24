# Exercise 05
For the first exercise we wrote three small Arduino programs.

## Overview
1. [IoT Empower](#iot-empower)
	- [Exploring IoTempower Services and Commands](#exploring-iotempower-services-and-commandsn)
		- [Tool Suport](#tool-support)
		- [Documentation on How to Use](#documentation-on-how-to-use)
2. [First Node](#first-node)
	- [How to begin](#how-to-begin)
	- [Simulaion Flow](#simulation-flow)
	- [Code](#code)
	- [Pictures](#pictures)
3. [Second Node](#second-node)
	- [How to begin](#how-to-begin-1)
	- [Simulaion Flow](#simulation-flow-1)
	- [Code](#code-1)
	- [Pictures](#pictures-1)
4. [Button to sound and notification](#button-to-sound-and-notification)
	- [How to begin](#how-to-begin-2)
	- [Simulaion Flow](#simulation-flow-2)
	- [Code](#code-2)
	- [Pictures](#pictures-2)
5. [Text receiver](#text-receiver)
	- [How to begin](#how-to-begin-3)
	- [Simulaion Flow](#simulation-flow-3)
	- [Code](#code-3)
	- [Pictures](#pictures-3)


## IoT Empower

### Exploring IoTempower Services and Commands

#### Tool support

| Command      | What we think it does |
| ----------- | ----------- |
| run/iot      | Runs IoTempower (starts the enviorment)       |
| iot menu   | Show the menu for IoTempower        |
| accesspoint   | Activate the accespoint or show info ot the accespoint for IoTempower        |
| iot upgrade   | update the version of IoTempower (probably by default to the newest version available)        |
| iot install   | Install a new module for IoTempower or a new device      |
| console_serial   | Show serial information of the IoTempower console        |
| initialize   | Initialize a new node        |
| adopt   | Save changes to an existing node        |
| deploy   | Deploy a new node to the IoTempower system        |
| mqtt_broker   | Show overview of mqtt listeners and senders and maybe activity between them        |
| mqtt_listen   | Start a listener to mqtt messages (probably a topic to subscribe to can be specified)        |
| mqtt_send   | Send a mqtt message (topic can likely also be defined)        |
| iot doc serve   | Show the documentation for IoTempower        |

We think all commands are supposed to be used in the command line interface of IoTempower.

The real purposes and uses of the commands can be found in the Github: 
https://github.com/iotempire/iotempower/blob/master/doc/tool-support.rst


#### Documentation on How to Use

**RFID reader**

	mfrc522(name);

This device reports the data read as well as uuid and pic (in their own topics). 

-	**Parameters:**
	- **name:** can be addressed via MQTT in the network. Inside the code it can be addressed via IN(name).

-	**Example**

		mfrc522(reader);

		This example will report data of a supported RFID/tag in node_topic/reader and uid in node_topic/reader/uid (works on most NFC tags) as well as picc in node_topic/reader/uid.

-	**Wiring**

		Wemos
		D1 Mini/    mfrc522/
		NodeMCU  -  rfid-rc522 board

    	3V3  -  3.3V
     	D8  -  sda
     	D7  -  MOSI
     	D6  -  MISO
     	D5  -  SCK
     	D0  -  RST
      	G  -  GND
    	N/C  -  IRQ (IRQ is not connected for use in IoTempower)

**PWM**

	pwm(name, pin, frequency=1000);

Control the given pin with pulse width modulation (PWM). A different frequency can be chosen for each port and even changed at runtime. Frequency is limited to 5000.

-	**Parameters:**
	- **name:** the name it can be addressed via MQTT in the network. Inside the code it can be addressed via IN(name).
	- **pin:** the gpio pin to control with PWM
	- **frequency:** the frequency for PWM (up to 5000)

-	**Example**

		pwm(blue, ONBOARDLED, 2000);
		
		Now you can set the brightness of the onboard-led to 50% sending 512 to [nodename]/blue/set

**Servo motor**

	servo(name, pin, min_us=600, max_us=2400,
    turn_time_ms=700);

Create a new servo motor controller. name will be appended to the mqtt topic and a set appended to send angles to.

-	**Parameters:**
	- **name:** the name it can be addressed via MQTT in the network. Inside the code it can be addressed via IN(name).
	- **pin:** the gpiopin
	- **freq, min_us, max_us:** values controlling the start and end motor timing settings
	- **turn_time_ms:** how long to give the motor in ms to reach its position before stopping power

-	**Example**

		servo(m1, D4);

		Now the motor can be controlled via sending to the mqtt-broker to the topic "node_topic/m1/set" the angle to turn the motor to.

**Ultrasonic distance sensor** **RCWL-1601 or HC-SR04**

	hcsr04(name, trigger_pin, echo_pin, timeout_us=30000);

Create a new HC-SR04 (or RCWL-1601) ultrasonic distance measuring device. It reads the distance in mm.

-	**Parameters:**
	- **name:** the name it can be addressed via MQTT in the network. Inside the code it can be addressed via IN(name).
	- **trigger_pin:** where the trigger pin is connected to
	- **echo_pin:** where the echo pin is connected to
	- **timeout_us:** how long to max wait for a return signal (usually no need to change default)
	- **.with_precision(precision):** can be used to only react for changes in measuring that are bigger or equal to this value

-	**Example**

		hcsr04(distance, D5, D6).with_precision(10);

-	**Wiring**

		The HCSR04 usually needs 5V input voltage (some though also work with 3.3V, test first on 3.3V, if it does not work build the voltage divider and try with 5V). 
		
		The RCWL-1601 is specified for 3.3V and does not need the voltage divider, do not connect it to 5V!

**Single rgb led**

	rgb_single(name, pin_r, pin_g, pin_b, invert=false);

Create a new rgb device object for an rgb-led connected to the pins pin_r (red pin), pin_g (green pin), and pin_b (blue pin). Name will be appended to the mqtt topic.

-	**Parameters:**
	- **name:** the name it can be addressed via MQTT in the network. Inside the code it can be addressed via IN(name).
	- **pin_r, pin_g, pin_b:** the gpiopin for red, green, and blue lines
	- **ignore_case:** should case in the command detection be ignored

- **Example**

		rgb_single(rgb1, D3, D4, D2);

		Now the RGB LED can be switched to red via sending to the mqtt-broker to the topic living room/tvlights/rgb1/rgb/set the command red.

- **Wiring** 

		If you have an integrated single RGB module with pins, there will be resitors on the module, and you can wire the module directly to the GPIO ports (RGB to the diffrent ports) and ground (or -) to ground.

		If you want to wire up a single RGB led (Comman Cathode) with four legs, soldered or on a breadboard, you need 3 resistors (100-500 Ohm range) in front of the R, G, and B channels. 

## First Node
In this part of the activity, we set-up and configurated our first IoT node.

First, we went to the https://gw.iotempire.net website and accessed the configuration folder while connected to our RaspberryPi Wifi. Once there, we createde a new Node by creating a folder and renaming it. Then modified the setup.cpp file to add a button and LED functionality.

After that, we used mqtt_listen on the RaspberryPi Shell, and the result was thet whenever we pressed or released the button attached to the ESP32, the shell would print a message.

### How to begin

1. Go to https://gw.iotempire.net
2. Go to Configuration Folder
3. Create a new Node (folder)
4. Modify the default setup.cpp file
5. Add in button and LED functionality
6. Flash ESP32
7. Wire ESP32 with a button and a LED
8. Use mqtt_listen on Raspberry Pi shell

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise05/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise05/)

## Second Node
In this activity, we need to create a new node (folder), modify the node.conf file to make it simulate a button.

After that, we wire the button to the Wemos D1 and create a flow to make it toggle the BUILTIN LED in the ESP32.

The result is that whenever we press the Wemos D1 wired button, the BUILTIN LED on the ESP32 turns on or off.

### How to begin

1. Create a new node (folder) in the system configuration folder
2. Modify the default node.conf file (paste in the button example)
3. Flash ESP32
4. Wire the Wemos D1 to the button
5. Create a new node-red flow
6. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise05/)

### Pictures
Here you can find a pictures -> [Pictures](/Teamfolder/Group1/pictures/exercise05/second-node/)

## Button to sound and notification
In this activity, we create a physical button device that uses MQTT and make it play a sound and show a notification in the Node-RED dashboard.

We modified the last node-red flow we made, and added a audio out node.

### How to begin

1. Wire the Wemos D1 to the button.
2. Edit the node-red flow to add an audio out.

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise05/button-to-sound/buttonToAudio.txt)

### Pictures
Here you can find a pictures -> [Pictures](/Teamfolder/Group1/pictures/exercise05/button-to-sound/)

## Text receiver
We used a OLED I2C display and implemented an MQTT text reciver. To do that, we connected the OLED I2C shield to the Wemos D1. 

After that, we modified the node.conf to implement the display command and deployed the new code to the Wemos D1. 

Then we created a new node-red flow that allows you to write down in a text input box and sends the message to the Wemos D1. 

The result is that whenever you enter a message on the input field of the dashboard and press the enter button on the keyboard, the same message displays on the OLED I2C display.

### How to begin

1. Connect the OLED I2C shiled to the Wemos D1
2. Modify the node.conf with the display command
3. Flash the ESP32
4. Create the node-red flow
5. Try if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise05/text-receiver/flow.txt)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise05/text-receiver/)
