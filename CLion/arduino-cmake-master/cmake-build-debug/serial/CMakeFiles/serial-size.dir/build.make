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

# Utility rule file for serial-size.

# Include the progress variables for this target.
include serial/CMakeFiles/serial-size.dir/progress.make

serial/CMakeFiles/serial-size: serial/serial.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Calculating serial image size"
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\serial && "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe" -DFIRMWARE_IMAGE=C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/serial/serial.elf -DMCU=atmega2560 -DEEPROM_IMAGE=C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/serial/serial.eep -P C:/Users/Sinyavsk/CLionProjects/arduino-cmake-master/cmake-build-debug/CMakeFiles/FirmwareSize.cmake

serial-size: serial/CMakeFiles/serial-size
serial-size: serial/CMakeFiles/serial-size.dir/build.make

.PHONY : serial-size

# Rule to build all files generated by this target.
serial/CMakeFiles/serial-size.dir/build: serial-size

.PHONY : serial/CMakeFiles/serial-size.dir/build

serial/CMakeFiles/serial-size.dir/clean:
	cd /d C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\serial && $(CMAKE_COMMAND) -P CMakeFiles\serial-size.dir\cmake_clean.cmake
.PHONY : serial/CMakeFiles/serial-size.dir/clean

serial/CMakeFiles/serial-size.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\serial C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\serial C:\Users\Sinyavsk\CLionProjects\arduino-cmake-master\cmake-build-debug\serial\CMakeFiles\serial-size.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : serial/CMakeFiles/serial-size.dir/depend

