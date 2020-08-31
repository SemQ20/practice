cmake_minimum_required(VERSION 3.8)

project(benchmarks LANGUAGES CXX)

set(TARGET benchmarks)

find_package(benchmark REQUIRED)

add_executable(${TARGET} test_bench.cpp)

target_link_libraries(${TARGET} benchmark::benchmark)
target_link_libraries(${TARGET} pthread)