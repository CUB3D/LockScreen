# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cub3d/Development/LockScreen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cub3d/Development/LockScreen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LockScreen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LockScreen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LockScreen.dir/flags.make

CMakeFiles/LockScreen.dir/main.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LockScreen.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/main.cpp.o -c /home/cub3d/Development/LockScreen/main.cpp

CMakeFiles/LockScreen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/main.cpp > CMakeFiles/LockScreen.dir/main.cpp.i

CMakeFiles/LockScreen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/main.cpp -o CMakeFiles/LockScreen.dir/main.cpp.s

CMakeFiles/LockScreen.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/main.cpp.o.requires

CMakeFiles/LockScreen.dir/main.cpp.o.provides: CMakeFiles/LockScreen.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/main.cpp.o.provides

CMakeFiles/LockScreen.dir/main.cpp.o.provides.build: CMakeFiles/LockScreen.dir/main.cpp.o


CMakeFiles/LockScreen.dir/TTFFont.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/TTFFont.cpp.o: ../TTFFont.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LockScreen.dir/TTFFont.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/TTFFont.cpp.o -c /home/cub3d/Development/LockScreen/TTFFont.cpp

CMakeFiles/LockScreen.dir/TTFFont.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/TTFFont.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/TTFFont.cpp > CMakeFiles/LockScreen.dir/TTFFont.cpp.i

CMakeFiles/LockScreen.dir/TTFFont.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/TTFFont.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/TTFFont.cpp -o CMakeFiles/LockScreen.dir/TTFFont.cpp.s

CMakeFiles/LockScreen.dir/TTFFont.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/TTFFont.cpp.o.requires

CMakeFiles/LockScreen.dir/TTFFont.cpp.o.provides: CMakeFiles/LockScreen.dir/TTFFont.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/TTFFont.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/TTFFont.cpp.o.provides

CMakeFiles/LockScreen.dir/TTFFont.cpp.o.provides.build: CMakeFiles/LockScreen.dir/TTFFont.cpp.o


CMakeFiles/LockScreen.dir/XCBInstance.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/XCBInstance.cpp.o: ../XCBInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LockScreen.dir/XCBInstance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/XCBInstance.cpp.o -c /home/cub3d/Development/LockScreen/XCBInstance.cpp

CMakeFiles/LockScreen.dir/XCBInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/XCBInstance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/XCBInstance.cpp > CMakeFiles/LockScreen.dir/XCBInstance.cpp.i

CMakeFiles/LockScreen.dir/XCBInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/XCBInstance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/XCBInstance.cpp -o CMakeFiles/LockScreen.dir/XCBInstance.cpp.s

CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.requires

CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.provides: CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.provides

CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.provides.build: CMakeFiles/LockScreen.dir/XCBInstance.cpp.o


CMakeFiles/LockScreen.dir/Image.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/Image.cpp.o: ../Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LockScreen.dir/Image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/Image.cpp.o -c /home/cub3d/Development/LockScreen/Image.cpp

CMakeFiles/LockScreen.dir/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/Image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/Image.cpp > CMakeFiles/LockScreen.dir/Image.cpp.i

CMakeFiles/LockScreen.dir/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/Image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/Image.cpp -o CMakeFiles/LockScreen.dir/Image.cpp.s

CMakeFiles/LockScreen.dir/Image.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/Image.cpp.o.requires

CMakeFiles/LockScreen.dir/Image.cpp.o.provides: CMakeFiles/LockScreen.dir/Image.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/Image.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/Image.cpp.o.provides

CMakeFiles/LockScreen.dir/Image.cpp.o.provides.build: CMakeFiles/LockScreen.dir/Image.cpp.o


CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o: ../widgets/BaseWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o -c /home/cub3d/Development/LockScreen/widgets/BaseWidget.cpp

CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/widgets/BaseWidget.cpp > CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.i

CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/widgets/BaseWidget.cpp -o CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.s

CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.requires

CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.provides: CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.provides

CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.provides.build: CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o


CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o: ../widgets/ClockWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o -c /home/cub3d/Development/LockScreen/widgets/ClockWidget.cpp

CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/widgets/ClockWidget.cpp > CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.i

CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/widgets/ClockWidget.cpp -o CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.s

CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.requires

CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.provides: CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.provides

CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.provides.build: CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o


CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o: ../widgets/PasswordEntryWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o -c /home/cub3d/Development/LockScreen/widgets/PasswordEntryWidget.cpp

CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/widgets/PasswordEntryWidget.cpp > CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.i

CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/widgets/PasswordEntryWidget.cpp -o CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.s

CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.requires

CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.provides: CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.provides

CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.provides.build: CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o


CMakeFiles/LockScreen.dir/UIRenderer.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/UIRenderer.cpp.o: ../UIRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/LockScreen.dir/UIRenderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/UIRenderer.cpp.o -c /home/cub3d/Development/LockScreen/UIRenderer.cpp

CMakeFiles/LockScreen.dir/UIRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/UIRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/UIRenderer.cpp > CMakeFiles/LockScreen.dir/UIRenderer.cpp.i

CMakeFiles/LockScreen.dir/UIRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/UIRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/UIRenderer.cpp -o CMakeFiles/LockScreen.dir/UIRenderer.cpp.s

CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.requires

CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.provides: CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.provides

CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.provides.build: CMakeFiles/LockScreen.dir/UIRenderer.cpp.o


CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o: CMakeFiles/LockScreen.dir/flags.make
CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o: ../widgets/BatteryWidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o -c /home/cub3d/Development/LockScreen/widgets/BatteryWidget.cpp

CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cub3d/Development/LockScreen/widgets/BatteryWidget.cpp > CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.i

CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cub3d/Development/LockScreen/widgets/BatteryWidget.cpp -o CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.s

CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.requires:

.PHONY : CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.requires

CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.provides: CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/LockScreen.dir/build.make CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.provides.build
.PHONY : CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.provides

CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.provides.build: CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o


# Object files for target LockScreen
LockScreen_OBJECTS = \
"CMakeFiles/LockScreen.dir/main.cpp.o" \
"CMakeFiles/LockScreen.dir/TTFFont.cpp.o" \
"CMakeFiles/LockScreen.dir/XCBInstance.cpp.o" \
"CMakeFiles/LockScreen.dir/Image.cpp.o" \
"CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o" \
"CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o" \
"CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o" \
"CMakeFiles/LockScreen.dir/UIRenderer.cpp.o" \
"CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o"

# External object files for target LockScreen
LockScreen_EXTERNAL_OBJECTS =

LockScreen: CMakeFiles/LockScreen.dir/main.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/TTFFont.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/XCBInstance.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/Image.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/UIRenderer.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o
LockScreen: CMakeFiles/LockScreen.dir/build.make
LockScreen: /usr/lib/libSDL2main.a
LockScreen: /usr/lib/libSDL2.so
LockScreen: /usr/lib/libSDL2_image.so
LockScreen: /usr/lib/libSDL2_ttf.so
LockScreen: /usr/lib/libX11-xcb.so
LockScreen: CMakeFiles/LockScreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable LockScreen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LockScreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LockScreen.dir/build: LockScreen

.PHONY : CMakeFiles/LockScreen.dir/build

CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/main.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/TTFFont.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/XCBInstance.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/Image.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/widgets/BaseWidget.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/widgets/ClockWidget.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/widgets/PasswordEntryWidget.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/UIRenderer.cpp.o.requires
CMakeFiles/LockScreen.dir/requires: CMakeFiles/LockScreen.dir/widgets/BatteryWidget.cpp.o.requires

.PHONY : CMakeFiles/LockScreen.dir/requires

CMakeFiles/LockScreen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LockScreen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LockScreen.dir/clean

CMakeFiles/LockScreen.dir/depend:
	cd /home/cub3d/Development/LockScreen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cub3d/Development/LockScreen /home/cub3d/Development/LockScreen /home/cub3d/Development/LockScreen/cmake-build-debug /home/cub3d/Development/LockScreen/cmake-build-debug /home/cub3d/Development/LockScreen/cmake-build-debug/CMakeFiles/LockScreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LockScreen.dir/depend
