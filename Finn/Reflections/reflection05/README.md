# Reflection 05

## Lecture reflection
Questions to think about:

### Introduction questions
- **What will be the issues scaling up (system size, number of systems, management)?** 
    - You would need more MQTT topics. make them more defined.
    - Management is more difficult.
- **How can we do testing?**
    - Divide system into multiple units, test individually, then integrate and test together
- **What would you like to see for scaling up? (what is not so great currently?)**
    - More NODE-RED
    - Data effiency
- **What role will play simulator(-component)s, MQTT and stories?**
    - Simulation plays a big role, first you have to simulate in order to see if the idea is feasible.
    - MQTT would play a big role too, since the topics make it easy to see where which data is going.

## Lab reflection
In this lab we made the following tasks:

### 1. First & Second node

At first we had to do the "First Node" assignment. The idea was to create and test a node with IoTEmpower. It was just creating a new node folder, selecting the board, adding an LED, and initializing the project on the board. Then we tested it by looking at the MQTT topics to see if the simulated LED worked. It did.

The second node assignemnt required us to use a second node, and use a button on that node to turn on the builtin LED from the first node. The idea was to have a simulated button, but we used a physical one. The steps for this were easy, just creating a second node with button input. And then using node-red to hook the button input to the LED output using the MQTT topics.

### 2. Button to Audio
Since we already hooked up a button since last assignemnt, we reused that and used the button input on the MQTT topic, to trigger the "audio out" node from the dashboard library. 

### 3. OLED screen
Adding an OLED screen to the project wasn't difficult. The idea was to just send some text to an OLED screen using MQTT. We added the OLED screen into the "setup.cpp" and on node-red we used dashboard text input and hooked it up to the MQTT topic from the OLED screen.




