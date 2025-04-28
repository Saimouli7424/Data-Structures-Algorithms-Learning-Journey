//Count Subarrays With Score Less Than K(Hard)
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0;
        int j = 0;
        long long sum = 0; // Use long long to avoid overflow
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            long long count = (i - j) + 1;
            while (sum * count >= k) {
                sum -= nums[j];
                j++;
                count = (i - j) + 1;
            }
            result += (i - j + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3, 1, 2, 5};
    long long k1 = 10;
    cout << "Test Case 1 Output: " << sol.countSubarrays(nums1, k1) << endl;
    // Expected Output: 9

    // Test Case 2
    vector<int> nums2 = {5, 1, 3, 2};
    long long k2 = 20;
    cout << "Test Case 2 Output: " << sol.countSubarrays(nums2, k2) << endl;
    // Expected Output: 10

    // Test Case 3
    vector<int> nums3 = {100000, 100000, 100000};
    long long k3 = 10000000000; // 10^10
    cout << "Test Case 3 Output: " << sol.countSubarrays(nums3, k3) << endl;
    // Expected Output: 6

    return 0;
}
