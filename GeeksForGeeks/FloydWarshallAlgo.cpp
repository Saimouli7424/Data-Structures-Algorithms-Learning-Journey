#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 100000000;  // Infinity representation
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
    }
};

// Utility to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    const int INF = 100000000;
    for (const auto& row : mat) {
        for (int val : row) {
            if (val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> graph1 = {
        {0, 8, 7, -3},
        {1, 0, -1, 6},
        {9, 5, 0, 5},
        {100000000, 100000000, 100000000, 0}
    };

    cout << "Original Graph 1:\n";
    printMatrix(graph1);

    sol.floydWarshall(graph1);

    cout << "Shortest paths (Graph 1):\n";
    printMatrix(graph1);

    // Test Case 2
    vector<vector<int>> graph2 = {
        {0, 5, 100000000},
        {100000000, 0, 3},
        {2, 100000000, 0}
    };

    cout << "Original Graph 2:\n";
    printMatrix(graph2);

    sol.floydWarshall(graph2);

    cout << "Shortest paths (Graph 2):\n";
    printMatrix(graph2);

    return 0;
}
/*
Original Graph 1:
0 8 7 -3
1 0 -1 6
9 5 0 5
INF INF INF 0

Shortest paths (Graph 1):
0 4 6 -3
1 0 -1 -2
6 2 0 3
INF INF 99999999 0

Original Graph 2:
0 5 INF
INF 0 3
2 INF 0

Shortest paths (Graph 2):
0 5 8
5 0 3
2 7 0

*/