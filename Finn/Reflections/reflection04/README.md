# Reflection 04

## Lecture reflection
The lecture today was about using node-red. I have a lot of experience with node-red before this day. 

## Lab reflection
For this lab the idea was to create the following tasks:

### 1. AC Simulation in Node-Red

We did this task the day before already, since we made the original simulation in Node-red because it's more efficient work and more intuitive.

### 2. Discord emergency button

This task required us to create a discord bot, this bot was placed into the server channel "sandbox". For the button we reused the code from the original button that we had, the toggle example. We use that example code to send a 1 or 0 depending if it was pressed or not. 

The input from the button goes to node-red, in node-red we send a message based on the input to discord. This message then gets placed into the "sandbox" channel.

### 3. Discord to Node-red audio
The second part with discord was for us to put a message into the discord manually, and this message then gets send to node-red which sends it to an MQTT topic that turns a light on, the message also gets played as an audio output.