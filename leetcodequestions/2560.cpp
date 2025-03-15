//House Robber IV(medium)
//using binary search
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minCapability(vector<int>& nums, int k) 
        {
            int left=*min_element(nums.begin(),nums.end());
            int right=*max_element(nums.begin(),nums.end());
            while(left<right)
            {
                int mid=left+(right-left)/2;
                if(check(nums,mid,k))
                {
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return left;
        }
    
        bool check(vector<int>& nums, int mid, int k)
        {
            int count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= mid)
                {
                    count++;
                    i++;
                }
                if (count >= k) return true;
            }
            return false;
        }
    };

int main()
{
    Solution s;
    vector<int> nums={1,2,3,4,5};
    int k=2;
    cout<<s.minCapability(nums,k)<<endl;
}
//Output: 3