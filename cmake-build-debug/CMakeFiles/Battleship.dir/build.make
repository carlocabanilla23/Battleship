# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\John Carlo Cabanilla\Desktop\Battleship"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Battleship.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Battleship.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Battleship.dir/flags.make

CMakeFiles/Battleship.dir/main.cpp.obj: CMakeFiles/Battleship.dir/flags.make
CMakeFiles/Battleship.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Battleship.dir/main.cpp.obj"
	C:\Users\JOHNCA~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Battleship.dir\main.cpp.obj -c "C:\Users\John Carlo Cabanilla\Desktop\Battleship\main.cpp"

CMakeFiles/Battleship.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Battleship.dir/main.cpp.i"
	C:\Users\JOHNCA~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\John Carlo Cabanilla\Desktop\Battleship\main.cpp" > CMakeFiles\Battleship.dir\main.cpp.i

CMakeFiles/Battleship.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Battleship.dir/main.cpp.s"
	C:\Users\JOHNCA~1\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\John Carlo Cabanilla\Desktop\Battleship\main.cpp" -o CMakeFiles\Battleship.dir\main.cpp.s

# Object files for target Battleship
Battleship_OBJECTS = \
"CMakeFiles/Battleship.dir/main.cpp.obj"

# External object files for target Battleship
Battleship_EXTERNAL_OBJECTS =

Battleship.exe: CMakeFiles/Battleship.dir/main.cpp.obj
Battleship.exe: CMakeFiles/Battleship.dir/build.make
Battleship.exe: CMakeFiles/Battleship.dir/linklibs.rsp
Battleship.exe: CMakeFiles/Battleship.dir/objects1.rsp
Battleship.exe: CMakeFiles/Battleship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Battleship.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Battleship.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Battleship.dir/build: Battleship.exe
.PHONY : CMakeFiles/Battleship.dir/build

CMakeFiles/Battleship.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Battleship.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Battleship.dir/clean

CMakeFiles/Battleship.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\John Carlo Cabanilla\Desktop\Battleship" "C:\Users\John Carlo Cabanilla\Desktop\Battleship" "C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug" "C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug" "C:\Users\John Carlo Cabanilla\Desktop\Battleship\cmake-build-debug\CMakeFiles\Battleship.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Battleship.dir/depend

