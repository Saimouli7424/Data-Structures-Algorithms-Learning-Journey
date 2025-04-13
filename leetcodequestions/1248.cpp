//Count Number of Nice Subarrays(Medium)
//using sliding window
//time complexity O(n)
//space complexity O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        if (k == 0) return 0;

        int totalcount = 0;
        int oddcount = 0;
        int i = 0, j = 0;
        int res = 0;

        while (i < nums.size())
        {
            if (nums[i] % 2 != 0)
            {
                oddcount++;
                totalcount = 0; // Reset count when a new odd number enters the window
            }

            // When exactly k odd numbers are in the window, count valid subarrays
            while (oddcount == k)
            {
                totalcount++; // Count how many ways we can shrink from left and still have k odds
                if (nums[j] % 2 != 0) oddcount--;
                j++;
            }

            // Add totalcount to result. 
            // Why? Because if the next number is even, the same k-odd subarrays still remain valid 
            // until another odd number comes and resets the condition.
            res += totalcount;
            i++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << "Test Case 1 Output: " << sol.numberOfSubarrays(nums1, k1) << endl; // Expected: 2

    // Test Case 2
    vector<int> nums2 = {1, 2, 1, 2, 1};
    int k2 = 2;
    cout << "Test Case 2 Output: " << sol.numberOfSubarrays(nums2, k2) << endl; // Expected: 4

    // Test Case 3
    vector<int> nums3 = {2, 4, 6};
    int k3 = 1;
    cout << "Test Case 3 Output: " << sol.numberOfSubarrays(nums3, k3) << endl; // Expected: 0

    return 0;
}
