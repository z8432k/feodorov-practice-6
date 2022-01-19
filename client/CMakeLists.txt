set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE  ON)

add_executable(client client.cpp)

if(WIN32)
    target_link_libraries(client wsock32 ws2_32)
endif()