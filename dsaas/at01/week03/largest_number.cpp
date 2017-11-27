#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool comparitor(const string& s1, const string& s2) {
  string c1 = s1;
  string c2 = s2;

  if (c1.size() < c2.size()) {
    while (c1.size() != c2.size())
      c1 += "9";
  } else if (c2.size() < c1.size()) {
    while (c1.size() != c2.size())
      c2 += "9";
  }

  return c1 > c2;
}

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end(), comparitor);

  std::stringstream ret;

  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << std::endl;
}
