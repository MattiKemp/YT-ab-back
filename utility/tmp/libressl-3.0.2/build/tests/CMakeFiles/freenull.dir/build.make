# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/freenull.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/freenull.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/freenull.dir/flags.make

tests/CMakeFiles/freenull.dir/freenull.c.o: tests/CMakeFiles/freenull.dir/flags.make
tests/CMakeFiles/freenull.dir/freenull.c.o: ../tests/freenull.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/freenull.dir/freenull.c.o"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/freenull.dir/freenull.c.o   -c /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/freenull.c

tests/CMakeFiles/freenull.dir/freenull.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/freenull.dir/freenull.c.i"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/freenull.c > CMakeFiles/freenull.dir/freenull.c.i

tests/CMakeFiles/freenull.dir/freenull.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/freenull.dir/freenull.c.s"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/freenull.c -o CMakeFiles/freenull.dir/freenull.c.s

# Object files for target freenull
freenull_OBJECTS = \
"CMakeFiles/freenull.dir/freenull.c.o"

# External object files for target freenull
freenull_EXTERNAL_OBJECTS =

tests/freenull: tests/CMakeFiles/freenull.dir/freenull.c.o
tests/freenull: tests/CMakeFiles/freenull.dir/build.make
tests/freenull: tls/libtls.a
tests/freenull: ssl/libssl.a
tests/freenull: crypto/libcrypto.a
tests/freenull: tests/CMakeFiles/freenull.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable freenull"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/freenull.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/freenull.dir/build: tests/freenull

.PHONY : tests/CMakeFiles/freenull.dir/build

tests/CMakeFiles/freenull.dir/clean:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/freenull.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/freenull.dir/clean

tests/CMakeFiles/freenull.dir/depend:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2 /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests/CMakeFiles/freenull.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/freenull.dir/depend
