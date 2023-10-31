## Reflection 08

### Lecture reflection

On this day we had no lectures as well. We had a discussion in the group about the project work in relation with the remaining lectures. During this the fire alarm went off and we had to go outside.

When we went back in we discussed some more, and then we got a guest lecture from somebody that worked at the Bosch IoT group. He talked about his experiences and what he achieved during his time there. Since a year ago he has been working as a teacher, which he enjoys more.

### Lab reflection


#### Touch sensor

#### Moisture sensor

#### Project work
I worked on the alarm module. So we have an ESP32 that has an RGB LED and a buzzer. This ESP32 connects to WiFi, to MQTT and then communicates using Node-Red. The RGB LED can be changed using the topics for every RGB value. Topis that we use are: 

    magnusp/rgb/red
    magnusp/rgb/green
    magnusp/rgb/blue
Every color can be changed be just inputting a value from 0-255 into the topic, and then the LED will change color based on the new value.

The buzzer can be operated using:

    magnusp/buzzer/on
    magnusp/buzzer/off
The program as the ones before uses OOP, which makes the code a lot more read-able and easy to understand.