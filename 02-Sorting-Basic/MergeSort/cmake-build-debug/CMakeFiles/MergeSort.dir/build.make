# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Installation\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Installation\CLion 2018.2.6\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MergeSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MergeSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MergeSort.dir/flags.make

CMakeFiles/MergeSort.dir/main.cpp.obj: CMakeFiles/MergeSort.dir/flags.make
CMakeFiles/MergeSort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MergeSort.dir/main.cpp.obj"
	C:\MinGW\gcc\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MergeSort.dir\main.cpp.obj -c "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\main.cpp"

CMakeFiles/MergeSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MergeSort.dir/main.cpp.i"
	C:\MinGW\gcc\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\main.cpp" > CMakeFiles\MergeSort.dir\main.cpp.i

CMakeFiles/MergeSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MergeSort.dir/main.cpp.s"
	C:\MinGW\gcc\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\main.cpp" -o CMakeFiles\MergeSort.dir\main.cpp.s

# Object files for target MergeSort
MergeSort_OBJECTS = \
"CMakeFiles/MergeSort.dir/main.cpp.obj"

# External object files for target MergeSort
MergeSort_EXTERNAL_OBJECTS =

MergeSort.exe: CMakeFiles/MergeSort.dir/main.cpp.obj
MergeSort.exe: CMakeFiles/MergeSort.dir/build.make
MergeSort.exe: CMakeFiles/MergeSort.dir/linklibs.rsp
MergeSort.exe: CMakeFiles/MergeSort.dir/objects1.rsp
MergeSort.exe: CMakeFiles/MergeSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MergeSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MergeSort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MergeSort.dir/build: MergeSort.exe

.PHONY : CMakeFiles/MergeSort.dir/build

CMakeFiles/MergeSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MergeSort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MergeSort.dir/clean

CMakeFiles/MergeSort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort" "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort" "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug" "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug" "D:\Github Sue9\Play-with-Algorithms\02-Sorting-Basic\MergeSort\cmake-build-debug\CMakeFiles\MergeSort.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MergeSort.dir/depend

