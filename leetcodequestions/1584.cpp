//Min Cost to Connect All Points(Medium)
//using prims algorithm
//time complexity: O(n^2)
//space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Min-heap: {cost, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);

        // Tracks minimum distance for each point
        unordered_map<int, int> heap_dict;
        for (int i = 0; i < n; ++i) {
            heap_dict[i] = INT_MAX;
        }

        int sum = 0;
        pq.push({0, 0}); // Starting point with cost 0

        while (!pq.empty()) {
            auto [cost, index] = pq.top();
            pq.pop();

            if (visited[index] || heap_dict[index] < cost)
                continue;

            sum += cost;
            visited[index] = 1;

            int xi = points[index][0];
            int xj = points[index][1];

            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;

                int yi = points[i][0], yj = points[i][1];
                int dist = abs(xi - yi) + abs(xj - yj);

                if (dist < heap_dict[i]) {
                    heap_dict[i] = dist;
                    pq.push({dist, i});
                }
            }
        }

        return sum;
    }
};

// ---------- Test Cases ----------
int main() {
    Solution obj;

    vector<vector<vector<int>>> testCases = {
        {{0,0},{2,2},{3,10},{5,2},{7,0}},   // Expected: 20
        {{3,12},{-2,5},{-4,1}},             // Expected: 18
        {{0,0},{1,1},{1,0},{-1,1}}          // Expected: 4
    };

    for (int i = 0; i < testCases.size(); i++) {
        int result = obj.minCostConnectPoints(testCases[i]);
        cout << "Test Case " << i+1 << ": MST Cost = " << result << endl;
    }

    return 0;
}
