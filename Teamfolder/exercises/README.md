
## Project 1
In this activity, we need to build an access control system using the previous activities. We need an RFID reader, three LEDs, the buzzer, the display and a relay with the solenoid drawer lock. 

We need to show the access status on the LEDs. When access is granted, green light is on  and lock open (locking again after a short time). When access is denied, red light and nasty noise.

In order to do that, we are using 1 ESP8266 and 3 ESP32.

First wire the three LEDs we have been given to the ESP32, along with the buzzer. 

Then we created a new node called "GROUP PROJECT". There, we modify the setup.cpp
file, adding:

	led(green, 32, "on", "off");
	led(red, 27, "on", "off");
	led(yellow, 25, "on", "off");
	pwm(pwm, 4);

We then flashed the ESP32.

On the same time, the other part of the group wired the RFID reader to the ESP8266, and flashed the node "RFID_Vin_ste". The setup.cpp has the lines:

	mfrc522(reader);

After that, we wired the shield to another ESP32. Flashed the node "Vin_ste_N2". The setup.cpp has the lines:

	U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0); // R0 no rotation, R1 - 90°
	display(oled, u8g2, font_tiny);

To lock it, we wired the relay and solenoid dreawer lock to yet another ESP32 and created a new node called "GROUP PROJECT P2" and modified the setup.cpp, adding:

	output(Lock, D1, "open", "close");

We flashed it to the ESP32.

After all that, we created a node-red flow that reads the topic from the RFID reader, after that, the payload goes to a switch to see whether the card is valid or not.

If the access is granted

### How to begin
1. Wire components
2. Modify setup.cpp
3. Flash Wemos D1
4. Create node-red flow
5. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/Group1/exercises/exercise06/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/Group1/pictures/exercise06/)

