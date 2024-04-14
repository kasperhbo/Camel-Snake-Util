cmake_minimum_required(VERSION 3.12)
project(CamelSnakeUtil LANGUAGES CXX C OBJC OBJCXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# compiled binaries folders (same as open62541)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(UAPP_ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" OFF)
option(UAPP_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
set(IMVK_DOWNLOAD_GLFW ON CACHE BOOL "Download GLFW")
set(HBUI_GLFW ON CACHE BOOL "HBUI_GLFW")


add_executable(${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/camel2snake.cc
        src/Application.cpp
        src/Application.h

        src/Opcua/Server.cpp
        src/Opcua/Server.h
        src/Opcua/ServerManagerWindow.cpp
        src/Opcua/ServerManagerWindow.h
        src/Opcua/NodeWindow.cpp
        src/Opcua/NodeWindow.h
)

######################################
#HBUI
#add_subdirectory(vendor/imgui)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE HBUI)


######################################
#open62541pp
###vars
#set(UAPP_BUILD_TESTS OFF CACHE BOOL "Build tests for open62541pp")
#set(UAPP_WARNINGS_AS_ERRORS OFF CACHE BOOL "Treat warnings as errors for open62541pp")
#set(UAPP_ENABLE_SANITIZER_UNDEFINED_BEHAVIOR ON CACHE BOOL "Enable undefined behavior sanitizer for open62541pp")
#set(UAPP_ENABLE_CLANG_TIDY ON CACHE BOOL "Enable clang-tidy for open62541pp")
#set(UAPP_BUILD_EXAMPLES ON CACHE BOOL "Build examples for open62541pp")
#
#add_subdirectory(vendor/open62541pp)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE open62541pp)
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE vendor/open62541pp/include)
message(STATUS "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message(STATUS "vendProjName: ${PROJECT_NAME}-VENDOR")
message(STATUS "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")


add_subdirectory(vendor)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE vendor_interface)


######################################
# Find and link Cocoa Framework
if (APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    if (NOT COCOA_LIBRARY)
        message(FATAL_ERROR "Cocoa not found")
    endif ()
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${COCOA_LIBRARY})
endif()

if (APPLE)
    # Find and link Security Framework
    find_library(SECURITY_LIBRARY Security)
    if (NOT SECURITY_LIBRARY)
        message(FATAL_ERROR "Security not found")
    endif ()
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${SECURITY_LIBRARY})

    find_library(LOCAL_AUTHENTICATION_LIBRARY LocalAuthentication)
    if (NOT LOCAL_AUTHENTICATION_LIBRARY)
        message(FATAL_ERROR "LocalAuthentication not found")
    endif ()
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LOCAL_AUTHENTICATION_LIBRARY})
endif (APPLE)
