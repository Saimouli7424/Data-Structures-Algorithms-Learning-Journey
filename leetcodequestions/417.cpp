// Pacific Atlantic Water Flow(Medium)
//using BFS
//time comomplexity: O(m*n)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // BFS from Pacific and Atlantic
        for (int i = 0; i < m; ++i) {
            bfs(matrix, pacific, i, 0);   // Pacific BFS from left column
            bfs(matrix, atlantic, i, n - 1); // Atlantic BFS from right column
        }

        for (int j = 0; j < n; ++j) {
            bfs(matrix, pacific, 0, j);   // Pacific BFS from top row
            bfs(matrix, atlantic, m - 1, j); // Atlantic BFS from bottom row
        }

        // Find common cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        // Sort the result in lexicographical order (row first then column)
        sort(result.begin(), result.end());
        return result;
    }

private:
    // Helper function to perform BFS and mark reachable cells
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        vector<int> dirs = {-1, 0, 1, 0, -1};  // Directions: up, right, down, left

        while (!q.empty()) {
            auto [curX, curY] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = curX + dirs[i], ny = curY + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !visited[nx][ny] && matrix[nx][ny] >= matrix[curX][curY]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    vector<vector<int>> result1 = sol.pacificAtlantic(matrix1);
    cout << "Test Case 1:" << endl;
    for (auto& cell : result1) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {3, 2, 1}
    };
    vector<vector<int>> result2 = sol.pacificAtlantic(matrix2);
    cout << "Test Case 2:" << endl;
    for (auto& cell : result2) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;

    // Test Case 3
    vector<vector<int>> matrix3 = {
        {2, 1},
        {1, 2}
    };
    vector<vector<int>> result3 = sol.pacificAtlantic(matrix3);
    cout << "Test Case 3:" << endl;
    for (auto& cell : result3) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;

    return 0;
}
