//Cheapest Flights Within K Stops(Medium)
//using dijkstra algorithm
//time complexity O(E + VlogV) where E is the number of edges and V is the number of vertices
//space complexity O(V) where V is the number of vertices

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> g(n);
        for(auto i : flights)
        {
            int u = i[0], v = i[1], cost = i[2];
            g[u].emplace_back(v, cost);
        }

        // tuple: {cost, node, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});

        vector<int> stops(n, INT_MAX);

        while(!pq.empty())
        {
            auto [cost, node, stop] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stop > k || stop >= stops[node]) continue;

            stops[node] = stop;

            for(auto& [nei, price] : g[node])
            {
                pq.push({cost + price, nei, stop + 1});
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> flights1 = {{0,1,100},{1,2,100},{0,2,500}};
    int n1 = 3, src1 = 0, dst1 = 2, k1 = 1;
    cout << "Test Case 1 Output: " << sol.findCheapestPrice(n1, flights1, src1, dst1, k1) << endl;
    // Expected: 200

    // Test Case 2
    vector<vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    int n2 = 3, src2 = 0, dst2 = 2, k2 = 0;
    cout << "Test Case 2 Output: " << sol.findCheapestPrice(n2, flights2, src2, dst2, k2) << endl;
    // Expected: 500

    // Test Case 3
    vector<vector<int>> flights3 = {{0,1,100},{1,2,100},{2,3,100},{3,4,100}};
    int n3 = 5, src3 = 0, dst3 = 4, k3 = 2;
    cout << "Test Case 3 Output: " << sol.findCheapestPrice(n3, flights3, src3, dst3, k3) << endl;
    // Expected: -1 (not reachable within 2 stops)

    return 0;
}
