
### NB!: Скорее всего вам тут править нечего, но попробовать можно.
#        Этот файл просто разделяет тесты на платформоспецифичные
#        Скорее всего вам нужно править CMakeLists.txt в каталогах ниже


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
