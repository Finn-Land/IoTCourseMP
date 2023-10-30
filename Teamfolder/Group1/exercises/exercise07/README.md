# Exercise 07


## Project idea

We worked as a group to discuss what we want to make, and what we need for our final project. In the end we came up with the following

- RFID Scanner
- Two M5's
- RGB-LED
- OLED screen
- Buzzer

**Modules:**

**First module**

The first module is the RFID reader that checks the if a tag has access to the system.

**Second module** 

This is the sort of an access control system. It's similar to the one we did in the group project exercise. So we'll have an ESP32 with a buzzer, an RGB LED and an OLED screen. 

When somebody scans the tag on the RFID reader it will check if it's the right tag, if it is the LED will turn green and the OLED screen will display "Access Granted". If the wrong tag get's scanned the Led will turn red, the OLED will display "Access Denied", and the buzzer will sound an alarm.

**Second module** 

The third module is one M5. This one will be used as a gesture recognizer to make an LED light up. So when the M5 is moved fast to the right an LED will light up to indicate it working.

**The fourth module**

The fourth module is the other M5. This will receive a call on it's display when the other M5 moves in a certain direction.


