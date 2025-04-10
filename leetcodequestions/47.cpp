//Permutations II(Medium)
//using recursion and backtracking
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: sort to detect duplicates
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.emplace_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicate numbers
            bool shouldSkip = false;
            for (int j = index; j < i; ++j) {
                if (nums[j] == nums[i]) {
                    shouldSkip = true;
                    break;
                }
            }
            if (shouldSkip) continue;

            swap(nums[index], nums[i]);
            backtrack(nums, index + 1, result);
            swap(nums[index], nums[i]); // backtrack
        }
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution sol;
    vector<vector<int>> result = sol.permuteUnique(nums);

    for (const auto& vec : result) {
        for (int num : vec) cout << num << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n!)
// Space Complexity: O(n)
