//Count Subarrays Where Max Element Appears at Least K Times(Medium)
//using sliding window and atmostK method
//Time complexity: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        long long totalSubarrays = (1LL * n * (n + 1)) / 2;
        return totalSubarrays - atMostKMinus1(nums, k - 1, maxNum);
    }

private:
    long long atMostKMinus1(vector<int>& nums, int k, int maxNum) {
        int left = 0, freq = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxNum) freq++;

            while (freq > k) {
                if (nums[left] == maxNum) freq--;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3, 3, 3, 2};
    int k1 = 2;
    cout << "Test Case 1: " << sol.countSubarrays(nums1, k1) << endl;
    // Expected output: 6

    // Test Case 2
    vector<int> nums2 = {1, 4, 2, 4};
    int k2 = 1;
    cout << "Test Case 2: " << sol.countSubarrays(nums2, k2) << endl;
    // Expected output: 10

    // Test Case 3
    vector<int> nums3 = {5, 5, 5, 5};
    int k3 = 3;
    cout << "Test Case 3: " << sol.countSubarrays(nums3, k3) << endl;
    // Expected output: 6 (subarrays with at least 3 fives)

    return 0;
}
