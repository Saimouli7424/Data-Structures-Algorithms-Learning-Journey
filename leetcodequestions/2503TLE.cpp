//Using BFS
//Maximum Number of Points From Grid Queries(Hard)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        if (queries.empty() || grid.empty()) return {};

        vector<int> qcount;
        int row = grid.size();
        int col = grid[0].size();
        int qsize = queries.size();

        for (int i = 0; i < qsize; i++) {
            int cval = counting(grid, queries[i], row, col);
            qcount.push_back(cval);
        }

        return qcount;
    }

    int counting(vector<vector<int>>& grid, int checkval, int row, int col) 
    {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        /*
            This creates a 2D vector with row number of rows, where each row is initialized with a 1D vector of size col.
            If row = 3 and col = 5, it creates:
            visited = {
                {false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, false, false, false}
            }
        */
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        queue<pair<int, int>> q;

        if (grid[0][0] < checkval) {
            q.push({0, 0});
            visited[0][0] = true;
        }

        while (!q.empty()) 
        {
            auto [rowi, coli] = q.front();
            q.pop();

            count++;

            for (auto [dx, dy] : directions) {
                int newRow = rowi + dx;
                int newCol = coli + dy;

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !visited[newRow][newCol]) 
                {
                    if (grid[newRow][newCol] < checkval) { // ✅ Only push if condition is met
                        q.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
        return count;
    }
};

// ✅ Main Function for Testing
int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 2, 4},
        {3, 4, 3},
        {2, 1, 2}
    };

    vector<int> queries = {2, 3, 4};

    vector<int> result = sol.maxPoints(grid, queries);

    cout << "Results: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Test Case:
// Input: grid = [[1,2,4],[3,4,3],[2,1,2]], queries = [2,3,4]
// Output: [4, 4, 1]
// Explanation:
// - For query 2, the points (0,0), (0,1), (1,0), and (2,0) are valid. So the answer is 4.
// - For query 3, the points (0,0), (0,1), (1,0), and (2,0) are valid. So the answer is 4.
 //- For query 4, the point (2,2) is valid. So the answer is 1.
 //Note:
 //The length of `grid` is in the range `[1, 50]`.
 //The length of `grid[i]` is in the range `[1, 50]`.
 //The maximum integer in `grid[i][j]` is in the range `[0, 109]`.
 //The length of `queries` is in the range `[1, 100]`.