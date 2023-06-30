# mqtt2exec

A library for executing commands (e.g. system commands) using the MQTT protocol.

TODO


# Compile example

1. After repository clone run "git submodule update --init --recursive" command
2. Build and install paho.mqtt.c library (instructions in submodule)
3. Build and install paho.mqtt.cpp library (instructions in submodule)
4. Use this command to build executable file: g++ example/main.cpp mqtt2exec.cpp -o mqtt2exec.out -lpaho-mqttpp3 -lpaho-mqtt3as