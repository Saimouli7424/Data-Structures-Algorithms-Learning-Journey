//House Robber II(Medium)
#include <iostream>
#include <vector>
#include <algorithm> // For std::max
//time complexity O(n), space complexity O(1)
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Rob 0 to n-2 (exclude last) OR 1 to n-1 (exclude first)
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 3, 2};
    cout << "Max amount robbed (nums1): " << solution.rob(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Max amount robbed (nums2): " << solution.rob(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {0};
    cout << "Max amount robbed (nums3): " << solution.rob(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {10, 2, 5, 3, 7};
    cout << "Max amount robbed (nums4): " << solution.rob(nums4) << endl;

    return 0;
}
