//Check if Grid can be Cut into Sections(Medium)
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> xs;
    vector<pair<int, int>> ys;

    for (const vector<int>& rectangle : rectangles) {
      const int startX = rectangle[0];
      const int startY = rectangle[1];
      const int endX = rectangle[2];
      const int endY = rectangle[3];
      xs.emplace_back(startX, endX);
      ys.emplace_back(startY, endY);
    }

    return max(countMerged(xs), countMerged(ys)) >= 3;
  }

 private:
  int countMerged(vector<pair<int, int>>& intervals) {
    int count = 0;
    int prevEnd = 0;

    sort(intervals.begin(), intervals.end());

    for (const auto& [start, eend] : intervals) {
      if (start < prevEnd) {
        prevEnd = max(prevEnd, eend);
      } else {
        prevEnd = eend;
        ++count;
      }
    }

    return count;
  }
};

int main() {
  Solution solution;
  int n;
  cout << "Enter number of rectangles: ";
  cin >> n;
  vector<vector<int>> rectangles(n, vector<int>(4));
  cout << "Enter rectangle coordinates (startX, startY, endX, endY):" << endl;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 4; ++j)
      cin >> rectangles[i][j];

  if (solution.checkValidCuts(n, rectangles))
    cout << "Valid cuts possible" << endl;
  else
    cout << "Valid cuts not possible" << endl;

  return 0;
}

// Test Case:
// Enter number of rectangles: 3
// Enter rectangle coordinates (startX, startY, endX, endY):
// 0 0 1 1
// 1 0 2 1
// 2 0 3 1
// Valid cuts possible
