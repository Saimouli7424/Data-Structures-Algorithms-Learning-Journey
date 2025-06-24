#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjlist, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (int neighbor : adjlist[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjlist, visited, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjlist[u].push_back(v);
        }

        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adjlist, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

// === MAIN FUNCTION WITH TEST CASES ===

int main() {
    Solution sol;

    // Test Case 1
    int V1 = 6;
    vector<vector<int>> edges1 = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };
    vector<int> result1 = sol.topoSort(V1, edges1);
    cout << "Topological Sort (Test Case 1): ";
    for (int node : result1) cout << node << " ";
    cout << endl;

    // Test Case 2
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}
    };
    vector<int> result2 = sol.topoSort(V2, edges2);
    cout << "Topological Sort (Test Case 2): ";
    for (int node : result2) cout << node << " ";
    cout << endl;

    // Test Case 3 (Single node with no edge)
    int V3 = 1;
    vector<vector<int>> edges3 = {};
    vector<int> result3 = sol.topoSort(V3, edges3);
    cout << "Topological Sort (Test Case 3): ";
    for (int node : result3) cout << node << " ";
    cout << endl;

    return 0;
}

/*
//Using Kahn's Algorithm

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adjlist(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            adjlist[u].push_back(v);
        }
        
        vector<int>Indegree(V);
        for(int i=0;i<V;i++){
            for(auto it:adjlist[i]){
                Indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(Indegree[i]==0)q.push(i);
        }
        
        vector<int> result;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto i:adjlist[node]){
                Indegree[i]--;
                if(Indegree[i]==0)q.push(i);
            }
        }
        
        return result;
    }
        
};
*/
