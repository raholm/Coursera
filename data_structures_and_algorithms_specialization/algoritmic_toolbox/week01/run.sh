#!/bin/bash

g++ -pipe -O2 -std=c++14 max_pairwise_product.cpp -lm -o main.so

echo "3 1 2 3" | ./main.so
echo "10 7 5 14 2 8 8 10 1 2 3" | ./main.so
echo "5 4 6 2 6 1" | ./main.so
