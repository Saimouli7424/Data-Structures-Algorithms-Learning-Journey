//Course Schedule(Medium)
//using DFS and topological sort to check if a cycle exists in the directed graph
// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges
// Space complexity: O(V + E) for the adjacency list and visited array
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjList[v].push_back(u); // v is prerequisite for u
        }

        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
        bool hasCycle = false;

        function<void(int)> dfs = [&](int node) {
            if (visited[node] == 1) {
                hasCycle = true;
                return;
            }
            if (visited[node] == 2) return;

            visited[node] = 1; // mark as visiting
            for (auto neighbor : adjList[node]) {
                dfs(neighbor);
                if (hasCycle) return;
            }
            visited[node] = 2; // mark as visited
        };

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) dfs(i);
            if (hasCycle) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test Case 1: " << (sol.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;
    // Output: true (you can finish 0 → 1)

    // Test Case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test Case 2: " << (sol.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;
    // Output: false (cycle: 0 ↔ 1)

    // Test Case 3
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Test Case 3: " << (sol.canFinish(numCourses3, prerequisites3) ? "true" : "false") << endl;
    // Output: true (0 → 1 → 2 → 3)

    return 0;
}
