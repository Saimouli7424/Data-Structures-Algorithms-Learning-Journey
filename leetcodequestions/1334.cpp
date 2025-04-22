//Find the City With the Smallest Number of Neighbors at a Threshold Distance(Medium)
//using Floyd-Warshall algorithm to find the shortest path between all pairs of nodes
//Time complexity: O(n^3), Space complexity: O(n^2)
//optimal solution for the problem is to use Dijkstra's algorithm for each node
//Time complexity: O(n^2 * log(n)), Space complexity: O(n^2)
//but since the number of nodes is small, we can use Floyd-Warshall algorithm
//to find the shortest path between all pairs of nodes
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> grid(n, vector<int>(n, 1e7));

        for (auto i : edges)
        {
            int u = i[0], v = i[1], wt = i[2];
            grid[u][v] = grid[v][u] = wt;
        }

        for (int i = 0; i < n; i++) grid[i][i] = 0;

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }

        //dummy citycount giving as n+1 can give INT_MAX as well
        int citycount = n + 1, city = -1;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] <= distanceThreshold)
                    temp++;
            }
            if (temp <= citycount)
            {
                citycount = temp;
                city = i;
            }
        }
        return city;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{0,1,3},{1,2,1},{2,3,4},{0,3,2}};
    int threshold1 = 4;
    cout << "Test Case 1 Output: " << sol.findTheCity(n1, edges1, threshold1) << endl;
    // Expected: 3

    // Test case 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int threshold2 = 2;
    cout << "Test Case 2 Output: " << sol.findTheCity(n2, edges2, threshold2) << endl;
    // Expected: 0

    // Test case 3
    int n3 = 6;
    vector<vector<int>> edges3 = {{0,1,2},{0,2,4},{1,2,1},{2,3,7},{3,4,3},{4,5,1}};
    int threshold3 = 5;
    cout << "Test Case 3 Output: " << sol.findTheCity(n3, edges3, threshold3) << endl;
    // Expected: 5

    return 0;
}
