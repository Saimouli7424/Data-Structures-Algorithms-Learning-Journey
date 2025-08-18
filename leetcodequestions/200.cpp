//Number of Islands(Medium)
//Either using DFS or DSU
//time complexity: O(m*n)
//space complexity: O(m*n) for DFS, O(m*n) for DSU
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        DSU ds(m * n);
        int landCount = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}}; // only down & right to avoid double counting

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    landCount++; // count as a new island
                    int id1 = i * n + j;

                    for (auto &d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni < m && nj < n && grid[ni][nj] == '1') {
                            int id2 = ni * n + nj;
                            if (ds.find(id1) != ds.find(id2)) {
                                ds.unite(id1, id2);
                                landCount--; // merge islands
                            }
                        }
                    }
                }
            }
        }
        return landCount;
    }
};

// ---------- MAIN FUNCTION WITH TESTCASES ----------
int main() {
    Solution sol;

    // Testcase 1
    vector<vector<char>> grid1 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Testcase 1 Output: " << sol.numIslands(grid1) << endl; // Expected 3

    // Testcase 2
    vector<vector<char>> grid2 = {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };
    cout << "Testcase 2 Output: " << sol.numIslands(grid2) << endl; // Expected 1

    // Testcase 3
    vector<vector<char>> grid3 = {
        {'1','0','1','0'},
        {'0','0','0','0'},
        {'1','0','1','0'}
    };
    cout << "Testcase 3 Output: " << sol.numIslands(grid3) << endl; // Expected 4

    return 0;
}

/*
 //using DFS
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='#' || grid[r][c]=='0')return;

        grid[r][c] = '#';
        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
*/