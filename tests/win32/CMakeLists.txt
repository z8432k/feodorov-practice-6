set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

# NB: Не забудь каждую цель линковать с библиотекой!
#
# ПРИМЕР НИЖЕ
#
# if(WIN32)
#    target_link_libraries(ИМЯ_ЦЕЛИ wsock32 ws2_32)
# endif()


add_executable(wintest wintest.cpp)

