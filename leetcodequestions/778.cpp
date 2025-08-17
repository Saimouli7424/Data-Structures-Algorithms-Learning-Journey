//Swim in Rising Water(Hard)
//time complexity: O(nlogn)
//space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int x, int y, vector<vector<int>> &grid, int maxTime, vector<vector<int>> &vis) {
        int n = grid.size();
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] > maxTime || vis[x][y] == 1) return false;
        if (x == n - 1 && y == n - 1) return true;

        vis[x][y] = 1;
        bool possible = dfs(x + 1, y, grid, maxTime, vis) ||
                        dfs(x - 1, y, grid, maxTime, vis) ||
                        dfs(x, y + 1, grid, maxTime, vis) ||
                        dfs(x, y - 1, grid, maxTime, vis);
        return possible;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxVal = 0;
        for (auto &row : grid)
            for (auto v : row)
                maxVal = max(maxVal, v);

        int left = 0, right = maxVal;

        while (left <= right) {
            int mid = (left + right) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if (dfs(0, 0, grid, mid, vis)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 2},
        {1, 3}
    };
    cout << "Test case 1 result: " << sol.swimInWater(grid1) << endl; // Expected: 3

    vector<vector<int>> grid2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    cout << "Test case 2 result: " << sol.swimInWater(grid2) << endl; // Expected: 16

    vector<vector<int>> grid3 = {
        {0, 1, 2},
        {5, 4, 3},
        {6, 7, 8}
    };
    cout << "Test case 3 result: " << sol.swimInWater(grid3) << endl; // Expected: 8

    return 0;
}
