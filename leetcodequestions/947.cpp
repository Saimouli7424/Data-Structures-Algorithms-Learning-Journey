//Most Stones Removed with Same Row or Column(Medium)
//using Union-Find
//time complexity: O(nlogn)
//space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int x, int y){
        int uPx = findParent(x), uPy = findParent(y);
        if(uPx == uPy) return;

        if(size[uPx] < size[uPy]){
            parent[uPx] = uPy;
            size[uPy] += size[uPx];
        } else {
            parent[uPy] = uPx;
            size[uPx] += size[uPy];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        for(auto &i : stones){
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }

        DSU dsu(maxRow + maxCol + 2); // +2 for safe indexing

        unordered_map<int,int> mp;
        for(auto &i : stones){
            int r = i[0];
            int c = i[1] + maxRow + 1; // shift column index
            dsu.unionBySize(r, c);

            mp[r] = 1;
            mp[c] = 1;
        }

        int uniqueParent = 0;
        for(auto &it : mp){
            if(dsu.findParent(it.first) == it.first)
                uniqueParent++;
        }

        return n - uniqueParent;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << "Test case 1: " << sol.removeStones(stones1) << endl; // Expected: 5

    // Test case 2
    vector<vector<int>> stones2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    cout << "Test case 2: " << sol.removeStones(stones2) << endl; // Expected: 3

    // Test case 3
    vector<vector<int>> stones3 = {{0,0},{1,1},{1,0},{2,3},{2,4},{3,3}};
    cout << "Test case 3: " << sol.removeStones(stones3) << endl; // Expected: 4

    return 0;
}

/*
 //the below code using DFS
class Solution {
public:
    vector<bool> visited;
    void dfs(int i, vector<vector<int>> &stones){
        visited[i]=true;
        for(int j=0;j<stones.size();j++){
            //checking stones index and traversing stones by finding same row or col of ith index to jth index values in stones
            if(!visited[j] && (stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])){
                dfs(j,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        visited.resize(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,stones);
                count++;
            }
        }

        return n-count;
    }
};
 */