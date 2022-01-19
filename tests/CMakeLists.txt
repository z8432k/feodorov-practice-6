#####################################
#                                   #
#            WIN32 TESTS            #
#                                   #
#####################################
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    add_subdirectory(win32)
endif()


#####################################
#                                   #
#            POSIX TESTS            #
#                                   #
#####################################
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    add_subdirectory(posix)
endif()
