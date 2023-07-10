# mqtt2exec

A library for executing commands (e.g. system commands) using the MQTT protocol. You can send command to MQTT topic and execute action on device connected to that MQTT broker.
Tested on PC with `Debian GNU/Linux 10 (buster)` and Raspberry Pi Zero 2 W with `Raspbian GNU/Linux 11 (bullseye)`.

# Example diagram

![Example diagram](https://raw.githubusercontent.com/lnarolski/mqtt2exec/main/ExampleDiagram.png)

# Build example
1. Clone repository
2. Run `git submodule update --init --recursive` command in repository directory
3. Build and install paho.mqtt.c library (instructions in submodule README file)
4. Build and install paho.mqtt.cpp library (instructions in submodule README file)
5. To build example:
	- Install g++ `sudo apt-get update; sudo apt-get install g++ -y`
	- Use `g++ example/main.cpp mqtt2exec.cpp -o mqtt2exec.out -lpaho-mqttpp3 -lpaho-mqtt3as` command in repository directory to create `mqtt2exec.out` binary file

# Context
[narolski.eu](https://narolski.eu/2023/07/07/spacecraft/)
