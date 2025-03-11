//Search in Rotated Sorted Array II(Medium)
//repeated number will be there using binary search
//time complexity O(logn)
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool search(vector<int>& nums, int target)
        {
            int left=0;
            int right=nums.size()-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(nums[mid]==target)return true;
                if(mid-1>=0 && nums[mid-1]==target)return true;
                if(mid+1<nums.size() && nums[mid+1]==target)return true;
    
                if(nums[left]<nums[mid])
                {
                    if(nums[left]<=target && target<nums[mid])
                    {
                        right=mid-1;
                    }
                    else
                    {
                        left=mid+1;
                    }
                }
                else
                {
                    if(nums[mid]<target && target<=nums[right])
                    {
                        left=mid+1;
                    }
                    else
                    {
                        right=mid-1;
                    }
                }
            }
            return false;
        }
    };

int main()
{
    Solution obj;
    vector<int> nums={2,5,6,0,0,1,2};
    int target=0;
    cout<<obj.search(nums,target);
    return 0;
}
//output: true