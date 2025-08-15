#include <bits/stdc++.h>
using namespace std;
// Kruskal's Algorithm for Minimum Spanning Tree (MST)
// Time Complexity: O(E log E + E * α(V)), where α is the Inverse Ackermann function
// Space Complexity: O(V + E)
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findParent(parent[n]); // path compression
    }

    void unionBySize(int x, int y) {
        int upX = findParent(x), upY = findParent(y);
        if (upX == upY) return;

        if (size[upX] < size[upY]) {
            parent[upX] = upY;
            size[upY] += size[upX];
        } else {
            parent[upY] = upX;
            size[upX] += size[upY];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int, pair<int, int>>> adjList;

        // Store edges as (weight, (u,v))
        for (int i = 0; i < edges.size(); i++) {
            int wt = edges[i][2], u = edges[i][0], v = edges[i][1];
            adjList.push_back({wt, {u, v}});
        }

        // Sort by weight
        sort(adjList.begin(), adjList.end());

        DSU dsu(V);
        int wt = 0;

        for (int i = 0; i < adjList.size(); i++) {
            int weight = adjList[i].first;
            int u = adjList[i].second.first;
            int v = adjList[i].second.second;

            if (dsu.findParent(u) != dsu.findParent(v)) {
                wt += weight;
                dsu.unionBySize(u, v);
            }
        }
        return wt;
    }
};

int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    cout << "MST Weight = " << sol.spanningTree(V, edges) << endl;

    return 0;
}
