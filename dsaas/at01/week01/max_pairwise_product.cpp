#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

unsigned long long max_pairwise_product_slow(const vector<unsigned>& numbers) {
  unsigned long long result = 0;
  unsigned n = numbers.size();
  unsigned long long prod;

  for (unsigned i = 0; i < n; ++i) {
    for (unsigned j = i + 1; j < n; ++j) {
      prod = (unsigned long long) numbers.at(i) * numbers.at(j);

      if (prod > result) {
        result = prod;
      }
    }
  }

  return result;
}

unsigned long long max_pairwise_product_fast(const vector<unsigned>& numbers) {
  unsigned n = numbers.size();

  int max_index1 = 0, max_index2 = -1;

  for (unsigned i = 1; i < n; ++i) {
    if (numbers.at(i) > numbers.at(max_index1))
      max_index1 = i;
  }

  for (unsigned i = 0; i < n; ++i) {
    if (i != max_index1 && (max_index2 == -1 || numbers.at(i) > numbers.at(max_index2)))
      max_index2 = i;
  }

  return (unsigned long long) numbers.at(max_index1) * numbers.at(max_index2);
}

int main() {
  int n;
  cin >> n;

  vector<unsigned> numbers(n);

  for (unsigned i = 0; i < n; ++i) {
    cin >> numbers.at(i);
  }

  unsigned long long result = max_pairwise_product_fast(numbers);
  cout << result << "\n";
  return 0;
}
