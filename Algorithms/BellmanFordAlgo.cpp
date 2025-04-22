//BellmanFord Algorithm must be directed graph when it consists of negative edges
//Time Complexity: O(V*E) where V is the number of vertices and E is the number of edges
//Space Complexity: O(V) where V is the number of vertices
//Bellman-Ford are used to detect the negative cycle and find the shortest path from source node to all other nodes with negative edges and directed graph
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void bellmanFord(int V, vector<tuple<int, int, int>> &edges, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Relax edges V-1 times because src is already 0 so excluding that v-1times
    for (int i = 1; i < V; ++i) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto &[u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cout << "Negative cycle detected!\n";
            return;
        }
    }

    cout << "Distances from source " << src << ": ";
    for (int d : dist)
        cout << (d == INF ? "INF" : to_string(d)) << " ";
    cout << "\n";
}

int main() {
    cout << "----- Test Case 1: Positive & Negative Edges -----\n";
    int V1 = 5;
    vector<tuple<int, int, int>> edges1 = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5},
        {1, 4, -4}, {2, 3, -3}, {2, 4, 9},
        {3, 1, -2}, {4, 0, 2}, {4, 3, 7}
    };
    bellmanFord(V1, edges1, 0);

    cout << "\n----- Test Case 2: No Negative Edges -----\n";
    int V2 = 4;
    vector<tuple<int, int, int>> edges2 = {
        {0, 1, 1}, {0, 2, 4}, {1, 2, 2}, {1, 3, 6}, {2, 3, 3}
    };
    bellmanFord(V2, edges2, 0);

    cout << "\n----- Test Case 3: Negative Cycle -----\n";
    int V3 = 3;
    vector<tuple<int, int, int>> edges3 = {
        {0, 1, 1}, {1, 2, -1}, {2, 0, -1}
    };
    bellmanFord(V3, edges3, 0);

    return 0;
}
