# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/germanzvezdin/Desktop/Git/SUPREMUM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SUPREMUM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SUPREMUM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SUPREMUM.dir/flags.make

CMakeFiles/SUPREMUM.dir/main.cpp.o: CMakeFiles/SUPREMUM.dir/flags.make
CMakeFiles/SUPREMUM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SUPREMUM.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SUPREMUM.dir/main.cpp.o -c /Users/germanzvezdin/Desktop/Git/SUPREMUM/main.cpp

CMakeFiles/SUPREMUM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SUPREMUM.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/germanzvezdin/Desktop/Git/SUPREMUM/main.cpp > CMakeFiles/SUPREMUM.dir/main.cpp.i

CMakeFiles/SUPREMUM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SUPREMUM.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/germanzvezdin/Desktop/Git/SUPREMUM/main.cpp -o CMakeFiles/SUPREMUM.dir/main.cpp.s

# Object files for target SUPREMUM
SUPREMUM_OBJECTS = \
"CMakeFiles/SUPREMUM.dir/main.cpp.o"

# External object files for target SUPREMUM
SUPREMUM_EXTERNAL_OBJECTS =

SUPREMUM: CMakeFiles/SUPREMUM.dir/main.cpp.o
SUPREMUM: CMakeFiles/SUPREMUM.dir/build.make
SUPREMUM: CMakeFiles/SUPREMUM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SUPREMUM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SUPREMUM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SUPREMUM.dir/build: SUPREMUM

.PHONY : CMakeFiles/SUPREMUM.dir/build

CMakeFiles/SUPREMUM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SUPREMUM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SUPREMUM.dir/clean

CMakeFiles/SUPREMUM.dir/depend:
	cd /Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/germanzvezdin/Desktop/Git/SUPREMUM /Users/germanzvezdin/Desktop/Git/SUPREMUM /Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug /Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug /Users/germanzvezdin/Desktop/Git/SUPREMUM/cmake-build-debug/CMakeFiles/SUPREMUM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SUPREMUM.dir/depend
