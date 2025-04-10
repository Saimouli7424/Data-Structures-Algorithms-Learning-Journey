//Minimum Operations to Make Array Values Equal to K(Easy)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minOperations(vector<int>& nums, int k) {
    unordered_set<int> numsset;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<k)return -1;
        if(nums[i]>k)numsset.insert(nums[i]);
    }
    return numsset.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << sol.minOperations(nums, k) << endl; // Output: 2
    return 0;
}