//Split Array Largest Sum(Hard)
//using BinarySearch
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int splitArray(vector<int>& nums, int k) 
        {
            int n = nums.size();
            if(k>n)return -1;
            int low = *max_element(nums.begin(),nums.end());
            if(n==k) return low;
    
            int high = accumulate(nums.begin(),nums.end(),0);
    
            auto ispossible=[&](int mid)
            {
                int subarrayscount=1;
                int sum=0;
                for(int num:nums)
                {
                    if(num>mid)return false;
                    if(sum+num > mid)
                    {
                        subarrayscount++;
                        sum=num;
                        if(subarrayscount>k)return false;
                    }
                    else
                    {
                        sum+=num;
                    }
                }
                return true;
            };
    
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                if(ispossible(mid))
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return low;
        }
    };

int main()
{
    Solution solution;
    vector<int> nums={7,2,5,10,8};
    int k=2;
    cout<<solution.splitArray(nums,k)<<endl;
    return 0;
}
//Time Complexity: O(nlog(sum of elements))
//Space Complexity: O(1)
//leetcodequestions/410.cpp
//Split Array Largest Sum(Hard)