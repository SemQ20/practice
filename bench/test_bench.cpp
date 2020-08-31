#include <string>
#include <benchmark/benchmark.h>


/* If using CMake, it is recommended to link against the project-provided benchmark::benchmark 
  * and benchmark::benchmark_main targets using target_link_libraries. 
  * It is possible to use find_package to import an installed version of the library.

  * find_package(benchmark REQUIRED)
Alternatively, add_subdirectory will incorporate the library directly in to one's CMake project.

  * add_subdirectory(benchmark)
Either way, link to the library as follows.

  * target_link_libraries(MyTarget benchmark::benchmark) 
*/

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();

/* for compile: 
 clang++ test_bench.cpp -std=c++17 -isystem                 
 benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread */