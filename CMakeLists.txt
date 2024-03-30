cmake_minimum_required(VERSION 3.13)
project(CamelSnakeUtil LANGUAGES C CXX OBJC OBJCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


#CMAKE_OBJCXX_LINK_EXECUTABLE



if (NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()
if (NOT DEFINED qMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif ()
if (NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif ()


set(IMVK_DOWNLOAD_GLFW ON CACHE BOOL "Download GLFW")
set(HBUI_GLFW ON CACHE BOOL "HBUI_GLFW")

add_subdirectory(vendor/imgui)

add_executable(CamelSnakeUtilTest
        src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/camel2snake.cc
        src/Application.cpp
        src/Application.h
        src/Gitlab/GitlabManager.cpp
        src/Gitlab/GitlabManager.h
        src/Certificates/CertificateGenerator.cpp
        src/Certificates/CertificateGenerator.h
        src/Certificates/Windows/CertificateGeneratorWindow.cpp
        src/Certificates/Windows/CertificateGeneratorWindow.h
        src/Authenticator/touch_id_auth.mm
        src/Authenticator/touch_id_auth.h
)
target_link_libraries(CamelSnakeUtilTest PRIVATE HBUI)



# Find and link Cocoa Framework
find_library(COCOA_LIBRARY Cocoa)
if(NOT COCOA_LIBRARY)
    message(FATAL_ERROR "Cocoa not found")
endif()
target_link_libraries(CamelSnakeUtilTest PRIVATE ${COCOA_LIBRARY})

# Find and link Security Framework
find_library(SECURITY_LIBRARY Security)
if(NOT SECURITY_LIBRARY)
    message(FATAL_ERROR "Security not found")
endif()
target_link_libraries(CamelSnakeUtilTest PRIVATE ${SECURITY_LIBRARY})

find_library(LOCAL_AUTHENTICATION_LIBRARY LocalAuthentication)
if(NOT LOCAL_AUTHENTICATION_LIBRARY)
    message(FATAL_ERROR "LocalAuthentication not found")
endif()
target_link_libraries(CamelSnakeUtilTest PRIVATE ${LOCAL_AUTHENTICATION_LIBRARY})




