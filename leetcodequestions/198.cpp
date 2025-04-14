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
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick = nums[i]+((i>1)?dp[i-2]:0);
            int notpick = dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }

    /*
    //using recursion
    class Solution
    {
    public:
        int rob(vector<int>& nums)
        {
            int n=nums.size();
            vector<int>dp(n,-1);
            return recursive(n-1,nums,dp);
        }

        int recursive(int index,vector<int>& nums,vector<int>& dp)
        {
            if(index==0)return nums[0];
            if(index<0)return 0;
            if(dp[index]!=-1)return dp[index];
            int pick = nums[index]+ recursive(index-2,nums,dp);
            int notpick = recursive(index-1,nums,dp);

            return dp[index]=max(pick,notpick);
        }
    };
    */
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

/*
🧪 Example:
nums = [2, 1, 4, 9]
Calling: rob(nums) → calls recursive(nums, 3)

recursive(3)
│
├── pick = nums[3] + recursive(1)
│        (9 + ?)
│       └── recursive(1)
│           ├── pick = nums[1] + recursive(-1)
│           │        (1 + 0 = 1)
│           └── notpick = recursive(0) = 2
│           → max(1, 2) = 2
│
├── pick = 9 + 2 = 11
│
├── notpick = recursive(2)
│           ├── pick = nums[2] + recursive(0)
│           │        (4 + 2 = 6)
│           └── notpick = recursive(1) = 2 (from memo)
│           → max(6, 2) = 6
│
└── final = max(11, 6) = 11


              recursive(3)
              /          \
        pick(1)        notpick(2)
       /                  \
recursive(1)          recursive(2)
 /       \               /       \
r(-1)   r(0)          r(0)      r(1)
         |             |         |
         0             2         2

*/