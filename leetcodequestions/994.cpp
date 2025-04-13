//Rotting Oranges(Medium)
//Using Breadth First Search
//Time Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int count = 0;
        int freshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();
        bool onefound = false;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;

        // Initial scan: add all rotten oranges to the queue and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges to rot

        // BFS: Process all rotten oranges
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                pair<int, int> data = q.front();
                q.pop();
                int r = data.first;
                int c = data.second;

                for (auto it : directions) {
                    int nr = r + it[0];
                    int nc = c + it[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        onefound = true;
                        q.push({nr, nc});
                        grid[nr][nc] = 2; // Rotten the adjacent fresh orange
                        freshOranges--;
                    }
                }
            }
            if (onefound) {
                count++; // Increment the time after processing one level of BFS
                onefound = false;
            }
        }

        // If there are still fresh oranges, return -1 because they couldn't be rotted
        return freshOranges == 0 ? count : -1;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,2}};
    cout << "Test Case 1: " << sol.orangesRotting(grid1) << endl;  // Expected Output: 4

    // Test case 2
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Test Case 2: " << sol.orangesRotting(grid2) << endl;  // Expected Output: -1

    // Test case 3
    vector<vector<int>> grid3 = {{0,2}};
    cout << "Test Case 3: " << sol.orangesRotting(grid3) << endl;  // Expected Output: 0

    // Test case 4
    vector<vector<int>> grid4 = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    cout << "Test Case 4: " << sol.orangesRotting(grid4) << endl;  // Expected Output: -1

    // Test case 5
    vector<vector<int>> grid5 = {{2,2,2},{2,1,2},{2,2,2}};
    cout << "Test Case 5: " << sol.orangesRotting(grid5) << endl;  // Expected Output: 1

    return 0;
}
