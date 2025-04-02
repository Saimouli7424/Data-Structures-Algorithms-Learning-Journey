//Maximum Value of an Ordered Triplet II(Medium)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //time complexity O(N) and space complexity O(1)
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Edge case
        
        long long maxLeft = nums[0];  // Track the maximum value on the left
        long long maxDiff = LLONG_MIN;  // Track max (nums[i] - nums[j])
        long long maxValue = 0;  // Store final max triplet value
        
        for (int i = 1; i < n - 1; i++) {
            maxDiff = max(maxDiff, maxLeft - nums[i]);  // Update max difference
            maxValue = max(maxValue, maxDiff * (long long)nums[i + 1]);  // Compute max triplet value
            maxLeft = max(maxLeft, (long long)nums[i]);  // Update maxLeft
        }

        return maxValue;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 4, 5, 2};
    cout << "Test Case 1: " << sol.maximumTripletValue(nums1) << endl; // Expected Output: 3

    // Test Case 2
    vector<int> nums2 = {6, 7, 2, 5, 10};
    cout << "Test Case 2: " << sol.maximumTripletValue(nums2) << endl; // Expected Output: 40

    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: " << sol.maximumTripletValue(nums3) << endl; // Expected Output: 0

    return 0;
}
