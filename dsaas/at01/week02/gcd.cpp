#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>

int gcd_naive(int a, int b) {
  int current_gcd = 1;

  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }

  return current_gcd;
}

unsigned gcd_fast(unsigned a, unsigned b) {
  if (b == 0) return a;
  return gcd_fast(b, a % b);
}

void test_solution() {
  assert(gcd_fast(18, 35) == 1);
  assert(gcd_fast(18, 35) == gcd_fast(35, 18));
  assert(gcd_fast(1344, 217) == 7);
  assert(gcd_fast(1344, 217) == gcd_fast(217, 1344));
  assert(gcd_fast(28851538, 1183019) == 17657);
  assert(gcd_fast(28851538, 1183019) == gcd_fast(1183019, 28851538));

  unsigned n = 1000;
  unsigned max = 1000;
  unsigned a, b;

  for (unsigned i = 0; i < n; ++i) {
    a = 1 + rand() % max;
    b = 1 + rand() % max;

    assert(gcd_fast(a, b) == gcd_naive(a, b));
    assert(gcd_fast(a, b) == gcd_fast(b, a));
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  test_solution();
  return 0;
}
