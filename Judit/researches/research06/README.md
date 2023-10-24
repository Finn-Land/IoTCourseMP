# Research records 06

## Contents
1. [IoT Project](#iot-project)
2. [User Stories Updated](#user-stories-updated)
3. [System in folders](#system-in-folders)
    - [Which topic needs to be called with what to:](#which-topic-needs-to-be-called-with-what-to)
    - [What is the general rule for forming topics in IoTempower?](#what-is-the-general-rule-for-forming-topics-in-iotempower)
    - [When does it make sense to change something in system.conf?](#when-does-it-make-sense-to-change-something-in-systemconf)
    - [What role does the location of system.conf play? (What if it would be one level higher and there is also yourhouse?)](#what-role-does-the-location-of-systemconf-play-what-if-it-would-be-one-level-higher-and-there-is-also-yourhouse)
4. [Nodes](#nodes)
    - [What needs to/can go into node.conf?](#what-needs-tocan-go-into-nodeconf)
    - [How do [optional config.txt,] etc/iotempower.conf, system.conf, and node.conf influence environment variables for compiling?](#how-do-optional-configtxt-etciotempowerconf-systemconf-and-nodeconf-influence-environment-variables-for-compiling)
5. [Compilation](#compilation)
    - [What types of deploy are there?](#what-types-of-deploy-are-there)
    - [Why can only one deploy run at once?](#why-can-only-one-deploy-run-at-once)
6. [Filters](#filters)
    - [What is a common problem when we measure?](#what-is-a-common-problem-when-we-measure)
    - [What are filters and how do they work (in Node-Red and IoTempower)?](#what-are-filters-and-how-do-they-work-in-node-red-and-iotempower)
    - [What is offered and what other generic filters would be nice?](#what-is-offered-and-what-other-generic-filters-would-be-nice)
    - [What is the “fluent” style?](#what-is-the-fluent-style)
7. [Lab](#lab)

## IoT Project
Fist thing we did today was discuss our IoT project with Ulrich. 

We ended up deciding to use a gyroscope in one hand and a deviced somehow like a smartwatch on the other. When doing a specific movement with the gyroscope, it sends a topic to someone else's watch, which vibrates and displays a message. After pressing a button on the watch, this sends a topic to the first person's watch and vibrates.

## User Stories Updated
After that, we created a new user scenario related with our project. To do that, I asked my teamates some questions about the idea we talked with Ulno, trying to make them think about details like "how does our user call a specific person" and "how does this really relate with our translating site". They were not able to answer me, so I just decided those answers on my own.
Update stories

## System in folders
### Which topic needs to be called with what to:
- **switch on the coffee machine?**

        myhouse/kitchen/coffee-machine/switch/set on

- **set all lights in living room to blue?**

        living_room/led1/rgb/set 0000FF
        living_room/led2/rgb/set 0000FF


- **turn the main power off?**

        myhouse/main/switch/set off


### What is the general rule for forming topics in IoTempower?

Hierarchy: system -> folders -> device name -> device subtopics

### When does it make sense to change something in system.conf?

When you want to add more settings or to change a specific thing. In the system.conf goes all the configuration.
        
### What role does the location of system.conf play? (What if it would be one level higher and there is also yourhouse?)

In that folder, system.conf applies to every folder inside. It has to be in the root of the topics.

If it was on a higher level it would also apply to other folders.

## Nodes
### What needs to/can go into node.conf?
All the configuration for a single node of a IoTempower system. We understand every network node or thing of the internet as a node.
Several devices (actors and sensors) can be connected to one node. 
The microcontroller.
Note: everything on the node.conf can go to setuo.conf or any other file.


### How do [optional config.txt,] etc/iotempower.conf, system.conf, and node.conf influence environment variables for compiling?
set or override environment variables, system settings, and application parameters. These files can greatly influence the behavior of the software or firmware that is being compiled or executed.

- **config.txt:**
       
    Modify when you have global settings that affect the entire system or multiple components.

- **iotempower.conf:** 
        
    modify this file when you're dealing with IoT-specific configurations, especially those that influence how your device connects or interacts with other devices.
- **system.conf:** 
        
    modify this file when you need to adjust system-level settings or behaviors.
- **node.conf:** 

    modify this when you're adjusting settings for specific devices or nodes in your IoT setup.


## Compilation

### What types of deploy are there?
Initialize serial: needs to be done via the RaspberryPi.

Deploy: can be done via internet, just one at the time.

### Why can only one deploy run at once?
We can only run one deploy at the time because parallel deployment makes it crash.

## Filters
### What is a common problem when we measure?
There is a lot of traffic on the network, a lot of devices sending means a lot of data collisions, which leads to loosing data.
### How can we do graphs in node-red?
Dashboard.
### What are filters and how do they work (in Node-Red and IoTempower)?
Conceptually it is the same.
In node-red you have different nodes, in IoTempower you have different chains.
In node-red:
You use funcitons like "filters" and "switch".
In IoTempower:
You use fluent style to change the filters.
### What is offered and what other generic filters would be nice?
Average, jmz_interval_median, round, time_filter, binarize and others.
### What is the “fluent” style?
Putting everything in one line.

## Lab
Activities can be found in the Group1 folder: 
[Activities](/Teamfolder/Group1/exercises/exercise06/README.md)