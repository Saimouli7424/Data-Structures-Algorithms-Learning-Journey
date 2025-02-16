#include <iostream>
#include <vector>
using namespace std;

class WeightedGraph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;

public:
    WeightedGraph(int v) {
        this->vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // Since it's an undirected weighted graph
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << " -> ";
            for (auto edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    WeightedGraph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    g.display();
    return 0;
}