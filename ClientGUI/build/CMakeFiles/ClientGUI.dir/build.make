# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build

# Include any dependencies generated for this target.
include CMakeFiles/ClientGUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ClientGUI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ClientGUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClientGUI.dir/flags.make

CMakeFiles/ClientGUI.dir/main.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/main.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/main.cpp
CMakeFiles/ClientGUI.dir/main.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClientGUI.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/main.cpp.o -MF CMakeFiles/ClientGUI.dir/main.cpp.o.d -o CMakeFiles/ClientGUI.dir/main.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/main.cpp

CMakeFiles/ClientGUI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/main.cpp > CMakeFiles/ClientGUI.dir/main.cpp.i

CMakeFiles/ClientGUI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/main.cpp -o CMakeFiles/ClientGUI.dir/main.cpp.s

CMakeFiles/ClientGUI.dir/Menu.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/Menu.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Menu.cpp
CMakeFiles/ClientGUI.dir/Menu.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ClientGUI.dir/Menu.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/Menu.cpp.o -MF CMakeFiles/ClientGUI.dir/Menu.cpp.o.d -o CMakeFiles/ClientGUI.dir/Menu.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Menu.cpp

CMakeFiles/ClientGUI.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/Menu.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Menu.cpp > CMakeFiles/ClientGUI.dir/Menu.cpp.i

CMakeFiles/ClientGUI.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/Menu.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Menu.cpp -o CMakeFiles/ClientGUI.dir/Menu.cpp.s

CMakeFiles/ClientGUI.dir/Button.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/Button.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Button.cpp
CMakeFiles/ClientGUI.dir/Button.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ClientGUI.dir/Button.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/Button.cpp.o -MF CMakeFiles/ClientGUI.dir/Button.cpp.o.d -o CMakeFiles/ClientGUI.dir/Button.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Button.cpp

CMakeFiles/ClientGUI.dir/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/Button.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Button.cpp > CMakeFiles/ClientGUI.dir/Button.cpp.i

CMakeFiles/ClientGUI.dir/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/Button.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Button.cpp -o CMakeFiles/ClientGUI.dir/Button.cpp.s

CMakeFiles/ClientGUI.dir/Message.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/Message.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Message.cpp
CMakeFiles/ClientGUI.dir/Message.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ClientGUI.dir/Message.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/Message.cpp.o -MF CMakeFiles/ClientGUI.dir/Message.cpp.o.d -o CMakeFiles/ClientGUI.dir/Message.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Message.cpp

CMakeFiles/ClientGUI.dir/Message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/Message.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Message.cpp > CMakeFiles/ClientGUI.dir/Message.cpp.i

CMakeFiles/ClientGUI.dir/Message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/Message.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Message.cpp -o CMakeFiles/ClientGUI.dir/Message.cpp.s

CMakeFiles/ClientGUI.dir/Messages.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/Messages.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Messages.cpp
CMakeFiles/ClientGUI.dir/Messages.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ClientGUI.dir/Messages.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/Messages.cpp.o -MF CMakeFiles/ClientGUI.dir/Messages.cpp.o.d -o CMakeFiles/ClientGUI.dir/Messages.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Messages.cpp

CMakeFiles/ClientGUI.dir/Messages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/Messages.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Messages.cpp > CMakeFiles/ClientGUI.dir/Messages.cpp.i

CMakeFiles/ClientGUI.dir/Messages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/Messages.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/Messages.cpp -o CMakeFiles/ClientGUI.dir/Messages.cpp.s

CMakeFiles/ClientGUI.dir/InputBox.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/InputBox.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/InputBox.cpp
CMakeFiles/ClientGUI.dir/InputBox.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ClientGUI.dir/InputBox.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/InputBox.cpp.o -MF CMakeFiles/ClientGUI.dir/InputBox.cpp.o.d -o CMakeFiles/ClientGUI.dir/InputBox.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/InputBox.cpp

CMakeFiles/ClientGUI.dir/InputBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/InputBox.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/InputBox.cpp > CMakeFiles/ClientGUI.dir/InputBox.cpp.i

CMakeFiles/ClientGUI.dir/InputBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/InputBox.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/InputBox.cpp -o CMakeFiles/ClientGUI.dir/InputBox.cpp.s

CMakeFiles/ClientGUI.dir/TCPClient.cpp.o: CMakeFiles/ClientGUI.dir/flags.make
CMakeFiles/ClientGUI.dir/TCPClient.cpp.o: /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/TCPClient.cpp
CMakeFiles/ClientGUI.dir/TCPClient.cpp.o: CMakeFiles/ClientGUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ClientGUI.dir/TCPClient.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ClientGUI.dir/TCPClient.cpp.o -MF CMakeFiles/ClientGUI.dir/TCPClient.cpp.o.d -o CMakeFiles/ClientGUI.dir/TCPClient.cpp.o -c /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/TCPClient.cpp

CMakeFiles/ClientGUI.dir/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ClientGUI.dir/TCPClient.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/TCPClient.cpp > CMakeFiles/ClientGUI.dir/TCPClient.cpp.i

CMakeFiles/ClientGUI.dir/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ClientGUI.dir/TCPClient.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/TCPClient.cpp -o CMakeFiles/ClientGUI.dir/TCPClient.cpp.s

# Object files for target ClientGUI
ClientGUI_OBJECTS = \
"CMakeFiles/ClientGUI.dir/main.cpp.o" \
"CMakeFiles/ClientGUI.dir/Menu.cpp.o" \
"CMakeFiles/ClientGUI.dir/Button.cpp.o" \
"CMakeFiles/ClientGUI.dir/Message.cpp.o" \
"CMakeFiles/ClientGUI.dir/Messages.cpp.o" \
"CMakeFiles/ClientGUI.dir/InputBox.cpp.o" \
"CMakeFiles/ClientGUI.dir/TCPClient.cpp.o"

# External object files for target ClientGUI
ClientGUI_EXTERNAL_OBJECTS =

ClientGUI: CMakeFiles/ClientGUI.dir/main.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/Menu.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/Button.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/Message.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/Messages.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/InputBox.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/TCPClient.cpp.o
ClientGUI: CMakeFiles/ClientGUI.dir/build.make
ClientGUI: /usr/local/lib/libsfml-graphics.2.6.1.dylib
ClientGUI: /usr/local/lib/libsfml-audio.2.6.1.dylib
ClientGUI: /usr/local/lib/libsfml-network.2.6.1.dylib
ClientGUI: /usr/local/lib/libsfml-window.2.6.1.dylib
ClientGUI: /usr/local/lib/libsfml-system.2.6.1.dylib
ClientGUI: CMakeFiles/ClientGUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ClientGUI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClientGUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClientGUI.dir/build: ClientGUI
.PHONY : CMakeFiles/ClientGUI.dir/build

CMakeFiles/ClientGUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClientGUI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClientGUI.dir/clean

CMakeFiles/ClientGUI.dir/depend:
	cd /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build /Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/build/CMakeFiles/ClientGUI.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ClientGUI.dir/depend
