//Directed Graph Cycle
//can use kahns algorithm or //DFS based approach

#include <iostream>
#include <vector>
using namespace std;


//below approach is using DFS
//it uses 3 states for each node: 0 = unvisited, 1 = visiting, 2 = visited
//if we find a node that is in the visiting state, it means we have found a
class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &visited) {
        if (visited[node] == 1) return true;  // cycle found (back edge)
        if (visited[node] == 2) return false; // already processed

        visited[node] = 1; // mark as visiting
        for (auto neighbor : adjlist[node]) {
            if (dfs(neighbor, adjlist, visited)) return true;
        }
        visited[node] = 2; // mark as processed
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> visited(V, 0);
        vector<vector<int>> adjlist(V);
        
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adjlist[u].push_back(v);
        }

        for (int i = 0; i < V; ++i) {
            if (visited[i] == 0) {
                if (dfs(i, adjlist, visited)) return true;
            }
        }
        return false;
    }
};

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    Solution sol;

    // Test case 1: No cycle
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    cout << "Test Case 1 (No Cycle): " << (sol.isCyclic(4, edges1) ? "Cycle Detected" : "No Cycle") << endl;

    // Test case 2: Contains a cycle (2 → 1 → 2)
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 1}};
    cout << "Test Case 2 (Cycle): " << (sol.isCyclic(3, edges2) ? "Cycle Detected" : "No Cycle") << endl;

    // Test case 3: Multiple components, one with a cycle
    vector<vector<int>> edges3 = {{0, 1}, {2, 3}, {3, 4}, {4, 2}};
    cout << "Test Case 3 (Cycle in a component): " << (sol.isCyclic(5, edges3) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}

/*
//using KAHN'S ALGORITHM
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and compute indegrees
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push nodes with 0 indegree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If not all nodes were processed, there is a cycle
        return count != V;
    }
};

*/
