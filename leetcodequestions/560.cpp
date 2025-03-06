//Subarray Sum equal k leetcode560 medium level
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> PrefixSum;
        int count = 0;
        int sum = 0;
        PrefixSum[0] = 1;  // Initialize for cases where sum itself is k

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (PrefixSum.find(sum - k) != PrefixSum.end()) {
                count += PrefixSum[sum - k]; // Add occurrences of (sum - k)
            }
            PrefixSum[sum]++; // Store prefix sum in map
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;
    cout << "Number of subarrays with sum " << k << " is: " << sol.subarraySum(nums, k) << endl;
    return 0;
}

