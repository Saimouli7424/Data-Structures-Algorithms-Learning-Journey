//Find Eventual Safe States(Medium)
//Using reverse Kahn's Algorithm for Topological Sorting and dfs
//time complexity: O(V + E) where V is the number of vertices and E is the number of edges
//space complexity: O(N) where N is the number of nodes in the graph

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> reverseList(V);
        vector<int> outDegree(V, 0);

        // Build reverse graph and calculate outdegree
        for (int u = 0; u < V; ++u) {
            for (int v : graph[u]) {
                reverseList[v].push_back(u);
                outDegree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (outDegree[i] == 0) q.push(i);
        }

        vector<int> isSafe(V, 0);
        while (!q.empty()) {
            int node = q.front(); q.pop();
            isSafe[node] = 1;
            for (int prev : reverseList[node]) {
                outDegree[prev]--;
                if (outDegree[prev] == 0) q.push(prev);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (isSafe[i]) result.push_back(i);
        }

        return result;
    }
};

// Function to print result
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function with test cases
int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> graph1 = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };
    cout << "Test Case 1: ";
    printVector(sol.eventualSafeNodes(graph1)); // Expected: 2 4 5 6

    // Test Case 2 (no cycles, all safe)
    vector<vector<int>> graph2 = {
        {},
        {0},
        {1},
        {2}
    };
    cout << "Test Case 2: ";
    printVector(sol.eventualSafeNodes(graph2)); // Expected: 0 1 2 3

    // Test Case 3 (cycle between 0 and 1)
    vector<vector<int>> graph3 = {
        {1},
        {0},
        {3},
        {}
    };
    cout << "Test Case 3: ";
    printVector(sol.eventualSafeNodes(graph3)); // Expected: 2 3

    return 0;
}
