//Number of Operations to Make Network Connected(Medium)
//using union by size with path compression or we can use BFS,DFS as well
//Time Complexity: O(n + m)
//Space Complexity: O(n + m)
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]); // path compression
    }

    bool unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return false; // already connected
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If not enough cables
        if ((int)connections.size() < n - 1) return -1;

        DSU dsu(n);
        for (auto &edge : connections) {
            dsu.unionBySize(edge[0], edge[1]);
        }

        // Count components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findParent(i) == i) components++;
        }

        // To connect components, we need (components - 1) operations
        return components - 1;
    }
};

// ------------------ TESTING ------------------
int main() {
    Solution sol;

    // Testcase 1
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1},{0,2},{1,2}};
    cout << "Test 1 Output: " << sol.makeConnected(n1, connections1) << "\n";
    // Expected 1

    // Testcase 2
    int n2 = 6;
    vector<vector<int>> connections2 = {{0,1},{0,2},{0,3},{1,2}};
    cout << "Test 2 Output: " << sol.makeConnected(n2, connections2) << "\n";
    // Expected -1

    // Testcase 3
    int n3 = 5;
    vector<vector<int>> connections3 = {{0,1},{0,2},{3,4},{2,3}};
    cout << "Test 3 Output: " << sol.makeConnected(n3, connections3) << "\n";
    // Expected 0 (already connected)

    return 0;
}
