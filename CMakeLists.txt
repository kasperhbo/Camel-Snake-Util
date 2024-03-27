cmake_minimum_required(VERSION 3.13)
project(CamelSnakeUtil CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
        src/Windows/CertificateGenerator.cpp
        src/Windows/CertificateGenerator.h
)

target_link_libraries(CamelSnakeUtilTest PRIVATE HBUI)