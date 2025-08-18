//24 Game
//using backtracking + DFS
//time complexity O((n!)²)= O((4!)²) O(576) which is O(1)
//space complexity :- O(n^2) (constant for n=4 → O(1))
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24) < 1e-6;  // check close to 24
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;  // avoid using same number twice

                vector<double> newList;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) newList.push_back(nums[k]);
                }

                vector<double> candidates = {
                    nums[i] + nums[j],
                    nums[i] * nums[j],
                    nums[i] - nums[j],
                    nums[j] - nums[i]
                };

                if (fabs(nums[j]) > 1e-6) candidates.push_back(nums[i] / nums[j]);
                if (fabs(nums[i]) > 1e-6) candidates.push_back(nums[j] / nums[i]);

                for (auto value : candidates) {
                    newList.push_back(value);
                    if (dfs(newList)) return true;
                    newList.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {4, 1, 8, 7};
    vector<int> test2 = {1, 2, 1, 2};
    vector<int> test3 = {3, 3, 8, 8};

    cout << "Test 1: {4, 1, 8, 7} -> " << (sol.judgePoint24(test1) ? "true" : "false") << endl;
    cout << "Test 2: {1, 2, 1, 2} -> " << (sol.judgePoint24(test2) ? "true" : "false") << endl;
    cout << "Test 3: {3, 3, 8, 8} -> " << (sol.judgePoint24(test3) ? "true" : "false") << endl;

    return 0;
}
