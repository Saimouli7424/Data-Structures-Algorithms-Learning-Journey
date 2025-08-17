//Making A Large Island(Hard)
//using Disjoint Set Union(DSU) to find connected components
//Time Complexity: O(n^2 * log(n^2))
//Space Complexity: O(n^2)
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
    }

    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int x, int y){
        int uPx = findParent(x), uPy = findParent(y);
        if(uPx == uPy) return;

        if(size[uPx]<size[uPy]){
            parent[uPx] = uPy;
            size[uPy]+=size[uPx];
        } else {
            parent[uPy] = uPx;
            size[uPx]+=size[uPy];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        vector<int> zeroCells;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

        // Step 1: Union all 1-cells
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr = i+dir[k][0], nc = j+dir[k][1];
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            dsu.unionBySize(i*n+j, nr*n+nc);
                        }
                    }
                } else {
                    zeroCells.push_back(i*n+j);
                }
            }
        }

        if(zeroCells.size()<=1) return n*n; // all ones or only one zero

        int result = 0;

        // Step 2: Check each zero-cell
        for(int x: zeroCells){
            int i = x / n, j = x % n;
            int sum = 1; // flip 0->1
            unordered_set<int> seen;
            for(int k=0;k<4;k++){
                int nr = i+dir[k][0], nc = j+dir[k][1];
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                    int root = dsu.findParent(nr*n + nc);
                    if(!seen.count(root)){
                        sum += dsu.size[root];
                        seen.insert(root);
                    }
                }
            }
            result = max(result,sum);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1,0},{0,1}};
    cout << "Test case 1: " << sol.largestIsland(grid1) << endl; // Expected: 3

    vector<vector<int>> grid2 = {{1,1},{1,0}};
    cout << "Test case 2: " << sol.largestIsland(grid2) << endl; // Expected: 4

    vector<vector<int>> grid3 = {{1,1},{1,1}};
    cout << "Test case 3: " << sol.largestIsland(grid3) << endl; // Expected: 4

    return 0;
}
