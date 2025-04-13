//House Robber(Medium)
//using dynamic programming
//time complexity O(n)
//space complexity O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int temp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Max rob from {1, 2, 3, 1}: " << sol.rob(nums1) << endl; // Expected: 4

    // Test Case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Max rob from {2, 7, 9, 3, 1}: " << sol.rob(nums2) << endl; // Expected: 12

    // Test Case 3
    vector<int> nums3 = {5, 1, 1, 5};
    cout << "Max rob from {5, 1, 1, 5}: " << sol.rob(nums3) << endl; // Expected: 10

    return 0;
}
