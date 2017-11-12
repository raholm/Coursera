#include <iostream>
#include <cassert>
#include <cstdlib>

unsigned long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

unsigned gcd_fast(unsigned a, unsigned b) {
  if (b == 0) return a;
  return gcd_fast(b, a % b);
}

unsigned long long lcm_fast(unsigned a, unsigned b) {
  if (a == 0 && b == 0) return 0;
  unsigned long long gcd = gcd_fast(a, b);
  return a / gcd * b;
}

void test_solution() {
  assert(lcm_fast(6, 8) == 24);
  assert(lcm_fast(8, 6) == 24);
  assert(lcm_fast(28851538, 1183019) == 1933053046);
  assert(lcm_fast(28851538, 1183019) == lcm_fast(1183019, 28851538));

  unsigned n = 1000;
  unsigned max = 1000;
  unsigned a, b;

  for (unsigned i = 0; i < n; ++i) {
    a = 1 + rand() % max;
    b = 1 + rand() % max;

    assert(lcm_fast(a, b) == lcm_naive(a, b));
    assert(lcm_fast(a, b) == lcm_fast(b, a));
  }
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  // test_solution();
  return 0;
}
