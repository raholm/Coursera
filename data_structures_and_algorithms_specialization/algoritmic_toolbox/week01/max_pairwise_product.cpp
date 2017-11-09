#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int max_pairwise_product_slow(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  int prod;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      prod = numbers.at(i) * numbers.at(j);

      if (prod > result) {
        result = prod;
      }
    }
  }

  return result;
}

int main() {
  int n;
  cin >> n;

  vector<int> numbers(n);

  for (int i = 0; i < n; ++i) {
    cin >> numbers.at(i);
  }

  int result = max_pairwise_product_slow(numbers);
  cout << result << "\n";
  return 0;
}
