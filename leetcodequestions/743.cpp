//Network Delay Time(Medium)
//using dijkstra algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        if(k > n) return -1;

        vector<vector<pair<int,int>>> g(n);
        for(auto i : times)
        {
            int u = i[0], v = i[1], time = i[2];
            g[u - 1].emplace_back(v - 1, time);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k - 1});
        vector<int> dp(n, INT_MAX);
        dp[k - 1] = 0;

        while(!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();
            if(time > dp[node]) continue;

            for(auto j : g[node])
            {
                int newtime = time + j.second;
                if(newtime < dp[j.first])
                {
                    dp[j.first] = newtime;
                    pq.push({newtime, j.first});
                }
            }
        }

        int ans = *max_element(dp.begin(), dp.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};

// ------------ Test Driver ------------
int main() {
    Solution sol;

    vector<vector<int>> test1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4, k1 = 2;
    cout << "Test 1 Output: " << sol.networkDelayTime(test1, n1, k1) << endl;  // Expected: 2

    vector<vector<int>> test2 = {{1,2,1}};
    int n2 = 2, k2 = 1;
    cout << "Test 2 Output: " << sol.networkDelayTime(test2, n2, k2) << endl;  // Expected: 1

    vector<vector<int>> test3 = {{1,2,1}};
    int n3 = 2, k3 = 2;
    cout << "Test 3 Output: " << sol.networkDelayTime(test3, n3, k3) << endl;  // Expected: -1

    return 0;
}

//time complexity: O(ElogV) where E is the number of edges and V is the number of vertices