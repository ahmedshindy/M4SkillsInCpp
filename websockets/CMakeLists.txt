cmake_minimum_required(VERSION 3.1)
project(WebSocketppServer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(server main.cpp)

target_link_libraries(server ${CONAN_LIBS})
