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
CMAKE_COMMAND = /Users/brk/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Users/brk/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brk/_private/repos/utils/Camel-Snake-Util

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system

# Include any dependencies generated for this target.
include vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/progress.make

# Include the compile flags for this target's objects.
include vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/spdlog.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o -MF CMakeFiles/spdlog.dir/src/spdlog.cpp.o.d -o CMakeFiles/spdlog.dir/src/spdlog.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/spdlog.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/spdlog.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/spdlog.cpp > CMakeFiles/spdlog.dir/src/spdlog.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/spdlog.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/spdlog.cpp -o CMakeFiles/spdlog.dir/src/spdlog.cpp.s

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/stdout_sinks.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/stdout_sinks.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/stdout_sinks.cpp > CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/stdout_sinks.cpp -o CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/color_sinks.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/color_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/color_sinks.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/color_sinks.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/color_sinks.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/color_sinks.cpp > CMakeFiles/spdlog.dir/src/color_sinks.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/color_sinks.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/color_sinks.cpp -o CMakeFiles/spdlog.dir/src/color_sinks.cpp.s

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/file_sinks.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/file_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/file_sinks.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/file_sinks.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/file_sinks.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/file_sinks.cpp > CMakeFiles/spdlog.dir/src/file_sinks.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/file_sinks.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/file_sinks.cpp -o CMakeFiles/spdlog.dir/src/file_sinks.cpp.s

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/async.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o -MF CMakeFiles/spdlog.dir/src/async.cpp.o.d -o CMakeFiles/spdlog.dir/src/async.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/async.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/async.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/async.cpp > CMakeFiles/spdlog.dir/src/async.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/async.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/async.cpp -o CMakeFiles/spdlog.dir/src/async.cpp.s

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/flags.make
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/cfg.cpp
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o -MF CMakeFiles/spdlog.dir/src/cfg.cpp.o.d -o CMakeFiles/spdlog.dir/src/cfg.cpp.o -c /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/cfg.cpp

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/cfg.cpp.i"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/cfg.cpp > CMakeFiles/spdlog.dir/src/cfg.cpp.i

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/cfg.cpp.s"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog/src/cfg.cpp -o CMakeFiles/spdlog.dir/src/cfg.cpp.s

# Object files for target spdlog
spdlog_OBJECTS = \
"CMakeFiles/spdlog.dir/src/spdlog.cpp.o" \
"CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/color_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/file_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/async.cpp.o" \
"CMakeFiles/spdlog.dir/src/cfg.cpp.o"

# External object files for target spdlog
spdlog_EXTERNAL_OBJECTS =

bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/spdlog.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/color_sinks.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/file_sinks.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/async.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/src/cfg.cpp.o
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/build.make
bin/libspdlogd.a: vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../../../../../bin/libspdlogd.a"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && $(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean_target.cmake
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spdlog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/build: bin/libspdlogd.a
.PHONY : vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/build

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/clean:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog && $(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean.cmake
.PHONY : vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/clean

vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/depend:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brk/_private/repos/utils/Camel-Snake-Util /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/imgui/HBUI/vendor/spdlog /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : vendor/imgui/HBUI/vendor/spdlog/CMakeFiles/spdlog.dir/depend
