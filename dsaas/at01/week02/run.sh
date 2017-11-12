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

####
source=lcm.cpp
executable=lcm.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "LCM"
echo "6 8" | ./$executable
echo "28851538 1183019" | ./$executable

####
source=fibonacci_huge.cpp
executable=fibonacci_huge.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fibonacci Huge"
echo "1 239" | ./$executable
echo "2015 3" | ./$executable
echo "239 1000" | ./$executable
echo "2816213588 30524" | ./$executable

####
source=fibonacci_sum_last_digit.cpp
executable=fibonacci_sum_last_digit.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fibonacci Sum Last Digit"
echo "3" | ./$executable
echo "100" | ./$executable
echo "832564823476" | ./$executable

####
source=fibonacci_partial_sum.cpp
executable=fibonacci_partial_sum.so

g++ -pipe -O2 -std=c++14 $source -lm -o $executable

echo "Fibonacci Partial Sum Last Digit"
echo "3 7" | ./$executable
echo "10 10" | ./$executable
echo "10 200" | ./$executable
# echo "10 10000000000" | ./$executable
