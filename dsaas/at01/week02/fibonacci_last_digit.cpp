#include <iostream>
#include <cassert>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
  if (n <= 1) return n;

  int previous = 0;
  int current  = 1;

  for (int i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
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

void test_solution() {
  assert(get_fibonacci_last_digit_fast(0) == 0);
  assert(get_fibonacci_last_digit_fast(1) == 1);
  assert(get_fibonacci_last_digit_fast(2) == 1);
  assert(get_fibonacci_last_digit_fast(3) == 2);
  assert(get_fibonacci_last_digit_fast(10) == 5);
  assert(get_fibonacci_last_digit_fast(331) == 9);
  assert(get_fibonacci_last_digit_fast(200) == 5);
  assert(get_fibonacci_last_digit_fast(327305) == 5);

  for (int n = 0; n < 20; ++n)
    assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit_fast(n);
  std::cout << c << '\n';
  test_solution();
  return 0;
}
