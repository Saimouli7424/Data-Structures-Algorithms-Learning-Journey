//Minimum Spanning Tree
//using priority queue
// Time Complexity: O(E log V)
// Space Complexity: O(V)
// where E is the number of edges and V is the number of vertices
//we are pushing into the priority queue in the format of wt,edge and finding up total sum
//using Prim's algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);

        // weight, node
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node]) continue;
            visited[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};

void addEdge(vector<vector<int>> adj[], int u, int v, int wt) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt}); // Because it's an undirected graph
}

int main() {
    Solution obj;

    // Test Case 1
    int V1 = 4;
    vector<vector<int>> adj1[V1];
    addEdge(adj1, 0, 1, 1);
    addEdge(adj1, 1, 2, 2);
    addEdge(adj1, 2, 3, 3);
    addEdge(adj1, 0, 3, 4);
    cout << "MST Total Weight (Test 1): " << obj.spanningTree(V1, adj1) << endl;

    // Test Case 2
    int V2 = 5;
    vector<vector<int>> adj2[V2];
    addEdge(adj2, 0, 1, 2);
    addEdge(adj2, 0, 3, 6);
    addEdge(adj2, 1, 2, 3);
    addEdge(adj2, 1, 3, 8);
    addEdge(adj2, 1, 4, 5);
    addEdge(adj2, 2, 4, 7);
    cout << "MST Total Weight (Test 2): " << obj.spanningTree(V2, adj2) << endl;

    // Test Case 3
    int V3 = 3;
    vector<vector<int>> adj3[V3];
    addEdge(adj3, 0, 1, 10);
    addEdge(adj3, 1, 2, 5);
    addEdge(adj3, 0, 2, 1);
    cout << "MST Total Weight (Test 3): " << obj.spanningTree(V3, adj3) << endl;

    return 0;
}

