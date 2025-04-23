//Evaluate Division(Medium)
//using graph and DFS
//time complexity O(V+E)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].push_back(make_pair(v, val));
            graph[v].push_back({u, 1.0 / val});
        }

        vector<double> result;
        for (auto i : queries) {
            string src = i[0];
            string dest = i[1];
            unordered_set<string> visited;
            double value = dfs(src, dest, visited);
            result.emplace_back(value);
        }
        return result;
    }

    double dfs(string src, string dest, unordered_set<string>& visited) {
        if (!graph.count(src) || !graph.count(dest)) return -1.0;
        if (src == dest) return 1.0;

        visited.insert(src);
        for (auto& [neighbor, weight] : graph[src]) {
            if (!visited.count(neighbor)) {
                double val = dfs(neighbor, dest, visited);
                if (val != -1.0) return val * weight;
            }
        }
        return -1.0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result1 = sol.calcEquation(equations1, values1, queries1);
    cout << "Test Case 1:\n";
    for (double r : result1) cout << r << " ";
    cout << "\n";

    // Test Case 2
    Solution sol2;
    vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};

    vector<double> result2 = sol2.calcEquation(equations2, values2, queries2);
    cout << "Test Case 2:\n";
    for (double r : result2) cout << r << " ";
    cout << "\n";

    // Test Case 3
    Solution sol3;
    vector<vector<string>> equations3 = {{"x", "y"}, {"y", "z"}};
    vector<double> values3 = {4.0, 2.0};
    vector<vector<string>> queries3 = {{"x", "z"}, {"z", "x"}, {"x", "x"}, {"a", "b"}};

    vector<double> result3 = sol3.calcEquation(equations3, values3, queries3);
    cout << "Test Case 3:\n";
    for (double r : result3) cout << r << " ";
    cout << "\n";

    return 0;
}

/*
//using BFS
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].push_back({v,val});
            graph[v].push_back({u,1.0/val});
        }

        vector<double>result;
        for(int i=0;i<queries.size();i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];
            double value = bfs(src,dest);
            result.emplace_back(value);
        }

        return result;
    }

    double bfs(string src,string dest)
    {
        if (!graph.count(src) || !graph.count(dest)) return -1.0;
        if(src==dest)return 1.0;
        unordered_set<string>visited;
        queue<pair<string,double>>q;
        q.push({src,1.0});
        while(!q.empty())
        {
            auto[u,wt] = q.front();
            q.pop();

            if(u==dest)return wt;

            visited.insert(u);
            for(auto [neighbour,weight]:graph[u])
            {
                if(!visited.count(neighbour))
                {
                    q.push({neighbour,wt*weight});
                }
            }
        }
        return -1.0;
    }
};
*/
