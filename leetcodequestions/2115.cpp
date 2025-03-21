//Find All Possible Recipes from Given Supplies(Medium)
//BFS Graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
        {
            unordered_map<string, int> indegree;
            unordered_map<string, vector<string>> graph;
            unordered_set<string> available(supplies.begin(), supplies.end());
            vector<string> result;
    
           
            for (int i = 0; i < recipes.size(); i++) {
                indegree[recipes[i]] = ingredients[i].size();
    
                for (const string& ing : ingredients[i]) {
                    graph[ing].push_back(recipes[i]);
                }
            }
    
            queue<string> q;
            for (const string& s : supplies) 
            {
                q.push(s);
            }
    
            while (!q.empty()) 
            {
                string item = q.front();
                q.pop();
    
                if (indegree.find(item) != indegree.end())
                {
                    result.push_back(item);
                }
    
                for (const string& dependent : graph[item])
                {
                    if (--indegree[dependent] == 0)
                    {
                        q.push(dependent);
                    }
                }
            }
            return result;
        }
    };

    int main() {
        Solution solution;
    
        vector<string> recipes = {"bread", "sandwich", "burger"};
        vector<vector<string>> ingredients = {
            {"flour", "water"},
            {"bread", "ham"},
            {"sandwich", "lettuce"}
        };
        vector<string> supplies = {"flour", "water", "ham", "lettuce"};
    
        vector<string> result = solution.findAllRecipes(recipes, ingredients, supplies);
    
        cout << "Recipes that can be made: ";
        for (const string& r : result) {
            cout << r << " ";
        }
        cout << endl;
    
        return 0;
    }

/*
Data Structures Used & Why
This problem is solved using Graph + BFS (Topological Sorting).

Graph Representation (unordered_map<string, vector<string>> graph)

Purpose: Stores dependency relationships between ingredients and recipes.
Example: "flour" -> ["bread"], "bread" -> ["sandwich"] (i.e., bread depends on flour).
Indegree Map (unordered_map<string, int> indegree)

Purpose: Stores how many ingredients are still needed for each recipe.
Example: "bread" -> 2, "sandwich" -> 1 (sandwich needs 1 more ingredient to be prepared).
Set for Supplies (unordered_set<string> available)

Purpose: Fast lookup of already available ingredients.
Example: { "flour", "water", "ham", "lettuce" }.
Queue for BFS (queue<string> q)

Purpose: Stores available ingredients and recipes that can be prepared.
Example: We start with supplies in the queue and process recipes in order.
Algorithm Explanation (BFS + Topological Sort)
Step 1: Build a graph from ingredients → recipes.
Step 2: Count the number of missing ingredients (indegree).
Step 3: Start BFS from already available supplies.
Step 4: Process each ingredient, updating dependent recipes.
Step 5: Once a recipe’s indegree == 0, add it to the queue.
Step 6: Return all recipes that can be made.
Complexity Analysis
Building the graph: O(N + M)
BFS traversal: O(N + M)
Total Complexity: O(N + M) (where N is the number of recipes, M is the total number of ingredients).
*/
    