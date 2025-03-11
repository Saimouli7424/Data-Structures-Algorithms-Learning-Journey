//Find Peak Element (Medium) using Binary search
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        if(nums.size()<=1)return 0;
        if(nums.size()==2){
            if(nums[1]>nums[0]) return 1;
            return 0;
        }
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid+1])
            {
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
};

int main()
{
    Solution s;
    vector<int> nums={1,2,3,1};
    cout<<s.findPeakElement(nums)<<endl;
    return 0;
}