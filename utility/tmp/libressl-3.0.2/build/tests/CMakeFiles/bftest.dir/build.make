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
include tests/CMakeFiles/bftest.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/bftest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/bftest.dir/flags.make

tests/CMakeFiles/bftest.dir/bftest.c.o: tests/CMakeFiles/bftest.dir/flags.make
tests/CMakeFiles/bftest.dir/bftest.c.o: ../tests/bftest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/bftest.dir/bftest.c.o"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bftest.dir/bftest.c.o   -c /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/bftest.c

tests/CMakeFiles/bftest.dir/bftest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bftest.dir/bftest.c.i"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/bftest.c > CMakeFiles/bftest.dir/bftest.c.i

tests/CMakeFiles/bftest.dir/bftest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bftest.dir/bftest.c.s"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/bftest.c -o CMakeFiles/bftest.dir/bftest.c.s

# Object files for target bftest
bftest_OBJECTS = \
"CMakeFiles/bftest.dir/bftest.c.o"

# External object files for target bftest
bftest_EXTERNAL_OBJECTS =

tests/bftest: tests/CMakeFiles/bftest.dir/bftest.c.o
tests/bftest: tests/CMakeFiles/bftest.dir/build.make
tests/bftest: tls/libtls.a
tests/bftest: ssl/libssl.a
tests/bftest: crypto/libcrypto.a
tests/bftest: tests/CMakeFiles/bftest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bftest"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bftest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/bftest.dir/build: tests/bftest

.PHONY : tests/CMakeFiles/bftest.dir/build

tests/CMakeFiles/bftest.dir/clean:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/bftest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/bftest.dir/clean

tests/CMakeFiles/bftest.dir/depend:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2 /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests/CMakeFiles/bftest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/bftest.dir/depend

