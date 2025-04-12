//Unique Paths II(Medium)
//using Dynamic Programming
//Time Complexity: O(m*n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                else if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0 && i > 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Test Case 1 Output: " << sol.uniquePathsWithObstacles(grid1) << endl; // Expected: 2

    // Test Case 2
    vector<vector<int>> grid2 = {
        {0, 1, 0, 0}
    };
    cout << "Test Case 2 Output: " << sol.uniquePathsWithObstacles(grid2) << endl; // Expected: 0

    // Test Case 3
    vector<vector<int>> grid3 = {
        {0, 0},
        {1, 0}
    };
    cout << "Test Case 3 Output: " << sol.uniquePathsWithObstacles(grid3) << endl; // Expected: 1

    return 0;
}
