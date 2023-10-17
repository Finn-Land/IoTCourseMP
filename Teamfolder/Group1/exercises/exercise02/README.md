# Exercise 02
For the first exercise we wrote three small Arduino programs.

## Overview
1. [Preparation](/Teamfolder/Group1/exercises/exercise02/README.md#preparation)
2. [Control Led with Web Request](/Teamfolder/Group1/exercises/exercise02/README.md#control-led-with-web-request)
	- [How to begin](/Teamfolder/Group1/exercises/exercise02/README.md#how-to-begin)
	- [Code](/Teamfolder/Group1/exercises/exercise02/README.md#code)
	- [Pictures](/Teamfolder/Group1/exercises/exercise02/README.md#pictures)
3. [Use a Button to Create Web Request](/Teamfolder/Group1/exercises/exercise02/README.md#use-a-button-to-create-web-request)
	- [Client](/Teamfolder/Group1/exercises/exercise02/README.md#client)
		- [How to begin](/Teamfolder/Group1/exercises/exercise02/README.md#how-to-begin-1)
		- [Code](/Teamfolder/Group1/exercises/exercise02/README.md#code-1)
		- [Pictures](/Teamfolder/Group1/exercises/exercise02/README.md#pictures-1)
	- [Server](/Teamfolder/Group1/exercises/exercise02/README.md#server)
		- [How to begin](/Teamfolder/Group1/exercises/exercise02/README.md#how-to-begin-2)
		- [Code](/Teamfolder/Group1/exercises/exercise02/README.md#code-2)
		- [Pictures](/Teamfolder/Group1/exercises/exercise02/README.md#pictures-2)




## Preparation
Before we could start doing the first little example, we had to setup our Raspberry Pi.
3. We downloaded the image for the Raspberry Pi from https://github.com/iotempire/iotempower/blob/master/doc/image-pi.rst
4. We checked the checksum with the tool from https://raylin.wordpress.com/downloads/md5-sha-1-checksum-utility/
5. We downloaded etcher from https://www.balena.io/etcher/
6. We flashed the image to the Raspberry Pi with etcher and validate it
7. In wifi.txt we changed the WiFi name and password and removed '#' from the WiFi name line
8. We connected the Raspberry Pi to the network via Ethernet cable and powered it up

## Control Led with Web Request
For this small example we created an Arduino program which makes the onboard LED of the ESP32 change it's state depending on the IP we go to.

### How to begin
1. File > New
2. Tools > Board > ESP32 DEV MODULE
3. Write the code
4. Verify the program
5. Upload File to ESP32

### Code
Here you can find the code -> [web_request.ino](/Teamfolder/Group1/exercises/exercise02/Control_LED_with_web_request/)

### Pictures
Pictures and videos can be found in teh following folder:
[Pictures](/Teamfolder/Group1/pictures/exercise02/Control_LED_with_web_request/)

## Use a Button to Create Web Request
In this project we use 2 ESP32, one as a server and one as a client, to change the state of the builtin led.

### Client

#### How to begin
1. File > New
1. Tools > Board > ESP32 DEV MODULE
3. Connect the cables between the ESP32
2. Write the code
3. Verify the program
4. Upload File to ESP32

#### Code
Here you can find the code for the client -> [client_button.ino](/Teamfolder/Group1/exercises/exercise02/Button_to_create_web_request_1/)

#### Pictures
Pictures and videos can be found in teh following folder:
[Pictures](/Teamfolder/Group1/pictures/exercise02/Button_to_create_web_request_1/)

### Server

#### How to begin
1. File > New
1. Tools > Board > WEMOS D1 MINI ESP32
3. Connect the cables between the MINI ESP32
2. Write the code
3. Verify the program
4. Upload File to MINI ESP32

#### Code
Here you can find the code for the client -> [client_button.ino](/Teamfolder/Group1/exercises/exercise02/Button_to_create_web_request_1/)

#### Pictures
Pictures and videos can be found in teh following folder:
[Pictures](/Teamfolder/Group1/pictures/exercise02/Button_to_create_web_request_1/)


