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
CMAKE_COMMAND = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Stud\5 sem\os\l4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Stud\5 sem\os\l4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/l4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/l4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/l4.dir/flags.make

CMakeFiles/l4.dir/main.cpp.obj: CMakeFiles/l4.dir/flags.make
CMakeFiles/l4.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Stud\5 sem\os\l4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/l4.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\l4.dir\main.cpp.obj -c "E:\Stud\5 sem\os\l4\main.cpp"

CMakeFiles/l4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l4.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Stud\5 sem\os\l4\main.cpp" > CMakeFiles\l4.dir\main.cpp.i

CMakeFiles/l4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l4.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Stud\5 sem\os\l4\main.cpp" -o CMakeFiles\l4.dir\main.cpp.s

CMakeFiles/l4.dir/safe_input.cpp.obj: CMakeFiles/l4.dir/flags.make
CMakeFiles/l4.dir/safe_input.cpp.obj: ../safe_input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Stud\5 sem\os\l4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/l4.dir/safe_input.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\l4.dir\safe_input.cpp.obj -c "E:\Stud\5 sem\os\l4\safe_input.cpp"

CMakeFiles/l4.dir/safe_input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l4.dir/safe_input.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Stud\5 sem\os\l4\safe_input.cpp" > CMakeFiles\l4.dir\safe_input.cpp.i

CMakeFiles/l4.dir/safe_input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l4.dir/safe_input.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Stud\5 sem\os\l4\safe_input.cpp" -o CMakeFiles\l4.dir\safe_input.cpp.s

CMakeFiles/l4.dir/menu.cpp.obj: CMakeFiles/l4.dir/flags.make
CMakeFiles/l4.dir/menu.cpp.obj: ../menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Stud\5 sem\os\l4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/l4.dir/menu.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\l4.dir\menu.cpp.obj -c "E:\Stud\5 sem\os\l4\menu.cpp"

CMakeFiles/l4.dir/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/l4.dir/menu.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Stud\5 sem\os\l4\menu.cpp" > CMakeFiles\l4.dir\menu.cpp.i

CMakeFiles/l4.dir/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/l4.dir/menu.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Stud\5 sem\os\l4\menu.cpp" -o CMakeFiles\l4.dir\menu.cpp.s

# Object files for target l4
l4_OBJECTS = \
"CMakeFiles/l4.dir/main.cpp.obj" \
"CMakeFiles/l4.dir/safe_input.cpp.obj" \
"CMakeFiles/l4.dir/menu.cpp.obj"

# External object files for target l4
l4_EXTERNAL_OBJECTS =

l4.exe: CMakeFiles/l4.dir/main.cpp.obj
l4.exe: CMakeFiles/l4.dir/safe_input.cpp.obj
l4.exe: CMakeFiles/l4.dir/menu.cpp.obj
l4.exe: CMakeFiles/l4.dir/build.make
l4.exe: CMakeFiles/l4.dir/linklibs.rsp
l4.exe: CMakeFiles/l4.dir/objects1.rsp
l4.exe: CMakeFiles/l4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Stud\5 sem\os\l4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable l4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\l4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/l4.dir/build: l4.exe
.PHONY : CMakeFiles/l4.dir/build

CMakeFiles/l4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\l4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/l4.dir/clean

CMakeFiles/l4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Stud\5 sem\os\l4" "E:\Stud\5 sem\os\l4" "E:\Stud\5 sem\os\l4\cmake-build-debug" "E:\Stud\5 sem\os\l4\cmake-build-debug" "E:\Stud\5 sem\os\l4\cmake-build-debug\CMakeFiles\l4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/l4.dir/depend
