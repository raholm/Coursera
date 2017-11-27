#!/bin/bash

####
source=change.cpp
executable=change.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Changing Money"
echo "2" | ./$executable
echo "28" | ./$executable

####
source=fractional_knapsack.cpp
executable=fractional_knapsack.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fractional Knapsack"
echo "3 50 60 20 100 50 120 30" | ./$executable
echo "1 10 500 30" | ./$executable

####
source=dot_product.cpp
executable=dot_product.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Online Ad Placement"
echo "1 23 39" | ./$executable
echo "3 1 3 -5 -2 4 1" | ./$executable

####
source=covering_segments.cpp
executable=covering_segments.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Collecting Signatures"
echo "3 1 3 2 5 3 6" | ./$executable
echo "4 4 7 1 3 2 5 5 6" | ./$executable

####
source=largest_number.cpp
executable=largest_number.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Maximizing Salary"
echo "2 21 2" | ./$executable
echo "5 9 4 6 1 9" | ./$executable
echo "3 23 39 92" | ./$executable
echo "3 0 2 8" | ./$executable
echo "3 23 399 92" | ./$executable
echo "3 0 2 8" | ./$executable
echo "2 29 2" | ./$executable
echo "2 2 29" | ./$executable
