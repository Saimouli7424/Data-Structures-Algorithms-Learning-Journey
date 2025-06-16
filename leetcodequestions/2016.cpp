//Maximum Difference Between Increasing Elements(Easy)
//Time complexity: O(n)
//space complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minElem = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (minElem < nums[i]) {
                maxDiff = max(maxDiff, nums[i] - minElem);
            } else {
                minElem = nums[i];
            }
        }

        return maxDiff;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {7, 1, 5, 4};
    cout << "Test case 1: ";
    for (int n : nums1) cout << n << " ";
    cout << "\nMaximum Difference: " << sol.maximumDifference(nums1) << "\n\n";

    // Test case 2
    vector<int> nums2 = {9, 4, 3, 2};
    cout << "Test case 2: ";
    for (int n : nums2) cout << n << " ";
    cout << "\nMaximum Difference: " << sol.maximumDifference(nums2) << "\n\n";

    // Test case 3
    vector<int> nums3 = {1, 5, 2, 10};
    cout << "Test case 3: ";
    for (int n : nums3) cout << n << " ";
    cout << "\nMaximum Difference: " << sol.maximumDifference(nums3) << "\n";

    return 0;
}
