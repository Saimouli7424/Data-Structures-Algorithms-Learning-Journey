//Kahn's Algorithm for Topological Sorting
//using BFS and Indegree technique
//there will be alway a one Node has Indegree 0
//time complexity: O(V+E)
//space complexity: O(N)
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0);

        // Step 1: Compute in-degrees of all nodes
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // Step 2: Add nodes with in-degree 0 to queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: BFS
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Optional: Check for cycle
        if (topoOrder.size() < V) {
            cout << "Cycle detected! Topological sort not possible.\n";
            return {};
        }

        return topoOrder;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int V1 = 6;
    vector<vector<int>> adj1(V1);
    adj1[5].push_back(2);
    adj1[5].push_back(0);
    adj1[4].push_back(0);
    adj1[4].push_back(1);
    adj1[2].push_back(3);
    adj1[3].push_back(1);

    vector<int> result1 = sol.topoSort(V1, adj1);
    cout << "Topological Sort (Test Case 1): ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Test Case 2 (Cycle case)
    int V2 = 3;
    vector<vector<int>> adj2(V2);
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(0); // cycle

    vector<int> result2 = sol.topoSort(V2, adj2);
    cout << "Topological Sort (Test Case 2): ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}
