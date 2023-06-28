# Install script for directory: /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mqtt" TYPE FILE FILES
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/async_client.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/buffer_ref.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/buffer_view.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/callback.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/client.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/connect_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/create_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/delivery_token.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/disconnect_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/exception.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/iaction_listener.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/iasync_client.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/iclient_persistence.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/message.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/properties.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/response_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/server_response.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/ssl_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/string_collection.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/subscribe_options.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/thread_queue.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/token.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/topic.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/types.h"
    "/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/mqtt/will_options.h"
    )
endif()

