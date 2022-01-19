set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

# NB: Библиотека линкуется автоматитчески для всех целей ниже
link_libraries(wsock32 ws2_32)

################################################################################


add_executable(wintest wintest.cpp)

