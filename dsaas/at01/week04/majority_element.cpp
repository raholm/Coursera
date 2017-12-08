#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];

  int mid = left + (right - left) / 2;
  int mleft = get_majority_element(a, left, mid);
  int left_counter = 0;

  if (mleft != -1)
    for (unsigned i = left; i < (unsigned) right; ++i)
      if (a.at(i) == mleft) ++left_counter;

  if (left_counter > (right - left) / 2) return mleft;

  int mright = get_majority_element(a, mid, right);
  int right_counter = 0;

  if (mright != -1)
    for (unsigned i = left; i < (unsigned) right; ++i)
      if (a.at(i) == mright) ++right_counter;

  if (right_counter > (right - left) / 2) return mright;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
