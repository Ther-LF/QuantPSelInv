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
include fortran/CMakeFiles/f_driver_pselinv_real.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include fortran/CMakeFiles/f_driver_pselinv_real.dir/compiler_depend.make

# Include the progress variables for this target.
include fortran/CMakeFiles/f_driver_pselinv_real.dir/progress.make

# Include the compile flags for this target's objects.
include fortran/CMakeFiles/f_driver_pselinv_real.dir/flags.make

fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o: fortran/CMakeFiles/f_driver_pselinv_real.dir/flags.make
fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o: ../fortran/f_driver_pselinv_real.f90
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/therlf/pexsi_v2.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building Fortran object fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o"
	cd /home/therlf/pexsi_v2.0.0/build/fortran && /usr/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -c /home/therlf/pexsi_v2.0.0/fortran/f_driver_pselinv_real.f90 -o CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o

fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing Fortran source to CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.i"
	cd /home/therlf/pexsi_v2.0.0/build/fortran && /usr/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -E /home/therlf/pexsi_v2.0.0/fortran/f_driver_pselinv_real.f90 > CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.i

fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling Fortran source to assembly CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.s"
	cd /home/therlf/pexsi_v2.0.0/build/fortran && /usr/bin/gfortran $(Fortran_DEFINES) $(Fortran_INCLUDES) $(Fortran_FLAGS) -S /home/therlf/pexsi_v2.0.0/fortran/f_driver_pselinv_real.f90 -o CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.s

# Object files for target f_driver_pselinv_real
f_driver_pselinv_real_OBJECTS = \
"CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o"

# External object files for target f_driver_pselinv_real
f_driver_pselinv_real_EXTERNAL_OBJECTS =

fortran/f_driver_pselinv_real: fortran/CMakeFiles/f_driver_pselinv_real.dir/f_driver_pselinv_real.f90.o
fortran/f_driver_pselinv_real: fortran/CMakeFiles/f_driver_pselinv_real.dir/build.make
fortran/f_driver_pselinv_real: src/libpexsi.a
fortran/f_driver_pselinv_real: /usr/lib/x86_64-linux-gnu/libmpichcxx.so
fortran/f_driver_pselinv_real: /usr/lib/x86_64-linux-gnu/libmpichfort.so
fortran/f_driver_pselinv_real: /home/therlf/Software/SuperLU_DIST_install/lib/libsuperlu_dist.a
fortran/f_driver_pselinv_real: /usr/lib/x86_64-linux-gnu/libmpich.so
fortran/f_driver_pselinv_real: /home/therlf/parmetis-4.0.3/lib/libparmetis.a
fortran/f_driver_pselinv_real: /home/therlf/parmetis-4.0.3/lib/libmetis.a
fortran/f_driver_pselinv_real: /usr/lib/x86_64-linux-gnu/liblapack.so
fortran/f_driver_pselinv_real: /usr/lib/x86_64-linux-gnu/libblas.so
fortran/f_driver_pselinv_real: fortran/CMakeFiles/f_driver_pselinv_real.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/therlf/pexsi_v2.0.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable f_driver_pselinv_real"
	cd /home/therlf/pexsi_v2.0.0/build/fortran && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f_driver_pselinv_real.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
fortran/CMakeFiles/f_driver_pselinv_real.dir/build: fortran/f_driver_pselinv_real
.PHONY : fortran/CMakeFiles/f_driver_pselinv_real.dir/build

fortran/CMakeFiles/f_driver_pselinv_real.dir/clean:
	cd /home/therlf/pexsi_v2.0.0/build/fortran && $(CMAKE_COMMAND) -P CMakeFiles/f_driver_pselinv_real.dir/cmake_clean.cmake
.PHONY : fortran/CMakeFiles/f_driver_pselinv_real.dir/clean

fortran/CMakeFiles/f_driver_pselinv_real.dir/depend:
	cd /home/therlf/pexsi_v2.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/therlf/pexsi_v2.0.0 /home/therlf/pexsi_v2.0.0/fortran /home/therlf/pexsi_v2.0.0/build /home/therlf/pexsi_v2.0.0/build/fortran /home/therlf/pexsi_v2.0.0/build/fortran/CMakeFiles/f_driver_pselinv_real.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : fortran/CMakeFiles/f_driver_pselinv_real.dir/depend

