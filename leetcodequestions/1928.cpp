//Minimum Cost to Reach Destination in Time(Hard)
//Using dijkstra algorithm to find the minimum cost to reach the destination in time
//Time complexity: O(ElogV) where E is the number of edges and V is the number of vertices
//Space complexity: O(V) where V is the number of vertices

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) 
    {
        int n = passingFees.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        vector<vector<pair<int,int>>> graph(n);

        // Constructing the undirected graph
        for (auto& e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]); // undirected graph
        }

        // Fee, node, time
        pq.emplace(passingFees[0], 0, 0);

        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));
        dp[0][0] = passingFees[0];

        int mincost = INT_MAX;
        while(!pq.empty())
        {
            auto [fee, u, time] = pq.top();
            pq.pop();
            if (u == n - 1) return fee;  // Reached the destination

            for (auto& [v, t] : graph[u])
            {
                int newTime = time + t;
                if (newTime > maxTime) continue; // Skip if time exceeds maxTime

                int newFee = fee + passingFees[v];
                if (dp[v][newTime] > newFee) {
                    dp[v][newTime] = newFee;
                    pq.emplace(newFee, v, newTime);
                }
            }
        }
        return -1;  // If there's no valid path
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 2}, {0, 2, 5}};
    vector<int> fees1 = {1, 2, 3};
    int maxTime1 = 4;
    cout << "Test case 1 result: " << sol.minCost(maxTime1, edges1, fees1) << endl;

    // Test case 2
    vector<vector<int>> edges2 = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}, {1, 3, 2}, {2, 3, 1}};
    vector<int> fees2 = {3, 4, 2, 1};
    int maxTime2 = 5;
    cout << "Test case 2 result: " << sol.minCost(maxTime2, edges2, fees2) << endl;

    // Test case 3
    vector<vector<int>> edges3 = {{0, 1, 5}, {1, 2, 5}};
    vector<int> fees3 = {1, 2, 3};
    int maxTime3 = 10;
    cout << "Test case 3 result: " << sol.minCost(maxTime3, edges3, fees3) << endl;

    return 0;
}
