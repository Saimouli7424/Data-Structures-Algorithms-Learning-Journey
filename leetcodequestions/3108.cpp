//Minimum cost Walk in Weighted Graph(Hard)
#include<bits/stdc++.h>
using namespace std;
class UnionFind {
    public:
     // 2^17 - 1 is the minimum number in the form 2^x - 1 > 10^5.
     UnionFind(int n) : id(n), rank(n), weight(n, (1 << 17) - 1) {
       iota(id.begin(), id.end(), 0);
     }
   
     void unionByRank(int u, int v, int w) {
       const int i = find(u);
       const int j = find(v);
       const int newWeight = weight[i] & weight[j] & w;
       weight[i] = newWeight;
       weight[j] = newWeight;
       if (i == j)
         return;
       if (rank[i] < rank[j]) {
         id[i] = j;
       } else if (rank[i] > rank[j]) {
         id[j] = i;
       } else {
         id[i] = j;
         ++rank[j];
       }
     }
   
     int getMinCost(int u, int v) {
       if (u == v)
         return 0;
       const int i = find(u);
       const int j = find(v);
       return i == j ? weight[i] : -1;
     }
   
    private:
     vector<int> id;
     vector<int> rank;
     vector<int> weight;
   
     int find(int u) {
       return id[u] == u ? u : id[u] = find(id[u]);
     }
   };
   
   class Solution {
   public:
       vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries)
       {
           vector<int> ans;
           UnionFind uf(n);
   
           for (const vector<int>& edge : edges) {
           const int u = edge[0];
           const int v = edge[1];
           const int w = edge[2];
           uf.unionByRank(u, v, w);
           }
   
           for (const vector<int>& query : queries) {
           const int u = query[0];
           const int v = query[1];
           ans.push_back(uf.getMinCost(u, v));
           }
   
           return ans;
       }
   };

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0,1,10},{1,2,15},{2,5,4},{0,5,6},{3,4,12},{1,4,7}};
    vector<vector<int>> queries = {{0,4},{4,3},{1,2}};
    vector<int> result = s.minimumCost(6, edges, queries);
    for(int i : result) cout << i << " ";
    return 0;
}

//Explanation:
//The graph is shown below:
//  0 - 1 - 2
//  |       |
//  5       5
//  |       |
//  6 - 4 - 3
//The minimum cost to go from 0 to 4 is 10.
//The minimum cost to go from 4 to 3 is 12.
//The minimum cost to go from 1 to 2 is 15.
//So the output is [10, 12, 15].
//Time Complexity: O(N + Q)
//Space Complexity: O(N)
