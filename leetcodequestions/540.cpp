//Single Element in a Sorted Array(Medium)
//using Binary Search
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int left=0;
            int right=nums.size()-1;
            while(left<right)
            {
                int mid = (left+right)/2;
                if(mid%2==0)
                {
                    if(nums[mid]!=nums[mid+1])
                    {
                        right=mid;
                    }
                    else
                    {
                        left=mid+1;
                    }
                }else 
                {
                    if(nums[mid]==nums[mid-1])
                    {
                        left=mid+1;
                    }
                    else
                    {
                        right=mid;
                    }
                }
            }
            return nums[right];
        }
};

int main(){
    Solution s;
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    cout<<s.singleNonDuplicate(nums);
    return 0;
}