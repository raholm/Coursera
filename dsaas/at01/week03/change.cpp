#include <iostream>
#include <cassert>

unsigned get_change(int m) {
  unsigned num_coins = 0;

  while (m - 10 >= 0) {
    m -= 10;
    ++num_coins;
  }

  while (m - 5 >= 0) {
    m -= 5;
    ++num_coins;
  }

  while (m - 1 >= 0) {
    m -= 1;
    ++num_coins;
  }

  return num_coins;
}

void test_solution() {
  assert(get_change(0) == 0);
  assert(get_change(1) == 1);
  assert(get_change(2) == 2);
  assert(get_change(3) == 3);
  assert(get_change(5) == 1);
  assert(get_change(7) == 3);
  assert(get_change(10) == 1);
  assert(get_change(11) == 2);
  assert(get_change(16) == 3);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  test_solution();
}
