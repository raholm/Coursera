#include <iostream>

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

unsigned get_fibonacci_last_digit_fast(int n) {
    if (n <= 1) return n;

    unsigned previous = 0;
    unsigned current = 1;
    unsigned tmp;

    for (unsigned i = 0; i < n - 1; ++i) {
        tmp = previous;
        previous = current;
        current = (tmp + current) % 10;
    }

    return current;
}

unsigned long long get_fibonacci_partial_sum_fast(unsigned long long from, unsigned long long to) {
    unsigned last_digit1 = get_fibonacci_last_digit_fast((to + 2) % 60);
    unsigned last_digit2 = get_fibonacci_last_digit_fast((from + 2) % 60);

    unsigned last_digit = last_digit1 + last_digit2;

    if (last_digit == 0) return 8;
    else if (last_digit == 1) return 1;
    return last_digit - 2;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
