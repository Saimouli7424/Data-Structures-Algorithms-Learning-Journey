//Number of Zero-Filled Subarrays(Medium)
//Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long currentZeroLength = 0;

        for (int num : nums) {
            if (num == 0) {
                currentZeroLength++;
                count += currentZeroLength;
            } else {
                currentZeroLength = 0;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, 0, 2, 0};
    cout << "Test case 1: " << sol.zeroFilledSubarray(nums1) << endl; // 4

    vector<int> nums2 = {0, 0, 0, 0};
    cout << "Test case 2: " << sol.zeroFilledSubarray(nums2) << endl; // 10

    vector<int> nums3 = {1, 2, 3};
    cout << "Test case 3: " << sol.zeroFilledSubarray(nums3) << endl; // 0

    return 0;
}
