# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build

# Include any dependencies generated for this target.
include src/samples/CMakeFiles/async_consume.dir/depend.make

# Include the progress variables for this target.
include src/samples/CMakeFiles/async_consume.dir/progress.make

# Include the compile flags for this target's objects.
include src/samples/CMakeFiles/async_consume.dir/flags.make

src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.o: src/samples/CMakeFiles/async_consume.dir/flags.make
src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.o: ../src/samples/async_consume.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.o"
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/async_consume.dir/async_consume.cpp.o -c /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/samples/async_consume.cpp

src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_consume.dir/async_consume.cpp.i"
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/samples/async_consume.cpp > CMakeFiles/async_consume.dir/async_consume.cpp.i

src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_consume.dir/async_consume.cpp.s"
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/samples/async_consume.cpp -o CMakeFiles/async_consume.dir/async_consume.cpp.s

# Object files for target async_consume
async_consume_OBJECTS = \
"CMakeFiles/async_consume.dir/async_consume.cpp.o"

# External object files for target async_consume
async_consume_EXTERNAL_OBJECTS =

src/samples/async_consume: src/samples/CMakeFiles/async_consume.dir/async_consume.cpp.o
src/samples/async_consume: src/samples/CMakeFiles/async_consume.dir/build.make
src/samples/async_consume: src/libpaho-mqttpp3.so.1.2.0
src/samples/async_consume: /usr/local/lib/libpaho-mqtt3a.so
src/samples/async_consume: src/samples/CMakeFiles/async_consume.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable async_consume"
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/async_consume.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/samples/CMakeFiles/async_consume.dir/build: src/samples/async_consume

.PHONY : src/samples/CMakeFiles/async_consume.dir/build

src/samples/CMakeFiles/async_consume.dir/clean:
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples && $(CMAKE_COMMAND) -P CMakeFiles/async_consume.dir/cmake_clean.cmake
.PHONY : src/samples/CMakeFiles/async_consume.dir/clean

src/samples/CMakeFiles/async_consume.dir/depend:
	cd /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0 /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/src/samples /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples /mnt/h/mqtt2exec/paho.mqtt.cpp-1.2.0/build/src/samples/CMakeFiles/async_consume.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/samples/CMakeFiles/async_consume.dir/depend

