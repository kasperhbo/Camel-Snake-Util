# Install script for directory: /Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/bin/libopen62541.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopen62541.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopen62541.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopen62541.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541/open62541Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541/open62541Targets.cmake"
         "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/CMakeFiles/Export/8cb9d92d46a89e68bf96c40f4a60fffd/open62541Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541/open62541Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541/open62541Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/CMakeFiles/Export/8cb9d92d46a89e68bf96c40f4a60fffd/open62541Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/CMakeFiles/Export/8cb9d92d46a89e68bf96c40f4a60fffd/open62541Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/open62541" TYPE FILE FILES
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/open62541Config.cmake"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/open62541ConfigVersion.cmake"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/open62541Macros.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/open62541/tools" TYPE DIRECTORY FILES
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/certs"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/nodeset_compiler"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/schema"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/deps/ua-nodeset"
    USE_SOURCE_PERMISSIONS FILES_MATCHING REGEX "/[^/]*$" REGEX "/[^/]*\\.pyc$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/open62541/tools" TYPE FILE FILES
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/generate_datatypes.py"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/generate_nodeid_header.py"
    "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/tools/generate_statuscode_descriptions.py"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/deps/ms_stdint.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/architecture_definitions.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/posix" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/arch/posix/ua_architecture.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/statuscodes.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/nodeids.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/common.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/types.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/types_generated.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/src_generated/open62541/types_generated_handling.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/util.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/log.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/network.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/accesscontrol.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/pki.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/securitypolicy.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/pubsub.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/deps/ziptree.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/deps/aa_tree.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/plugin/nodestore.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/server_pubsub.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/server.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/client.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/client_highlevel.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/client_subscriptions.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/client_highlevel_async.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/accesscontrol_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/pki_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/log_stdout.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/nodestore_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/server_config_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/client_config_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/securitypolicy_default.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541/plugin" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/plugins/include/open62541/plugin/log_syslog.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/network_tcp.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/open62541" TYPE FILE FILES "/Users/brk/_private/repos/utils/Camel-Snake-Util/vendor/open62541pp/3rdparty/open62541/include/open62541/architecture_functions.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/arch/cmake_install.cmake")
  include("/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/doc/cmake_install.cmake")
  include("/Users/brk/_private/repos/utils/Camel-Snake-Util/cmake-build-debug-system/vendor/open62541pp/3rdparty/open62541/tools/packaging/cmake_install.cmake")

endif()

