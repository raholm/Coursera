#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Item {
  int weight;
  int value;
  double value_per_weight;

  bool operator<(const Item& other) const {
    return value_per_weight > other.value_per_weight;
  }

};

template<typename T>
void print(const vector<T>& v) {
  for (auto const& e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  if (capacity <= 0) return 0;

  double value = 0.0;

  vector<Item> items(weights.size());

  for (unsigned i = 0; i < weights.size(); ++i) {
    Item item;
    item.weight = weights.at(i);
    item.value = values.at(i);
    item.value_per_weight = (double) item.value / item.weight;
    items.at(i) = item;
  }

  std::sort(items.begin(), items.end());

  unsigned current_item = 0;

  while (capacity > 0) {
    if (current_item >= items.size()) break;

    Item& item = items.at(current_item);

    if (item.weight == 0)
      ++current_item;
    else {
      --item.weight;
      --capacity;
      value += item.value_per_weight;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
