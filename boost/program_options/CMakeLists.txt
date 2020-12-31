cmake_minimum_required(VERSION 3.8)

project(bprogram_options LANGUAGES CXX)

set(TARGET bprogram_options)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(${TARGET} main.cpp)

target_link_libraries(${TARGET} Boost::program_options)