#!/bin/sh

# generates the extensive benchmark source file

cat extensive_benchmark.cpp.head > extensive_benchmark.cpp
./generate_extensive_benchmark.py >>  extensive_benchmark.cpp

cat extensive_benchmark.cpp.tail  >>  extensive_benchmark.cpp

clang-format -i extensive_benchmark.cpp

