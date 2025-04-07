//Partition Equal Subset Sum(Medium)
//Using Dynamic Programming
//Time Complexity: O(n * sum)
//Space Complexity: O(sum)

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {14, 9, 8, 4, 3, 2};

    if (sol.canPartition(nums)) {
        cout << "Can partition into equal subset sums." << endl;
    } else {
        cout << "Cannot partition into equal subset sums." << endl;
    }

    return 0;
}
