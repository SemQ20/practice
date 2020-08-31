echo off
cd build
cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .. && make && benchmarks.exe && cd ..