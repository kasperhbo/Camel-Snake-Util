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

# Utility rule file for open62541-generator-namespace.

# Include any custom commands dependencies for this target.
include vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/progress.make

vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c
vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.h

vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/nodeset_compiler.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/nodes.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/nodeset.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/datatypes.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/backend_open62541.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/backend_open62541_nodes.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/backend_open62541_datatypes.py
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.Reduced.xml
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.EventsMinimal.xml
vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.Part8_Subset.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating src_generated/open62541/namespace0_generated.c, src_generated/open62541/namespace0_generated.h"
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541 && /opt/homebrew/bin/python3 /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/nodeset_compiler.py --internal-headers --ignore=/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler/NodeID_NS0_Base.txt --xml=/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.Reduced.xml --xml=/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.EventsMinimal.xml --xml=/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema/Opc.Ua.NodeSet2.Part8_Subset.xml /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated

vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.h: vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c
	@$(CMAKE_COMMAND) -E touch_nocreate vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.h

open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace
open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.c
open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/src_generated/open62541/namespace0_generated.h
open62541-generator-namespace: vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/build.make
.PHONY : open62541-generator-namespace

# Rule to build all files generated by this target.
vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/build: open62541-generator-namespace
.PHONY : vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/build

vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/clean:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541 && $(CMAKE_COMMAND) -P CMakeFiles/open62541-generator-namespace.dir/cmake_clean.cmake
.PHONY : vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/clean

vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/depend:
	cd /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brk/_private/repos/utils/Camel-Snake-Util /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541 /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541 /Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : vendor/open62541pp/3rdparty/open62541/CMakeFiles/open62541-generator-namespace.dir/depend
