#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;  
    // Number of vertices
    vector<vector<int>> adj;  
    // Adjacency list

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); 
        // For undirected graph
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(5); 
    // Creating a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    
    cout << "Depth-First Search (starting from vertex 0): ";
    g.DFS(0);

    return 0;
}
