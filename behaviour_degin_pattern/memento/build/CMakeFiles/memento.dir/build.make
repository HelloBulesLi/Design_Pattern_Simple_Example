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
CMAKE_SOURCE_DIR = /home/libo/Design_Pattern/behaviour_degin_pattern/memento

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/libo/Design_Pattern/behaviour_degin_pattern/memento/build

# Include any dependencies generated for this target.
include CMakeFiles/memento.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/memento.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memento.dir/flags.make

CMakeFiles/memento.dir/memento.cpp.o: CMakeFiles/memento.dir/flags.make
CMakeFiles/memento.dir/memento.cpp.o: ../memento.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/libo/Design_Pattern/behaviour_degin_pattern/memento/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memento.dir/memento.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/memento.dir/memento.cpp.o -c /home/libo/Design_Pattern/behaviour_degin_pattern/memento/memento.cpp

CMakeFiles/memento.dir/memento.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memento.dir/memento.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/libo/Design_Pattern/behaviour_degin_pattern/memento/memento.cpp > CMakeFiles/memento.dir/memento.cpp.i

CMakeFiles/memento.dir/memento.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memento.dir/memento.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/libo/Design_Pattern/behaviour_degin_pattern/memento/memento.cpp -o CMakeFiles/memento.dir/memento.cpp.s

# Object files for target memento
memento_OBJECTS = \
"CMakeFiles/memento.dir/memento.cpp.o"

# External object files for target memento
memento_EXTERNAL_OBJECTS =

memento: CMakeFiles/memento.dir/memento.cpp.o
memento: CMakeFiles/memento.dir/build.make
memento: CMakeFiles/memento.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/libo/Design_Pattern/behaviour_degin_pattern/memento/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memento"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memento.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memento.dir/build: memento

.PHONY : CMakeFiles/memento.dir/build

CMakeFiles/memento.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memento.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memento.dir/clean

CMakeFiles/memento.dir/depend:
	cd /home/libo/Design_Pattern/behaviour_degin_pattern/memento/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/libo/Design_Pattern/behaviour_degin_pattern/memento /home/libo/Design_Pattern/behaviour_degin_pattern/memento /home/libo/Design_Pattern/behaviour_degin_pattern/memento/build /home/libo/Design_Pattern/behaviour_degin_pattern/memento/build /home/libo/Design_Pattern/behaviour_degin_pattern/memento/build/CMakeFiles/memento.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memento.dir/depend

