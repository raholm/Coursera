#!/bin/bash

####
source=binary_search.cpp
executable=binary_search.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Binary Search"
echo "5 1 5 8 12 13 5 8 1 23 1 11" | ./$executable

####
source=majority_element.cpp
executable=majority_element.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Majority Element"
echo "2 2 2" | ./$executable
echo "5 2 3 9 2 2" | ./$executable
echo "4 1 2 3 4" | ./$executable
echo "4 1 2 3 1" | ./$executable
