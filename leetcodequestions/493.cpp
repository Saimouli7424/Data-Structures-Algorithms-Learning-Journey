//lletcode 493 Reverse Pairs(hard level)
//using mergesort
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int reversePairs(vector<int>& nums)
        {
            return funcount(nums,0,nums.size()-1);
        }
    
        int funcount(vector<int>&nums,int low,int high)
        {
            if(low>=high)return 0;
            int mid = (low+high)/2;
            int paircount=0;
            paircount+=funcount(nums,low,mid);
            paircount+=funcount(nums,mid+1,high);
            paircount+=reversepairs(nums,low,mid,high);
            
            Mergesort(nums,low,mid,high);
            return paircount;
        }
    
        int reversepairs(vector<int>& arr,int low,int mid,int high)
        {
            int paircount=0;
            int left=low;
            int j=mid+1;
            for(int i=low;i<=mid;i++){
                while (j <= high && arr[i] > 2LL * arr[j]) {
                    j++;
                }
                paircount += (j - (mid + 1));
            }
            return paircount;
        }
    
        void Mergesort(vector<int>& arr,int low,int mid,int high)
        {
            vector<int> temp;
            int left=low;
            int right=mid+1;
            while(left<=mid && right<=high)
            {
                if(arr[right]<arr[left])
                {
                    temp.emplace_back(arr[right]);
                    right++;
                }else
                {
                    temp.emplace_back(arr[left]);
                    left++;
                }
            }
            
            while(left<=mid)
            {
                temp.emplace_back(arr[left]);
                left++;
            }
            
            while(right<=high)
            {
                temp.emplace_back(arr[right]);
                right++;
            }
            
            for(int i=0;i<temp.size();i++)
            {
                arr[i+low]=temp[i];
            }
        }
    };

    int main(){
        vector<int> arr = {2,4,3,5,1};
        Solution sol;
        cout<<sol.reversePairs(arr)<<endl;
        return 0;
    }

/*
Time complexity: O(nlogn)
Space complexity: O(n)
Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
*/