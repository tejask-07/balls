#!/bin/bash
g++ -std=c++17 main.cpp -o ball $(pkg-config --cflags --libs raylib)
./ball