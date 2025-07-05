#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    // Build the tree
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }

    // Check every non-leaf node
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) continue; // skip leaves

        int leafCount = 0;
        for (int child : adj[i]) {
            if (adj[child].empty()) {
                leafCount++;
            }
        }

        if (leafCount < 3) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
