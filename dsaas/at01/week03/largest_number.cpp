#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool comparitor2(const string& s1, const string& s2) {
  string c1 = s1;
  string c2 = s2;
  char s3;

  if (s1.size() < s2.size()) {
    c1 = s1;
    c2 = s2.substr(0, s1.size());
    s3 = s2.at(s1.size());
  } else if (s2.size() < s1.size()) {
    c1 = s1.substr(0, s2.size());
    c2 = s2;
    s3 = s1.at(s2.size());
  }

  if (c1 == c2) {
    if (s1.size() < s2.size())
      return s3 < s1.at(0);
    else if (s2.size() < s1.size())
      return s3 > s2.at(0);
  }

  return c1 > c2;
}

bool comparitor(const string& s1, const string& s2) {
  string c1 = s1;
  string c2 = s2;

  if (s1.size() < s2.size()) {
    while (c1.size() != c2.size())
      c1 += "9";
  } else if (s2.size() < s1.size()) {
    while (c1.size() != c2.size())
      c2 += "9";
  }

  return c1 > c2;
}

string largest_number(vector<string> a) {
  if (a.size() == 1) return a.at(0);

  std::sort(a.begin(), a.end(), comparitor2);

  std::stringstream ss;

  string result;

  for (size_t i = 0; i < a.size(); i++) {
    // if (result + a.at(i) > a.at(i) + result)
    //   result += a.at(i);
    // else
    //   result = a.at(i) + result;
    ss << a.at(i);
  }

  ss >> result;
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
