#include <iostream>
#include <vector>

using Vector = std::vector<unsigned long long>;

void print(const Vector& v) {
    for (auto const& e : v)
        std::cout << e << " ";
    std::cout << std::endl;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

unsigned long long fibonacci_fast(unsigned long long n, unsigned long long m, Vector& numbers) {
    if (n < numbers.size()) return numbers.at(n);

    for (unsigned i = numbers.size(); i <= n; ++i)
        numbers.push_back((numbers.at(i - 1) + numbers.at(i - 2)) % m);

    return numbers.at(n);
}

unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    if (n <= 1) return n;

    Vector cache{0, 1};
    Vector pattern{0, 1};

    unsigned long long counter = 2;
    bool pattern_found = false;

    while (!pattern_found) {
        pattern.push_back(fibonacci_fast(counter, m, cache) % m);

        if (pattern.at(counter) == 1 && pattern.at(counter - 1) == 0)
            pattern_found = true;

        ++counter;
    }

    unsigned long long pattern_size = pattern.size() - 2;
    return fibonacci_fast(n % pattern_size, m, cache);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
