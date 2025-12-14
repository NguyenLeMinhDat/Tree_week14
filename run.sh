#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi
gcc ./src/*.c -I./include -o ./build/main
./build/main