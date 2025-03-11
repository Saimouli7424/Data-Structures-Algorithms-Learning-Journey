//Find Minimum in rotated sorted array(Medium)
//using binary search
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findMin(vector<int>& arr)
        {
            int left=0;
            int right=arr.size()-1;
    
            while(left<right)
            {
                int mid=(left+right)/2;
                if(arr[mid]>arr[right])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
    
                //for larger number
                // if(arr[mid]>arr[right])
                // {
                //     right=mid-1;
                // }
                // else
                // {
                //     left=mid;
                // }
            }
            return arr[left];
        }
    };
    int main()
    {
        Solution obj;
        vector<int> arr={3,4,5,1,2};
        cout<<obj.findMin(arr);
        return 0;
    }
