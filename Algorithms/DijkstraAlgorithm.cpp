
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int adjdist = it.second;

                if (dis + adjdist < dist[adjnode]) {
                    dist[adjnode] = dis + adjdist;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};

// Function to create adjacency list
vector<vector<pair<int, int>>> createGraph(int V, vector<tuple<int, int, int>> edges) {
    vector<vector<pair<int, int>>> adj(V);
    for (auto &[u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove this line for a directed graph
    }
    return adj;
}

int main() {
    Solution sol;

    // Test Case 1
    int V1 = 5;
    vector<tuple<int, int, int>> edges1 = {
        {0, 1, 2}, {0, 3, 1}, {1, 2, 4}, {1, 3, 3}, {3, 4, 6}, {2, 4, 5}
    };
    vector<vector<pair<int, int>>> adj1 = createGraph(V1, edges1);
    int src1 = 0;
    vector<int> result1 = sol.dijkstra(adj1, src1);
    cout << "Shortest distances from node " << src1 << ": ";
    for (int d : result1) cout << d << " ";
    cout << "\n";

    // Test Case 2
    int V2 = 4;
    vector<tuple<int, int, int>> edges2 = {
        {0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 3, 7}
    };
    vector<vector<pair<int, int>>> adj2 = createGraph(V2, edges2);
    int src2 = 0;
    vector<int> result2 = sol.dijkstra(adj2, src2);
    cout << "Shortest distances from node " << src2 << ": ";
    for (int d : result2) cout << d << " ";
    cout << "\n";

    // Test Case 3
    int V3 = 6;
    vector<tuple<int, int, int>> edges3 = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 1}, {1, 3, 2}, {2, 3, 4}, {3, 4, 2}, {4, 5, 6}
    };
    vector<vector<pair<int, int>>> adj3 = createGraph(V3, edges3);
    int src3 = 0;
    vector<int> result3 = sol.dijkstra(adj3, src3);
    cout << "Shortest distances from node " << src3 << ": ";
    for (int d : result3) cout << d << " ";
    cout << "\n";

    return 0;
}

// Shortest distances from node 0: 0 2 5 1 7 
// Shortest distances from node 0: 0 1 3 6 
// Shortest distances from node 0: 0 4 3 5 7 13 
