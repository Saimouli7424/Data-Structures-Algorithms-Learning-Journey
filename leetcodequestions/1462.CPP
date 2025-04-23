//Course Schedule IV(Medium)
//using Floyd-Warshall algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<vector<int>> grid(numCourses, vector<int>(numCourses, 1e7)); // Use large number as infinity

        for (auto& i : prerequisites) {
            int u = i[0], v = i[1];
            grid[u][v] = 1;
        }

        for (int i = 0; i < numCourses; i++) grid[i][i] = 0;

        // Floyd-Warshall to find all-pairs shortest path
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }

        for (auto& i : queries) {
            int u = i[0], v = i[1];
            result.push_back(grid[u][v] < 1e7);
        }

        return result;
    }
};

// Helper to print vector<bool>
void printResult(const vector<bool>& res) {
    for (bool b : res) {
        cout << (b ? "true" : "false") << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{0,1},{1,2},{2,3}};
    vector<vector<int>> queries1 = {{0,3},{1,3},{3,0}};
    auto result1 = sol.checkIfPrerequisite(numCourses1, prerequisites1, queries1);
    printResult(result1); // Expected: true true false

    // Test Case 2
    int numCourses2 = 3;
    vector<vector<int>> prerequisites2 = {{0,1},{1,2}};
    vector<vector<int>> queries2 = {{0,2},{2,0},{0,1}};
    auto result2 = sol.checkIfPrerequisite(numCourses2, prerequisites2, queries2);
    printResult(result2); // Expected: true false true

    // Test Case 3
    int numCourses3 = 5;
    vector<vector<int>> prerequisites3 = {{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> queries3 = {{0,4},{4,0},{1,3},{3,1}};
    auto result3 = sol.checkIfPrerequisite(numCourses3, prerequisites3, queries3);
    printResult(result3); // Expected: true false true false

    return 0;
}
