//leetcode31 finding next permutation (medium)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            // next_permutation(nums.begin(),nums.end());
            int right=nums.size()-2;
            int ind =-1;
            for(int i=right;i>=0;i--)
            {
                if(nums[i]<nums[i+1])
                {
                    ind=i;
                    break;
                }
            }
    
            if(ind==-1)return reverse(nums.begin(),nums.end());
    
            for(int i=nums.size()-1;i>ind;i--)
            {
                if(nums[i]>nums[ind])
                {
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
    
            reverse(nums.begin()+ind+1,nums.end());
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {1,2,3,4};
        s.nextPermutation(nums);
        for(auto &i: nums) cout<<i<<" ";
        cout<<endl;
        vector<int> nums1 = {3,4,1,2};
        s.nextPermutation(nums1);
        for(auto &i: nums1) cout<<i<<" ";
        return 0;
    }