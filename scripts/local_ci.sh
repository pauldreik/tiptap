#!/bin/sh

set -e

rootdir=$(dirname $0)/..

for type in Debug Release ; do
    cmake -S "$rootdir"  -B build-$type -GNinja -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined"
    cmake --build build-$type
    (cd build-$type/tests; ctest)
done

echo "all is ok!"
