//Path with Maximum Gold(Medium)
//using DFS+BACKTRACKING
//time complexity: O(4^(m*n))
// space complexity: O(m*n)
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        int n = grid.size();
        int m = grid[0].size();

        // DFS function with backtracking
        function<int(int, int)> dfs = [&](int r, int c) {
            if (r >= n || c >= m || r < 0 || c < 0 || grid[r][c] == 0) return 0;

            int currGold = grid[r][c];
            grid[r][c] = 0;  // mark as visited

            int tempGold = max({
                dfs(r - 1, c),
                dfs(r + 1, c),
                dfs(r, c - 1),
                dfs(r, c + 1)
            });

            grid[r][c] = currGold; // backtrack
            return currGold + tempGold;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(i, j));
                }
            }
        }
        return maxGold;
    }
};

// --------------------- MAIN FUNCTION ---------------------
int main() {
    Solution sol;

    // ✅ Test Case 1
    vector<vector<int>> grid1 = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };
    cout << "Test Case 1 Output: " << sol.getMaximumGold(grid1) << endl; // Expected: 24

    // ✅ Test Case 2
    vector<vector<int>> grid2 = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };
    cout << "Test Case 2 Output: " << sol.getMaximumGold(grid2) << endl; // Expected: 28

    // ✅ Test Case 3
    vector<vector<int>> grid3 = {
        {0, 0, 0},
        {0, 10, 0},
        {0, 0, 0}
    };
    cout << "Test Case 3 Output: " << sol.getMaximumGold(grid3) << endl; // Expected: 10

    return 0;
}
