//Number of Subsequences That Satisfy the Given Sum Condition(Medium)
//using sorting and two pointers
// Time Complexity: O(nlogn)
//space complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        long long res = 0;

        // Precompute powers of 2
        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};

// 🔽 Main function with test cases
int main() {
    Solution sol;

    vector<int> nums1 = {3, 5, 6, 7};
    int target1 = 9;
    cout << "Test Case 1: " << sol.numSubseq(nums1, target1) << endl;
    // Expected: 4

    vector<int> nums2 = {3, 3, 6, 8};
    int target2 = 10;
    cout << "Test Case 2: " << sol.numSubseq(nums2, target2) << endl;
    // Expected: 6

    vector<int> nums3 = {2, 3, 3, 4, 6, 7};
    int target3 = 12;
    cout << "Test Case 3: " << sol.numSubseq(nums3, target3) << endl;
    // Expected: 61

    return 0;
}

