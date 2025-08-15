//Time complexity: O(4 alpha)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n+1;i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

    int findUPar(int n) {
        if (parent[n]==n)return n;
        return parent[n]=findUPar(parent[n]);
    }

    void unionByRank(int x, int y) {
        int up_u=parent[x], up_v=parent[y];
        int rup_u=rank[up_u], rup_v=rank[up_v];

        if (rup_u<rup_v) {
            parent[up_u]=up_v;
        }
        else if (rup_v<rup_u) {
            parent[up_v]=up_u;
        }
        else {
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int x, int y) {
        int up_u=parent[x], up_v=parent[y];
        int sup_u=size[up_u], sup_v=size[up_v];

        if (sup_u<sup_v) {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else {
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
};

// int main() {
//     DisjointSet ds(7);
//     ds.unionByRank(1, 2);
//     ds.unionByRank(2, 3);
//     ds.unionByRank(4, 5);
//     ds.unionByRank(6, 7);
//     ds.unionByRank(5, 6);
//     // if 3 and 7 same or not
//     if (ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n";
//     }
//     else cout << "Not same\n";
//
//     ds.unionByRank(3, 7);
//
//     if (ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n";
//     }
//     else cout << "Not same\n";
//     return 0;
// }


int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}