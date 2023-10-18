# Exercise 01
For the first exercise we wrote three small Arduino programs.

## Overview
1. [Preparation](/Teamfolder/exercises/exercise01#preparation)
2. [Example - blinking LED](/Teamfolder/exercises/exercise01#example---blinking-led)
	- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin)
	- [Code for the blinking LED](/Teamfolder/exercises/exercise01#code-for-the-blinking-led)
	- [Pictures](/Teamfolder/exercises/exercise01#pictures)
3. [Control an ESP8266 from another ESP8266 via WLAN](/Teamfolder/exercises/exercise01#control-an-esp8266-from-another-esp8266-via-wlan)
	- [Client - ESP8266 with a button which talks to another ESP8266](/Teamfolder/exercises/exercise01#client---esp8266-with-a-button-which-talks-to-another-esp8266)
		- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin-1)
		- [Code for the client](/Teamfolder/exercises/exercise01#code-for-the-client)
		- [Pictures](/Teamfolder/exercises/exercise01#pictures-1)
	- [Server - ESP8266 with a LED which is switched on/off from the client](/Teamfolder/exercises/exercise01#server---esp8266-with-a-led-which-is-switched-onoff-from-the-client)
		- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin-2)
		- [Code for the server](/Teamfolder/exercises/exercise01#code-for-the-server). 
4. [Problems](/Teamfolder/exercises/exercises01#Problems)



## Preparation
Before we could start doing the first little example, we had to setup our Raspberry Pi.
1. We installed the Arduino IDE from https://www.arduino.cc/en/Main/Software
2. We added support for ESP8266 to the Arduino environment by following these steps: https://github.com/esp8266/Arduino
3. We downloaded the image for the Raspberry Pi from https://github.com/iotempire/iotempower/blob/master/doc/image-pi.rst
4. We checked the checksum with the tool from https://raylin.wordpress.com/downloads/md5-sha-1-checksum-utility/
5. We downloaded etcher from https://www.balena.io/etcher/
6. We flashed the image to the Raspberry Pi with etcher and validate it
7. In wifi.txt we changed the WiFi name and password and removed '#' from the WiFi name line
8. We connected the Raspberry Pi to the network via Ethernet cable and powered it up

## Example - blinking LED
For this small example we created an Arduino program which makes the onboard LED of the ESP8266 blink every second.

### How to begin
1. Tools > Board > LOLIN(WEMOS) D1 R2 & mini
2. Files > Example > Built in examples > 01. Basics > Blink
3. Verify the program
4. Upload File to ESP8266

### Code for the blinking LED
Here you can find the code for the blinking LED -> [example_blink.ino](/Teamfolder/exercises/exercise01/example_blink/example_blink.ino)

### Pictures
<img src="/Teamfolder/pictures/exercise01/example_blink_picture_1.jpg" alt="drawing" width="300"/> <img src="/Teamfolder/pictures/exercise01/example_blink_picture_2.jpg" alt="drawing" width="300"/>

## Control an ESP8266 from another ESP8266 via WLAN
In this little project we wanted to make a server (ESP8266) which only toggles a LED when a special event occurs. That event is the click of a button on another ESP8266.
These two ESP8266s are connected via WLAN.

### Client - ESP8266 with a button which talks to another ESP8266
This is our client which connects to the WLAN from our Raspberry Pi and also connects to the second ESP8266 via its IP address and sends a HTTP GET to it when the button is pressed.

#### How to begin
1. File > New
1. Tools > Board > LOLIN(WEMOS) D1 R2 & mini
3. Connect the cables between the ESP8266 and the button
	- black cable of the button to the ground (G) of the ESP8266
	- yellow cable of the button to D6 connector of the ESP8266
	- red cable of the button to the 3V connector of the ESP8266
2. Write the code
3. Verify the program
4. Upload File to ESP8266

#### Code for the client
Here you can find the code for the client -> [client_button.ino](/Teamfolder/exercises/exercise01/client_button/client_button.ino)

#### Pictures
<img src="/Teamfolder/pictures/exercise01/client_button_picture_1.jpg" alt="drawing" width="300"/> <img src="/Teamfolder/pictures/exercise01/client_button_picture_2.jpg" alt="drawing" width="300"/>

### Server - ESP8266 with a LED which is switched on/off from the client
...

## Problems
In the first Lab we had problems especially with the micro USB cables. Some of our cables did not work and that cost us time.
