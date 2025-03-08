//Maximum product of subarray leetcode152(medium)
//By using Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxProduct(const vector<int>& nums)
        {
            if(nums.size()==1)return nums[0];
            int size = nums.size()-1;
            int pre =1;
            int suff = 1;
            int maxelem=INT_MIN;
            for(int i=0;i<=size;i++)
            {
                if(pre==0)pre=1;
                if(suff==0)suff=1;
                pre*=nums[i];
                suff*=nums[size-i];
                maxelem=max(maxelem,max(pre,suff));
            }
            return maxelem;
        }
    };


    int main() {
        Solution sol;
    
        vector<vector<int>> testCases = {
            {2, 3, -2, 4},      // Expected Output: 6
            {-2, 0, -1},        // Expected Output: 0
            {1, 2, 3, 4},       // Expected Output: 24
            {-2, 3, -4},        // Expected Output: 24
            {-1, -2, -3, -4},   // Expected Output: 24
            {0, 2, -3, 4, -1},  // Expected Output: 8
            {-2, -3, 0, -2, -40} // Expected Output: 80
        };
    
        for (const auto& nums : testCases) {
            cout << "Max Product Subarray for [";
            for (int num : nums) cout << num << " ";
            cout << "] is: " << sol.maxProduct(nums) << endl;
        }
    
        return 0;
    }