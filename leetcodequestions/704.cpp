//Binary search
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target)
        {
            if(nums.size()==1)
            {
                if(nums[0]==target)return 0;
                return -1;
            }
    
            int left=0;
            int right=nums.size()-1;
            int mid;
            while(left<=right)
            {
                mid = left+(right-left)/2;
                if(nums[mid]==target)return mid;
                if(nums[mid]>target)
                {
                    right=mid-1;
                }
                else if(nums[mid]<target)
                {
                    left=mid+1;
                }
            }
            return -1;
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        cout << s.search(nums, target)<<endl;
        vector<int> nums2 = {2, 7, 11, 15};
        int target1 = 11;
        cout << s.search(nums2, target1);
        return 0;
    }