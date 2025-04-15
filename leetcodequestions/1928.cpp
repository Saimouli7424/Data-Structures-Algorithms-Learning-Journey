//Minimum Cost to Reach Destination in Time(Hard)
//Using dijkstra algorithm to find the minimum cost to reach the destination in time
//Time complexity: O(E log V) where E is the number of edges and V is the number of vertices
//Space complexity: O(V) where V is the number of vertices

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
    public:

        //mycode
        int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) 
        {
           int n = passingFees.size();
           vector<vector<pair<int,int>>>g(n);
           for(auto i:edges)
           {
            int node = i[0], neighbour=i[1], time=i[2];
            g[node].emplace_back(neighbour,time);
            g[neighbour].emplace_back(node,time);
           }
    
            //mincost,node,time
           priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
           vector<int>dist(n,INT_MAX);
           dist[0]=0;
           q.emplace(passingFees[0],0,0);
    
           while(!q.empty())
           {
            auto[fees,node,time]=q.top();
            q.pop();
            if(node==n-1 && time<=maxTime)return fees;
            if(time>maxTime)continue;
            for(auto i:g[node])
            {
                int newnode=i.first;
                int newfee=fees+passingFees[newnode];
                int newtime = time+i.second;
                if(dist[newnode]>newtime)
                {
                    dist[newnode]=newtime;
                    q.emplace(newfee,newnode,newtime);
                }
            }
           }
           return -1;
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
