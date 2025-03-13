//Find the smallest divisor given a threshold(medium)
//using binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int maxelem = *max_element(nums.begin(),nums.end());
            if(nums.size()==threshold)
            {
                return maxelem;
            }
    
            int left=1;
            int right = maxelem;
            while(left<=right)
            
            {
                int mid=left+(right-left)/2;
                int val = checking(nums,mid);
                if(val>threshold)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            return left;
        }
    
        int checking(vector<int>& nums,int divisor){
            int sum = 0;
            for (int num : nums)
                sum += (num + divisor - 1) / divisor;
            return sum;
        }
    };

int main()
{
    Solution s;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout<<s.smallestDivisor(nums,threshold);
    return 0;
}

//Time complexity: O(nlogm), where n is the length of nums and m is the maximum element in nums.