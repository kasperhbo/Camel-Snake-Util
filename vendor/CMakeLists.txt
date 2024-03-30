#create interface for all vendor packages
message(STATUS "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message(STATUS "vendProjName: ${PROJECT_NAME}-VENDOR")
message(STATUS "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
add_library(vendor_interface INTERFACE)
target_include_directories(vendor_interface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/open62541pp/include)

#set(vendProjName ${PROJECT_NAME}-VENDOR)
#add_library(${vendProjName} INTERFACE)
#
##open62541pp
####vars
add_subdirectory(open62541pp)
target_link_libraries(vendor_interface INTERFACE open62541pp)

##HBUI
set(IMVK_DOWNLOAD_GLFW ON CACHE BOOL "Download GLFW")
set(HBUI_GLFW ON CACHE BOOL "HBUI_GLFW")
add_subdirectory(imgui)
target_link_libraries(vendor_interface INTERFACE HBUI)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/imgui/HBUI/include)

