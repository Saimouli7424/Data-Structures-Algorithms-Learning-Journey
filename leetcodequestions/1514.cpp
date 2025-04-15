//Path with Maximum Probability(Medium)
//using dijkstra Algorithm
//Time Complexity: O(ElogV) where E is the number of edges and V is the number of vertices
//Space Complexity: O(V) where V is the number of vertices
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if(end_node >= n) return 0.0;

        vector<vector<pair<int, double>>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double cost = succProb[i];
            g[u].emplace_back(v, cost);
            g[v].emplace_back(u, cost);
        }

        // Max heap to get the path with the highest probability
        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        pq.emplace(1.0, start_node);

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (node == end_node) return cost;

            for(auto [newnode, newcost] : g[node]) {
                if(cost * newcost > dist[newnode]) {
                    dist[newnode] = cost * newcost;
                    pq.emplace(dist[newnode], newnode);
                }
            }
        }

        return 0.0;
    }
};

// ------------------- MAIN FUNCTION WITH TEST CASES --------------------
int main() {
    Solution sol;

    // Test Case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1},{1,2},{0,2}};
    vector<double> prob1 = {0.5, 0.5, 0.2};
    int start1 = 0, end1 = 2;
    cout << "Test Case 1 Output: " << sol.maxProbability(n1, edges1, prob1, start1, end1) << endl;

    // Test Case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0,1},{1,2},{0,2}};
    vector<double> prob2 = {0.5, 0.5, 0.3};
    int start2 = 0, end2 = 2;
    cout << "Test Case 2 Output: " << sol.maxProbability(n2, edges2, prob2, start2, end2) << endl;

    // Test Case 3
    int n3 = 5;
    vector<vector<int>> edges3 = {{0,1},{1,2},{2,3},{3,4}};
    vector<double> prob3 = {0.9,0.8,0.7,0.6};
    int start3 = 0, end3 = 4;
    cout << "Test Case 3 Output: " << sol.maxProbability(n3, edges3, prob3, start3, end3) << endl;

    return 0;
}
