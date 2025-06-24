//Topological sort using Depth First Search (DFS) algorithm
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space Complexity: O(V) for the recursion stack and visited array
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(node);  // Add to stack after visiting all neighbors
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> result;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
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

    vector<int> topo1 = sol.topoSort(V1, adj1);
    cout << "Topological Sort (Test Case 1): ";
    for (int node : topo1) cout << node << " ";
    cout << endl;

    // Test Case 2
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    adj2[0].push_back(1);
    adj2[0].push_back(2);
    adj2[1].push_back(3);
    adj2[2].push_back(3);

    vector<int> topo2 = sol.topoSort(V2, adj2);
    cout << "Topological Sort (Test Case 2): ";
    for (int node : topo2) cout << node << " ";
    cout << endl;

    return 0;
}
