set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

add_executable(server server.cpp)

if(WIN32)
    target_link_libraries(server wsock32 ws2_32)
endif()