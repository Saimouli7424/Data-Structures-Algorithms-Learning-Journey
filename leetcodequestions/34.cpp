//Find First and Last Position of Element in Sorted Array(Medium)

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) 
        {
            if(nums.empty())return {-1,-1};
            int left=0;
            int right=nums.size()-1;
            int starting=-1;
            int ending=-1;
            vector<int>temp;
            
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(nums[mid]==target)
                {
                    starting =mid;
                    right=mid-1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }else
                {
                    right=mid-1;
                }
            }
    
            left=0;right=nums.size()-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(nums[mid]==target)
                {
                    ending=mid;
                    left=mid+1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }
                else
                {
                  right=mid-1;
                }
            }
    
            return {starting,ending};
        }
    };

    int main(){
        Solution solution;
        vector<int>nums={5,7,7,8,8,10};
        int target=8;
        vector<int>result=solution.searchRange(nums,target);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
        }
        return 0;
    }