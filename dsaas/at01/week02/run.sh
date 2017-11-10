#!/bin/bash

####
source=fibonacci.cpp
executable=fibonacci.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fibonacci"
echo "3" | ./$executable
echo "10" | ./$executable
echo "5" | ./$executable
echo "40" | ./$executable
echo "43" | ./$executable

####
source=fibonacci_last_digit.cpp
executable=fibonacci_last_digit.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fibonacci Last Digit"
echo "3" | ./$executable
echo "10" | ./$executable
echo "5" | ./$executable
echo "40" | ./$executable
echo "43" | ./$executable

####
source=gcd.cpp
executable=gcd.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "GCD"
echo "18 35" | ./$executable
echo "28851538 1183019" | ./$executable
echo "1344 217" | ./$executable
echo "0 378" | ./$executable
