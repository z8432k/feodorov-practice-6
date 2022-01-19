cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(os-task5 LANGUAGES C CXX)
################################################################################





################################
#                              #
#            CLIENT            #
#                              #
################################

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows") # <= Тут ничего не трогать
    # Изменить поддиректорию строчкой ниже в соответствии с заданием
    add_subdirectory(client)
endif()



################################################################################



################################
#                              #
#            SERVER            #
#                              #
################################

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux") # <= Тут ничего не торгать
    # Изменить поддиректорию строчкой ниже в соответствии с заданием
    add_subdirectory(server)
endif()





################################################################################
################################################################################



set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(tests)
