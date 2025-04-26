//Count Subarrays With Fixed Bounds(Hard)
//using sliding window and two pointers
//Time complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int n = nums.size();
        int lastMin = -1, lastMax = -1, badIndex = -1;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) badIndex = i;
            if(nums[i] == minK) lastMin = i;
            if(nums[i] == maxK) lastMax = i;

            int validStart = min(lastMin, lastMax);
            if(validStart > badIndex) {
                ans += validStart - badIndex;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 2, 5, 1};
    int minK1 = 1, maxK1 = 5;
    cout << "Test Case 1 Output: " << sol.countSubarrays(nums1, minK1, maxK1) << endl;
    // Expected output: 2

    vector<int> nums2 = {1, 1, 1, 1};
    int minK2 = 1, maxK2 = 1;
    cout << "Test Case 2 Output: " << sol.countSubarrays(nums2, minK2, maxK2) << endl;
    // Expected output: 10 (all subarrays)

    vector<int> nums3 = {1, 2, 3, 4, 5};
    int minK3 = 2, maxK3 = 4;
    cout << "Test Case 3 Output: " << sol.countSubarrays(nums3, minK3, maxK3) << endl;
    // Expected output: 1 ([2,3,4])

    return 0;
}
