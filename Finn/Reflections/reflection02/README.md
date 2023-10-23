# Reflection day 2

## Overview
1. [Lecture reflection](/Finn/Reflections/reflection02/README.md#lecture-reflection)
2. [Lab reflection](/Finn/Reflections/reflection02/README.md#lab-reflection)
    - [Raspberry pi](/Finn/Reflections/reflection02/README.md#setting-up-raspberry-pi)
    - [Control LED with web request](/Finn/Reflections/reflection02/README.md#control-led-with-web-request)
    - [Button for web request](/Finn/Reflections/reflection02/README.md#button-for-web-request)

## Lecture reflection
The first lecture of this module was the introduction to IoT. Having worked with IoT before and embedded systems, I found it to be quite refreshing. On this day I did feel quite bad, I had food poisoning and had to puke several times, hence why I left the classroom during an explanation. The lecture went through an explanation on IoT, some IoT domains, microcontrollers used and protocol examples. We also talked about the advantages/disadvantages that are present within the IoT field. 

## Lab reflection

### Setting up Raspberry PI
In order to set up our raspberry pi we first have to flash an SD card with a suitable rapsberry pi image. We got the image from the lecturer, we flashed this using a program called balenaEtcher. I have used this in the past before, it's easy to use but you can also the raspberry pi image flasher.

### Control LED with web request

1. Set up server on Wemos
2. Set up client on ESP32
3. Send HTTP command to turn on LED
4. Led turns on

### Button for web request
**Blink with web request:**
The first step here was to code the client to make the LED from the server ESP blink with a one second delay. This didn't take too long but we accidently switched the server and client

The second assignment was to use a button on the client side to toggle the LED on the server side. We reused the code from Monday to toggle the LED. 

