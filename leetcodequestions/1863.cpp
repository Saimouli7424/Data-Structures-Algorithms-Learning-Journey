// 1863. Sum of All Subset XOR Totals(Easy)
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/
//using backtracking to find all subsets and calculate their XOR sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    //time complexity: O(2^n) where n is the number of elements in nums
    int subsetXORSum(vector<int>& nums)
    {
        int total = 0;
        backtracking(nums, 0, 0, total);
        return total;
    }

    void backtracking(vector<int>& nums, int index, int currentXOR, int& total) {
        if (index == nums.size()) {
            total += currentXOR;
            return;
        }

        // Include nums[index] in current subset
        backtracking(nums, index + 1, currentXOR ^ nums[index], total);

        // Exclude nums[index] from current subset
        backtracking(nums, index + 1, currentXOR, total);
    }*/

    //time complexity: O(n) where n is the number of elements in nums
    //space complexity: O(1)
    int subsetXORSum(vector<int>& nums)
    {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            total |= nums[i];
        }
        return total * (1 << (n - 1)); // Each element contributes to half of the subsets
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    int result = sol.subsetXORSum(nums);
    cout << "Subset XOR Sum = " << result << endl; // Expected: 6
    return 0;
}
