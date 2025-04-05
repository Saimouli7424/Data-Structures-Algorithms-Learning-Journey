//K Highest Ranked Items Within a Price Range(Medium)
//using BFS and tuple
//tuple is a container which can hold a fixed number of elements of different types

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<tuple<int, int, int>> q; // {r, c, distance}
        vector<tuple<int, int, int, int>> items; // {distance, price, row, col}

        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();

            int val = grid[r][c];
            if (val >= pricing[0] && val <= pricing[1]) {
                items.emplace_back(dist, val, r, c);
            }

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] != 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        sort(items.begin(), items.end());

        vector<vector<int>> result;
        for (int i = 0; i < min(k, (int)items.size()); ++i) {
            auto [dist, price, r, c] = items[i];
            result.push_back({r, c});
        }

        return result;
    }
};

// 🔹 Helper to print result
void printResult(const vector<vector<int>>& result) {
    for (const auto& pos : result) {
        cout << "[" << pos[0] << ", " << pos[1] << "]" << endl;
    }
}

int main() {
    // Sample input
    vector<vector<int>> grid = {
        {1, 2, 0, 1},
        {1, 3, 0, 1},
        {0, 4, 5, 1}
    };

    vector<int> pricing = {2, 5};         // Price range: [2, 5]
    vector<int> start = {0, 0};           // Starting position
    int k = 3;                            // Number of top items to find

    Solution sol;
    vector<vector<int>> result = sol.highestRankedKItems(grid, pricing, start, k);

    // Output
    cout << "Top " << k << " ranked items:" << endl;
    printResult(result);

    return 0;
}
