//Find the Minimum Area to Cover All Ones I(Medium)
//using basic matrix traversal
//Time Complexity: O(m*n)
//space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int top = INT_MAX, left = INT_MAX, bottom = -1, right = -1;

        for (int i = 0; i < m; i++) {
            auto &row = grid[i];

            // find first 1 in the row
            auto itLeft = find(row.begin(), row.end(), 1);
            if (itLeft == row.end()) continue; // no 1 in this row → skip

            // find last 1 in the row (reverse search)
            auto itRight = find(row.rbegin(), row.rend(), 1);

            int jLeft = itLeft - row.begin();
            int jRight = n - 1 - (itRight - row.rbegin());

            // update boundaries
            top = min(top, i);
            bottom = max(bottom, i);
            left = min(left, jLeft);
            right = max(right, jRight);

            // early exit if whole grid is covered
            if (top == 0 && left == 0 && bottom == m - 1 && right == n - 1)
                return (bottom - top + 1) * (right - left + 1);
        }

        return (bottom - top + 1) * (right - left + 1);
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<vector<int>> grid1 = {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,0,0},
        {0,0,0,0}
    };
    cout << "Test 1 → " << sol.minimumArea(grid1) << " (Expected: 6)" << endl;

    // Test 2
    vector<vector<int>> grid2 = {
        {0,0,0},
        {0,0,0},
        {1,1,1},
    };
    cout << "Test 2 → " << sol.minimumArea(grid2) << " (Expected: 3)" << endl;

    // Test 3
    vector<vector<int>> grid3 = {
        {1,0,0},
        {0,0,0},
        {0,0,1}
    };
    cout << "Test 3 → " << sol.minimumArea(grid3) << " (Expected: 9)" << endl;

    return 0;
}
