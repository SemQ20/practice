cmake_minimum_required(VERSION 3.8)

project(test LANGUAGES CXX)

set(TARGET test)

find_package(OpenCV REQUIRED)

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} ${OpenCV_LIBS})