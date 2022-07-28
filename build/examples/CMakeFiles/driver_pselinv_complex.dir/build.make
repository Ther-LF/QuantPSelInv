# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/therlf/pexsi_v2.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/therlf/pexsi_v2.0.0/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/driver_pselinv_complex.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/driver_pselinv_complex.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/driver_pselinv_complex.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/driver_pselinv_complex.dir/flags.make

examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o: examples/CMakeFiles/driver_pselinv_complex.dir/flags.make
examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o: ../examples/driver_pselinv_complex.c
examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o: examples/CMakeFiles/driver_pselinv_complex.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/therlf/pexsi_v2.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o"
	cd /home/therlf/pexsi_v2.0.0/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o -MF CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o.d -o CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o -c /home/therlf/pexsi_v2.0.0/examples/driver_pselinv_complex.c

examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.i"
	cd /home/therlf/pexsi_v2.0.0/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/therlf/pexsi_v2.0.0/examples/driver_pselinv_complex.c > CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.i

examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.s"
	cd /home/therlf/pexsi_v2.0.0/build/examples && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/therlf/pexsi_v2.0.0/examples/driver_pselinv_complex.c -o CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.s

# Object files for target driver_pselinv_complex
driver_pselinv_complex_OBJECTS = \
"CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o"

# External object files for target driver_pselinv_complex
driver_pselinv_complex_EXTERNAL_OBJECTS =

examples/driver_pselinv_complex: examples/CMakeFiles/driver_pselinv_complex.dir/driver_pselinv_complex.c.o
examples/driver_pselinv_complex: examples/CMakeFiles/driver_pselinv_complex.dir/build.make
examples/driver_pselinv_complex: src/libpexsi.a
examples/driver_pselinv_complex: /usr/lib/x86_64-linux-gnu/libmpichcxx.so
examples/driver_pselinv_complex: /usr/lib/x86_64-linux-gnu/libmpichfort.so
examples/driver_pselinv_complex: /home/therlf/Software/SuperLU_DIST_install/lib/libsuperlu_dist.a
examples/driver_pselinv_complex: /usr/lib/x86_64-linux-gnu/libmpich.so
examples/driver_pselinv_complex: /home/therlf/parmetis-4.0.3/lib/libparmetis.a
examples/driver_pselinv_complex: /home/therlf/parmetis-4.0.3/lib/libmetis.a
examples/driver_pselinv_complex: /usr/lib/x86_64-linux-gnu/liblapack.so
examples/driver_pselinv_complex: /usr/lib/x86_64-linux-gnu/libblas.so
examples/driver_pselinv_complex: examples/CMakeFiles/driver_pselinv_complex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/therlf/pexsi_v2.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable driver_pselinv_complex"
	cd /home/therlf/pexsi_v2.0.0/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/driver_pselinv_complex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/driver_pselinv_complex.dir/build: examples/driver_pselinv_complex
.PHONY : examples/CMakeFiles/driver_pselinv_complex.dir/build

examples/CMakeFiles/driver_pselinv_complex.dir/clean:
	cd /home/therlf/pexsi_v2.0.0/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/driver_pselinv_complex.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/driver_pselinv_complex.dir/clean

examples/CMakeFiles/driver_pselinv_complex.dir/depend:
	cd /home/therlf/pexsi_v2.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/therlf/pexsi_v2.0.0 /home/therlf/pexsi_v2.0.0/examples /home/therlf/pexsi_v2.0.0/build /home/therlf/pexsi_v2.0.0/build/examples /home/therlf/pexsi_v2.0.0/build/examples/CMakeFiles/driver_pselinv_complex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/driver_pselinv_complex.dir/depend

