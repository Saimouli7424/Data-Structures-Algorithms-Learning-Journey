//Koko Bananas Using Binary Search(Medium)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h)
        {
            int maxelem = *max_element(piles.begin(),piles.end());
            long long left=1;
            long long right=maxelem;
            if(h==piles.size())return right;
            while(left<=right)
            {
                long long mid= left+(right-left)/2;
                long long val = checking(piles,mid);
                if(val<=h)
                {
                    right=mid-1;
                }else
                {
                    left=mid+1;
                }
            }
            return left;
        }
    
        long long checking(vector<int>& piles,int n)
        {
            long long count=0;
            for(int i=0;i<piles.size();i++)
            {
                count += (piles[i] + n - 1) / n;
            }
            return count;
        }
    };


int main()
{
    Solution obj;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<obj.minEatingSpeed(piles,h);
    return 0;
}

//Explanation:
//In this problem, we have to find the minimum speed at which the monkey can eat all the bananas in h hours.
//We can use binary search to find the minimum speed.
//We will find the maximum element in the piles array and then we will apply binary search from 1 to max element.
//We will check if the monkey can eat all the bananas in h hours at the mid speed.
//If the monkey can eat all the bananas in h hours at the mid speed then we will update the right pointer to mid-1.
//If the monkey cannot eat all the bananas in h hours at the mid speed then we will update the left pointer to mid+1.
//We will repeat this process until the left pointer is less than or equal to the right pointer.
//Finally, we will return the left pointer as the minimum speed at which the monkey can eat all the bananas in h hours.
//The time complexity of this approach is O(nlogm) where n is the size of the piles array and m is the maximum element in the piles array.
//The space complexity of this approach is O(1).
