//Assign Cookies(Easy)
//using greedy and two pointers
//Time complexity: O(nlogn) + O(mlogm) + O(n+m) = O(nlogn+mlogm+n+m) = O(nlogn+mlogm+n+m)
//Space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                i++; // satisfied this child
            }
            j++; // move to next cookie
        }

        return i; // total satisfied children
    }
};

int main() {
    Solution sol;

    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << sol.findContentChildren(g1, s1) << endl; // Output: 1

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << sol.findContentChildren(g2, s2) << endl; // Output: 2

    vector<int> g3 = {10, 9, 8, 7};
    vector<int> s3 = {5, 6, 7, 8};
    cout << sol.findContentChildren(g3, s3) << endl; // Output: 2

    return 0;
}
