//Maximum Fruits Harvested After at Most K Steps(Hard)
//using sliding window technique and binary search
//another approach is using two pointers and sliding window which takes time complexity O(n)
//time complexity: O(nlogn)
//space complexity: O(n)
/*
 1)go right only
2)go left only
3)go left first then right
4)go right first then left
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), qty(n), pref(n);

        for (int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            qty[i] = fruits[i][1];
            pref[i] = qty[i] + (i > 0 ? pref[i - 1] : 0);
        }

        auto getSum = [&](int l, int r) -> int {
            if (l > r) return 0;
            return pref[r] - (l > 0 ? pref[l - 1] : 0);
        };

        int ans = 0;

        // Case 1: Only go right
        int r = upper_bound(pos.begin(), pos.end(), startPos + k) - pos.begin() - 1;
        int l = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
        if (l < n && r >= 0) ans = max(ans, getSum(l, r));

        // Case 2: Only go left
        l = lower_bound(pos.begin(), pos.end(), startPos - k) - pos.begin();
        r = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin() - 1;
        if (l < n && r >= 0) ans = max(ans, getSum(l, r));

        // Case 3: Go left first, then right
        for (int i = 0; i < n && pos[i] <= startPos; i++) {
            int leftSteps = startPos - pos[i];
            int remain = k - 2 * leftSteps;
            if (remain < 0) continue;
            int j = upper_bound(pos.begin(), pos.end(), startPos + remain) - pos.begin() - 1;
            ans = max(ans, getSum(i, j));
        }

        // Case 4: Go right first, then left
        for (int j = n - 1; j >= 0 && pos[j] >= startPos; j--) {
            int rightSteps = pos[j] - startPos;
            int remain = k - 2 * rightSteps;
            if (remain < 0) continue;
            int i = lower_bound(pos.begin(), pos.end(), startPos - remain) - pos.begin();
            ans = max(ans, getSum(i, j));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> fruits1 = {{2,4},{4,5},{6,3},{8,1},{10,2}};
    int startPos1 = 4, k1 = 4;
    cout << "Test Case 1 Output: " << sol.maxTotalFruits(fruits1, startPos1, k1) << endl;
    // Expected: 9 (collect fruits at 4 and 6 -> 5+3=8, or go left and right -> max = 9)

    // Test Case 2
    vector<vector<int>> fruits2 = {{1,2},{2,4},{3,1},{6,5},{8,2}};
    int startPos2 = 3, k2 = 3;
    cout << "Test Case 2 Output: " << sol.maxTotalFruits(fruits2, startPos2, k2) << endl;
    // Expected: 7 (go left to 1 then right to 3 -> 2+4+1=7)

    // Test Case 3
    vector<vector<int>> fruits3 = {{0,9},{4,1},{5,7},{6,2},{7,4}};
    int startPos3 = 5, k3 = 5;
    cout << "Test Case 3 Output: " << sol.maxTotalFruits(fruits3, startPos3, k3) << endl;
    // Expected: 19 (collect all fruits: left to 0 and then right)

    return 0;
}

