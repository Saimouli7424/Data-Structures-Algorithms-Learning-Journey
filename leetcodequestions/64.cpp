//Minimum Path Sum(Medium)
//using Dynamic Programming
//Time Complexity: O(m*n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j > 0) {
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                } else if (j == 0 && i > 0) {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                } else if (i > 0 && j > 0) {
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Test Case 1 Output: " << sol.minPathSum(grid1) << endl;  // Expected: 7

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Test Case 2 Output: " << sol.minPathSum(grid2) << endl;  // Expected: 12

    vector<vector<int>> grid3 = {
        {5}
    };
    cout << "Test Case 3 Output: " << sol.minPathSum(grid3) << endl;  // Expected: 5

    return 0;
}
