
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

After that, we wired the OLED shield to another ESP32. Flashed the node "Vin_ste_N2". The setup.cpp has the lines:

	U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0); // R0 no rotation, R1 - 90°
	display(oled, u8g2, font_tiny);

To lock it, we wired the relay and solenoid drawer lock to yet another ESP32 and created a new node called "GROUP PROJECT P2" and modified the setup.cpp, adding:

	output(Lock, D1, "open", "close");

We flashed it to the ESP32.

After all that, we created a node-red flow that reads the topic from the RFID reader, after that, the payload goes to a switch to see whether the card is valid or not.

If the access is granted, we change the payload to "on" and inizialice 3 triggers of 5 seconds, one for the yellow LED to turn off, one for the green LED to turn on, and one for the relay to unlock the lock.

If acces is not granted, we change the payload to "off" and inizialice 3 triggers of 5 seconds, one for the yellow LED to turn off, one for the red LED to turn on, and one for the buzzer to annoy everyone.

In both cases, we go to another switch and depending on the payload send a message on the OLED topic to show during 2 seconds whether the access is granted or not.

### How to begin
1. Wire LEDs and Buzzer to ESP32 (one)
2. Creat node "GROUP PROJECT" and modify setup.cpp
3. Flash ESP32 (one)
4. Wire RFID Reader to ESP8266 
5. Flash ESP8266 with node "RFID_Vin_ste"
6. Wire OLED shield to ESP32 (two)
7. Modify setup.cpp of node "GROUP PROJECT"
8. Flash ESP32 (two) with node "Vin_ste_N2" 
9. Wire relay and solenoid drawer lock to ESP32 (three)
10. Creat node "GROUP PROJECT 2" and modify setup.cpp
11. Flash ESP32 (three)
12. Create node-red flow
13. Check if it works

### Simulation Flow
Here you can find the node-red flow -> [Compact JSON](/Teamfolder/exercises/)

### Pictures
Here you can find a picture -> [Picture](/Teamfolder/pictures/)

<img src="../pictures/node flow.png" width="auto" />

