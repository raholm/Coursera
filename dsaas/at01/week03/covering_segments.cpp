#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;

  bool operator<(const Segment& other) const {
    return end < other.end;
  }

};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  std::sort(segments.begin(), segments.end());

  unsigned current_pos = segments.at(0).end;
  points.push_back(current_pos);

  for (size_t i = 1; i < segments.size(); ++i) {
    Segment& segment = segments.at(i);

    if (segment.start > current_pos) {
      current_pos = segment.end;
      points.push_back(current_pos);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
