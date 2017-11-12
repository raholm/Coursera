#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


unsigned long long get_fibonacci_partial_sum_fast(unsigned long long from, unsigned long long to) {
    unsigned long long current = 0;
    unsigned long long next  = 1;
    unsigned long long sum = 0;

    for (unsigned long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
            sum %= 10;
        }

        unsigned long long new_current = next;
        next = (next + current) % 10;
        current = new_current;
    }

    return sum;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
