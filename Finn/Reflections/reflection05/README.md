# Reflection 05

## Lecture reflection

### Introduction questions
We had to answer these questions during the lecture:

-   What will be issues scaling (system size, number of systems,management)?
    - Bigger deployment
    - Documentation is harder to update
    - More systems, is bigger privacy/security threat
    - Finding bugs 

- How can we do testing?
    - Simulation environment
    - Integration testing
    - With user stories

-  What would you like to see for scaling up? (What is not so great currently?)

    - An easy-to-read log

-  What role will play
    - Simulator(-component)s? -> Testing
    - MQTT -> integration
    - Stories? -> base for testing

### IoTEmpower
IoTEmpower is an open-source and cloud-based platform designed to simplify and streamline the development and management of IoT applications and devices. IoT Empower offers features such as device management, data visualization, analytics, and remote monitoring.It aims to empower users to create, deploy, and manage IoT projects efficiently while benefiting from the scalability of a cloud-based solution.

#### Tools

#### Documentation
The documentation tab from IoTEmpower contains a lot of sensor/actuators that can be used by adding 1 or 2 lines into the setup.cpp from your own node. It provides example code for multiple microcontrollers and also the explanation of each variable that is used.

## Lab reflection
In this lab we made the following tasks:

### 1. First & Second node
At first we had to do the "First Node" assignment. The idea was to create and test a node with IoTEmpower. It was just creating a new node folder, selecting the board, adding an LED, and initializing the project on the board. Then we tested it by looking at the MQTT topics to see if the simulated LED worked. It did.

The second node assignemnt required us to use a second node, and use a button on that node to turn on the builtin LED from the first node. The idea was to have a simulated button, but we used a physical one. The steps for this were easy, just creating a second node with button input. And then using node-red to hook the button input to the LED output using the MQTT topics.

These two tasks were relatively easy, it was just about getting the hang of IoTEmpower.

[First & Second node](/Teamfolder/Group1/exercises/exercise05/README.md#first-node)

### 2. Button to Audio
Since we already hooked up a button since last assignment, we reused that and used the button input on the MQTT topic, to trigger the "audio out" node from the dashboard library. 

[Button to Audio](/Teamfolder/Group1/exercises/exercise05/README.md#button-to-sound-and-notification)

### 3. OLED screen
Adding an OLED screen to the project wasn't difficult. The idea was to just send some text to an OLED screen using MQTT. We added the OLED screen into the "setup.cpp" and on node-red we used dashboard text input and hooked it up to the MQTT topic from the OLED screen.

Tasks 2 and 3 were very simple if you finished the first/second node tasks. I did enjoy using a different platform for once on IoT solutions. Although I very much love programming it myself from scratch. Maybe one day I will write my own platform to support multiple drivers.

[OLED screen](/Teamfolder/Group1/exercises/exercise05/README.md#text-receiver)




