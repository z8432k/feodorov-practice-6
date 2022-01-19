cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(os-task5 LANGUAGES C CXX)

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

if(CMAKE_COMPILER_IS_GNUCC)
    message(STATUS "Detected GNU compiler. Using specific flags.")
    set(CMAKE_C_FLAGS_RELEASE "-pipe -O0")
endif()


#enable_testing()
#add_subdirectory(tests)

################################################################################



################################
#                              #
#            CLIENT            #
#                              #
################################
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    add_subdirectory(client)
endif()


################################
#                              #
#            SERVER            #
#                              #
################################
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    add_subdirectory(server)
endif()
