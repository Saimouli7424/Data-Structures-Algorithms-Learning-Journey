//Kth Missing Positive Number(Easy)
//Binary search
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int n=arr.size();
            int diff=(arr[n-1]-1)-n;
            if(n==arr[n-1])
            {
                return n+k;
            }
    
            int left=1;
            int right=arr.back()+k;
            while(left<right)
            {
                int mid=left+(right-left)/2;
    
                int val=checking(arr,mid);
    
                if(val<k)
                {
                    left=mid+1;
                }else
                {
                    right=mid;
                }
            }
            return right;//left also no issue    
        }
    
        int checking(vector<int>& arr, int mid)
        {
            int index = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            //upperbound also returns iterator of greater element than mid
            //the arr.begin() will always returns iterator which is at 0
            //to get the index value we must subtract with another iterator that's why we used here arr.begin()
            return mid - index;
        }
    };

int main()
{
    Solution s;
    vector<int> arr={2,3,4,7,11};
    int k=5;
    cout<<s.findKthPositive(arr,k)<<endl;
    }
    //Output: 9