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
include tests/CMakeFiles/valid_handshakes_terminate.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/valid_handshakes_terminate.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/valid_handshakes_terminate.dir/flags.make

tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o: tests/CMakeFiles/valid_handshakes_terminate.dir/flags.make
tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o: ../tests/valid_handshakes_terminate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o   -c /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/valid_handshakes_terminate.c

tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.i"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/valid_handshakes_terminate.c > CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.i

tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.s"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/valid_handshakes_terminate.c -o CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.s

# Object files for target valid_handshakes_terminate
valid_handshakes_terminate_OBJECTS = \
"CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o"

# External object files for target valid_handshakes_terminate
valid_handshakes_terminate_EXTERNAL_OBJECTS =

tests/valid_handshakes_terminate: tests/CMakeFiles/valid_handshakes_terminate.dir/valid_handshakes_terminate.c.o
tests/valid_handshakes_terminate: tests/CMakeFiles/valid_handshakes_terminate.dir/build.make
tests/valid_handshakes_terminate: tls/libtls.a
tests/valid_handshakes_terminate: ssl/libssl.a
tests/valid_handshakes_terminate: crypto/libcrypto.a
tests/valid_handshakes_terminate: tests/CMakeFiles/valid_handshakes_terminate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable valid_handshakes_terminate"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/valid_handshakes_terminate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/valid_handshakes_terminate.dir/build: tests/valid_handshakes_terminate

.PHONY : tests/CMakeFiles/valid_handshakes_terminate.dir/build

tests/CMakeFiles/valid_handshakes_terminate.dir/clean:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/valid_handshakes_terminate.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/valid_handshakes_terminate.dir/clean

tests/CMakeFiles/valid_handshakes_terminate.dir/depend:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2 /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests/CMakeFiles/valid_handshakes_terminate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/valid_handshakes_terminate.dir/depend

