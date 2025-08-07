#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) -
           2 * fruits.back().back();
  }

 private:
  int getTopLeft(const vector<vector<int>>& fruits) {
    const int n = fruits.size();
    int res = 0;
    for (int i = 0; i < n; ++i)
      res += fruits[i][i];
    return res;
  }

  int getTopRight(const vector<vector<int>>& fruits) {
    const int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][n - 1] = fruits[0][n - 1];
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        if (x >= y && !(x == n - 1 && y == n - 1))
          continue;
        for (const auto& [dx, dy] :
             vector<pair<int, int>>{{1, -1}, {1, 0}, {1, 1}}) {
          const int i = x - dx;
          const int j = y - dy;
          if (i < 0 || i == n || j < 0 || j == n)
            continue;
          if (i < j && j < n - 1 - i)
            continue;
          dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
        }
      }
    }
    return dp[n - 1][n - 1];
  }

  int getBottomLeft(const vector<vector<int>>& fruits) {
    const int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[n - 1][0] = fruits[n - 1][0];
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) {
        if (x <= y && !(x == n - 1 && y == n - 1))
          continue;
        for (const auto& [dx, dy] :
             vector<pair<int, int>>{{-1, 1}, {0, 1}, {1, 1}}) {
          const int i = x - dx;
          const int j = y - dy;
          if (i < 0 || i == n || j < 0 || j == n)
            continue;
          if (j < i && i < n - 1 - j)
            continue;
          dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
        }
      }
    }
    return dp[n - 1][n - 1];
  }
};

void test(vector<vector<int>> fruits) {
  Solution sol;
  int result = sol.maxCollectedFruits(fruits);
  cout << "Max collected fruits: " << result << endl;
}

int main() {
  vector<vector<int>> test1 = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };

  vector<vector<int>> test2 = {
      {5, 1, 0},
      {2, 8, 4},
      {0, 3, 6}
  };

  vector<vector<int>> test3 = {
      {0, 2, 4, 1},
      {3, 0, 1, 5},
      {2, 7, 0, 6},
      {8, 3, 2, 9}
  };

  cout << "Test case 1:\n";
  test(test1);

  cout << "\nTest case 2:\n";
  test(test2);

  cout << "\nTest case 3:\n";
  test(test3);

  return 0;
}
