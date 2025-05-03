//Minimum Domino Rotations For Equal Row(Medium)
//using C++ STL 
//time complexity: O(n)
//space complexity: O(6) which means O(1)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int tsize = tops.size();
        if (tsize != bottoms.size()) return -1;

        unordered_map<int, int> mp;
        int val = -1;

        for (int i = 0; i < tsize; i++) {
            mp[tops[i]]++;
            mp[bottoms[i]]++;
            if (mp[tops[i]] >= tsize) val = tops[i];
            if (mp[bottoms[i]] >= tsize) val = bottoms[i];
        }

        if (val == -1) return -1;

        int topcount = 0, bottomcount = 0;
        for (int i = 0; i < tsize; i++) {
            if (tops[i] != val && bottoms[i] != val) return -1;
            if (tops[i] == bottoms[i]) continue;
            if (tops[i] == val) topcount++;
            if (bottoms[i] == val) bottomcount++;
        }

        return min(topcount, bottomcount);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid solution (target = 2)
    vector<int> tops1 = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms1 = {5, 2, 6, 2, 3, 2};
    cout << "Test Case 1: " << sol.minDominoRotations(tops1, bottoms1) << endl; // Expected: 2

    // Test Case 2: No valid rotation possible
    vector<int> tops2 = {3, 5, 1, 2, 3};
    vector<int> bottoms2 = {3, 6, 3, 3, 4};
    cout << "Test Case 2: " << sol.minDominoRotations(tops2, bottoms2) << endl; // Expected: -1

    // Test Case 3: Already uniform row (no rotation needed)
    vector<int> tops3 = {1, 1, 1, 1};
    vector<int> bottoms3 = {2, 2, 2, 2};
    cout << "Test Case 3: " << sol.minDominoRotations(tops3, bottoms3) << endl; // Expected: 0

    return 0;
}
