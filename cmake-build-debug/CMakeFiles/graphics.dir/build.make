# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/riham/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/riham/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/riham/Documents/Second Year/Sonic/ Sonic Game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/graphics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphics.dir/flags.make

CMakeFiles/graphics.dir/src/Source.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Source.cpp.o: ../src/Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphics.dir/src/Source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Source.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Source.cpp"

CMakeFiles/graphics.dir/src/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Source.cpp" > CMakeFiles/graphics.dir/src/Source.cpp.i

CMakeFiles/graphics.dir/src/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Source.cpp" -o CMakeFiles/graphics.dir/src/Source.cpp.s

CMakeFiles/graphics.dir/src/Source.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Source.cpp.o.requires

CMakeFiles/graphics.dir/src/Source.cpp.o.provides: CMakeFiles/graphics.dir/src/Source.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Source.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Source.cpp.o.provides

CMakeFiles/graphics.dir/src/Source.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Source.cpp.o


CMakeFiles/graphics.dir/src/Window/Window.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Window/Window.cpp.o: ../src/Window/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphics.dir/src/Window/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Window/Window.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Window/Window.cpp"

CMakeFiles/graphics.dir/src/Window/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Window/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Window/Window.cpp" > CMakeFiles/graphics.dir/src/Window/Window.cpp.i

CMakeFiles/graphics.dir/src/Window/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Window/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Window/Window.cpp" -o CMakeFiles/graphics.dir/src/Window/Window.cpp.s

CMakeFiles/graphics.dir/src/Window/Window.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Window/Window.cpp.o.requires

CMakeFiles/graphics.dir/src/Window/Window.cpp.o.provides: CMakeFiles/graphics.dir/src/Window/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Window/Window.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Window/Window.cpp.o.provides

CMakeFiles/graphics.dir/src/Window/Window.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Window/Window.cpp.o


CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o: ../src/Compontents/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Camera.cpp"

CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Camera.cpp" > CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.i

CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Camera.cpp" -o CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.s

CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.requires

CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.provides: CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.provides

CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o


CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o: ../src/Compontents/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Mesh.cpp"

CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Mesh.cpp" > CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.i

CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Mesh.cpp" -o CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.s

CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.requires

CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.provides: CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.provides

CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o


CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o: ../src/Compontents/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Model.cpp"

CMakeFiles/graphics.dir/src/Compontents/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Compontents/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Model.cpp" > CMakeFiles/graphics.dir/src/Compontents/Model.cpp.i

CMakeFiles/graphics.dir/src/Compontents/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Compontents/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Model.cpp" -o CMakeFiles/graphics.dir/src/Compontents/Model.cpp.s

CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.requires

CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.provides: CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.provides

CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o


CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o: ../src/Compontents/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Shader.cpp"

CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Shader.cpp" > CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.i

CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Shader.cpp" -o CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.s

CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.requires

CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.provides: CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.provides

CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o


CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o: ../src/Compontents/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o -c "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Texture.cpp"

CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Texture.cpp" > CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.i

CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/riham/Documents/Second Year/Sonic/ Sonic Game/src/Compontents/Texture.cpp" -o CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.s

CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.requires:

.PHONY : CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.requires

CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.provides: CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphics.dir/build.make CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.provides

CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.provides.build: CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o


# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/src/Source.cpp.o" \
"CMakeFiles/graphics.dir/src/Window/Window.cpp.o" \
"CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o" \
"CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o" \
"CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o" \
"CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o" \
"CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

graphics: CMakeFiles/graphics.dir/src/Source.cpp.o
graphics: CMakeFiles/graphics.dir/src/Window/Window.cpp.o
graphics: CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o
graphics: CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o
graphics: CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o
graphics: CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o
graphics: CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o
graphics: CMakeFiles/graphics.dir/build.make
graphics: CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable graphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphics.dir/build: graphics

.PHONY : CMakeFiles/graphics.dir/build

CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Source.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Window/Window.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Compontents/Camera.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Compontents/Mesh.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Compontents/Model.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Compontents/Shader.cpp.o.requires
CMakeFiles/graphics.dir/requires: CMakeFiles/graphics.dir/src/Compontents/Texture.cpp.o.requires

.PHONY : CMakeFiles/graphics.dir/requires

CMakeFiles/graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphics.dir/clean

CMakeFiles/graphics.dir/depend:
	cd "/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/riham/Documents/Second Year/Sonic/ Sonic Game" "/home/riham/Documents/Second Year/Sonic/ Sonic Game" "/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug" "/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug" "/home/riham/Documents/Second Year/Sonic/ Sonic Game/cmake-build-debug/CMakeFiles/graphics.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/graphics.dir/depend

