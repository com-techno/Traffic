# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug

# Include any dependencies generated for this target.
include example/CMakeFiles/blink.dir/depend.make

# Include the progress variables for this target.
include example/CMakeFiles/blink.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/blink.dir/flags.make

example/CMakeFiles/blink.dir/blink.cpp.obj: example/CMakeFiles/blink.dir/flags.make
example/CMakeFiles/blink.dir/blink.cpp.obj: ../example/blink.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/blink.dir/blink.cpp.obj"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\blink.dir\blink.cpp.obj -c C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\example\blink.cpp

example/CMakeFiles/blink.dir/blink.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blink.dir/blink.cpp.i"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\example\blink.cpp > CMakeFiles\blink.dir\blink.cpp.i

example/CMakeFiles/blink.dir/blink.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blink.dir/blink.cpp.s"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && C:\PROGRA~2\Arduino\hardware\tools\avr\bin\AVR-G_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\example\blink.cpp -o CMakeFiles\blink.dir\blink.cpp.s

# Object files for target blink
blink_OBJECTS = \
"CMakeFiles/blink.dir/blink.cpp.obj"

# External object files for target blink
blink_EXTERNAL_OBJECTS =

example/blink.elf: example/CMakeFiles/blink.dir/blink.cpp.obj
example/blink.elf: example/CMakeFiles/blink.dir/build.make
example/blink.elf: example/libuno_example.a
example/blink.elf: example/libuno_CORE.a
example/blink.elf: example/libblink_lib.a
example/blink.elf: example/libuno_example.a
example/blink.elf: example/libuno_CORE.a
example/blink.elf: example/CMakeFiles/blink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable blink.elf"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\blink.dir\link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating EEP image"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && "C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avr-objcopy.exe" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.elf C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.eep
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating HEX image"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && "C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avr-objcopy.exe" -O ihex -R .eeprom C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.elf C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Calculating image size"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe" -DFIRMWARE_IMAGE=C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.elf -DMCU=atmega328p -DEEPROM_IMAGE=C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/example/blink.eep -P C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/CMakeFiles/FirmwareSize.cmake

# Rule to build all files generated by this target.
example/CMakeFiles/blink.dir/build: example/blink.elf

.PHONY : example/CMakeFiles/blink.dir/build

example/CMakeFiles/blink.dir/clean:
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example && $(CMAKE_COMMAND) -P CMakeFiles\blink.dir\cmake_clean.cmake
.PHONY : example/CMakeFiles/blink.dir/clean

example/CMakeFiles/blink.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\example C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\example\CMakeFiles\blink.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/blink.dir/depend

