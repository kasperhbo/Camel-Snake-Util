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

# Utility rule file for update_mappings.

# Include any custom commands dependencies for this target.
include ImVK/glfw/src/CMakeFiles/update_mappings.dir/compiler_depend.make

# Include the progress variables for this target.
include ImVK/glfw/src/CMakeFiles/update_mappings.dir/progress.make

ImVK/glfw/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/glfw/src && /Users/brk/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -P /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/glfw/CMake/GenerateMappings.cmake mappings.h.in mappings.h

update_mappings: ImVK/glfw/src/CMakeFiles/update_mappings
update_mappings: ImVK/glfw/src/CMakeFiles/update_mappings.dir/build.make
.PHONY : update_mappings

# Rule to build all files generated by this target.
ImVK/glfw/src/CMakeFiles/update_mappings.dir/build: update_mappings
.PHONY : ImVK/glfw/src/CMakeFiles/update_mappings.dir/build

ImVK/glfw/src/CMakeFiles/update_mappings.dir/clean:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/ImVK/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : ImVK/glfw/src/CMakeFiles/update_mappings.dir/clean

ImVK/glfw/src/CMakeFiles/update_mappings.dir/depend:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brk/_private/repos/utils/Camel-Snake-Util /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/glfw/src /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/ImVK/glfw/src /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/ImVK/glfw/src/CMakeFiles/update_mappings.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : ImVK/glfw/src/CMakeFiles/update_mappings.dir/depend

