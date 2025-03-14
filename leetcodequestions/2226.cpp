//Maximum Candies Allocated to K Children(Medium)
//Using binarysearch

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k)
        {
            long long sum=0;
            for(int num: candies)
            {
                sum+=num;
            }
            if(sum<k)return 0;
            int maxelem=*max_element(candies.begin(),candies.end());
            int ans=0;
            int left=1;
            int right=sum/k;
            while(left<=right)
            {
                long long mid=(left+right)/2;
                if(checking(candies, mid, k))
                {
                    ans=mid;
                    left=mid+1;
                }else
                {
                    right=mid-1;
                }
            }
            return ans;
        }
    
        bool checking(vector<int>& candies, int mid, long long k)
        {
            long long count=0;
            for(int i=0;i<candies.size();i++)
            {
                count+=candies[i]/mid;
                if(count>=k)return true;
            }
            return false;
        }
    };

int main()
{
    Solution obj;
    vector<int> candies={1,1,2,2,3,3,4,4,5,5};
    long long k=8;
    cout<<obj.maximumCandies(candies, k);
    return 0;
}
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Input: candies = [1,1,2,2,3,3,4,4,5,5], k = 8
// Output: 3
// Explanation: You can assign candies to the children as follows:
// - Child 1: 1, 1, 2, 2
// - Child 2: 3, 3
// - Child 3: 4, 4
// - Child 4: 5
// The maximum number of candies each child can have is 3.
//
// Input: candies = [2,4,6,8,10], k = 3
// Output: 4
 //Explanation: You can assign candies to the children as follows:
// - Child 1: 2, 4
// - Child 2: 6
// - Child 3: 8
// - Child 4: 10
// The maximum number of candies each child can have is 4.
//
// Input: candies = [1,2,3,4,5], k = 3
 //Output: 2
 //Explanation: You can assign candies to the children as follows:
// - Child 1: 1, 2
// - Child 2: 3
// - Child 3: 4, 5
 //The maximum number of candies each child can have is 2.
