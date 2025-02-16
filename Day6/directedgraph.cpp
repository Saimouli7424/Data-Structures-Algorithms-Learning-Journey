#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    DirectedGraph(int v) {
        this->vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Directed edge from u to v
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DirectedGraph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    return 0;
}