#!/bin/bash
g++ main.cpp Ball.cpp -lncurses -pthread -o exe
./exe
rm -rf exe
