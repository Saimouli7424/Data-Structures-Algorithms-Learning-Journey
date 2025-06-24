//Course Schedule II(Medium)
//using dfs+topological sort
// Time complexity: O(V+E), where V is the number of vertices and E is the number of edges.
// Space complexity: O(V+E), where V is the number of vertices and E is

#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            int u = pre[1], v = pre[0]; // u → v (u is a prereq of v)
            adj[u].push_back(v);
        }

        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> result;
        bool hasCycle = false;

        function<void(int)> dfs = [&](int node) {
            if (visited[node] == 1) {
                hasCycle = true;
                return;
            }
            if (visited[node] == 2) return;

            visited[node] = 1;
            for (int neighbor : adj[node]) {
                dfs(neighbor);
                if (hasCycle) return;
            }

            visited[node] = 2;
            result.push_back(node);
        };

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                dfs(i);
                if (hasCycle) return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 2;
    vector<vector<int>> prereq1 = {{1, 0}};
    cout << "Test Case 1: ";
    printVector(sol.findOrder(numCourses1, prereq1)); // Output: [0,1]

    // Test Case 2 (cycle)
    int numCourses2 = 2;
    vector<vector<int>> prereq2 = {{1, 0}, {0, 1}};
    cout << "Test Case 2: ";
    printVector(sol.findOrder(numCourses2, prereq2)); // Output: []

    // Test Case 3
    int numCourses3 = 4;
    vector<vector<int>> prereq3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Test Case 3: ";
    printVector(sol.findOrder(numCourses3, prereq3)); // Output: [0,1,2,3] or [0,2,1,3]

    return 0;
}
