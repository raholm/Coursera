#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

unsigned get_fibonacci_last_digit_fast(unsigned long long n) {
    if (n <= 1) return n;

    unsigned previous = 0;
    unsigned current = 1;
    unsigned tmp;

    for (unsigned long long i = 0; i < n - 1; ++i) {
        tmp = previous;
        previous = current;
        current = (tmp + current) % 10;
    }

    return current;
}

unsigned fibonacci_sum_fast(unsigned long long n) {
    unsigned last_digit = get_fibonacci_last_digit_fast((n + 2) % 60);
    return last_digit == 0 ? 9 : last_digit - 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << std::endl;
}
