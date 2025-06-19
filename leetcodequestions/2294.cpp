//Partition Array Such That Maximum Difference Is K(Medium)
//time complexity: O(n log n) due to sorting
//space complexity: O(1) for the sorting operation, as it sorts in place
#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Using std::sort instead of ranges::sort for compatibility

        int ans = 1;
        int mn = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (mn + k < nums[i]) {
                ++ans;
                mn = nums[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 6, 1, 2, 5};
    int k1 = 2;
    cout << "Test case 1 result: " << sol.partitionArray(nums1, k1) << endl;  // Output: 2

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 1;
    cout << "Test case 2 result: " << sol.partitionArray(nums2, k2) << endl;  // Output: 2

    // Test case 3
    vector<int> nums3 = {8, 4, 7, 9, 3, 2};
    int k3 = 3;
    cout << "Test case 3 result: " << sol.partitionArray(nums3, k3) << endl;  // Output: 2

    return 0;
}
