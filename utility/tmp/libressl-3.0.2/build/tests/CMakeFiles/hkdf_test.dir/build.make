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
include tests/CMakeFiles/hkdf_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/hkdf_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/hkdf_test.dir/flags.make

tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.o: tests/CMakeFiles/hkdf_test.dir/flags.make
tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.o: ../tests/hkdf_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.o"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hkdf_test.dir/hkdf_test.c.o   -c /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/hkdf_test.c

tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hkdf_test.dir/hkdf_test.c.i"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/hkdf_test.c > CMakeFiles/hkdf_test.dir/hkdf_test.c.i

tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hkdf_test.dir/hkdf_test.c.s"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests/hkdf_test.c -o CMakeFiles/hkdf_test.dir/hkdf_test.c.s

# Object files for target hkdf_test
hkdf_test_OBJECTS = \
"CMakeFiles/hkdf_test.dir/hkdf_test.c.o"

# External object files for target hkdf_test
hkdf_test_EXTERNAL_OBJECTS =

tests/hkdf_test: tests/CMakeFiles/hkdf_test.dir/hkdf_test.c.o
tests/hkdf_test: tests/CMakeFiles/hkdf_test.dir/build.make
tests/hkdf_test: tls/libtls.a
tests/hkdf_test: ssl/libssl.a
tests/hkdf_test: crypto/libcrypto.a
tests/hkdf_test: tests/CMakeFiles/hkdf_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hkdf_test"
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hkdf_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/hkdf_test.dir/build: tests/hkdf_test

.PHONY : tests/CMakeFiles/hkdf_test.dir/build

tests/CMakeFiles/hkdf_test.dir/clean:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/hkdf_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/hkdf_test.dir/clean

tests/CMakeFiles/hkdf_test.dir/depend:
	cd /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2 /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests /home/adblock/adblock-dev/YT-ab-back/utility/tmp/libressl-3.0.2/build/tests/CMakeFiles/hkdf_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/hkdf_test.dir/depend

