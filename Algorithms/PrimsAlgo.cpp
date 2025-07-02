//Minimum Spanning Tree
//using priority queue
// Time Complexity: O(E log V)
// Space Complexity: O(V)
// where E is the number of edges and V is the number of vertices
//we are pushing into the priority queue in the format of wt,edge and finding up total sum
//saving the MST in vector
//using Prim's algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns MST edges and total weight as a pair
    pair<vector<tuple<int, int, int>>, int> primsMST(int V, vector<vector<int>> adj[]) {
        vector<bool> inMST(V, false);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Min-heap: {weight, currentNode, parentNode}
        pq.push({0, 0, -1});

        vector<tuple<int, int, int>> mstEdges;
        int totalWeight = 0;

        while (!pq.empty()) {
            auto [wt, node, parent] = pq.top();
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;
            totalWeight += wt;

            if (parent != -1) {
                mstEdges.push_back({parent, node, wt});
            }

            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWt = neighbor[1];

                if (!inMST[adjNode]) {
                    pq.push({edgeWt, adjNode, node});
                }
            }
        }

        return {mstEdges, totalWeight};
    }
};

void addEdge(vector<vector<int>> adj[], int u, int v, int wt) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

int main() {
    Solution obj;

    int V = 5;
    vector<vector<int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);

    auto [mst, totalWeight] = obj.primsMST(V, adj);

    cout << "Edges in MST:\n";
    for (auto &[u, v, wt] : mst) {
        cout << u << " - " << v << " (Weight: " << wt << ")\n";
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}

