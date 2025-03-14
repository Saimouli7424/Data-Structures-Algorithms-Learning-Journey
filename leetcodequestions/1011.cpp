//Capacity To Ship Packages Within D Days(Medium)
//Using Binary search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days)
        {
            int ans=0;
            int tsum=0;
            int maxelem=INT_MIN;
            for(auto nums: weights)
            {
                tsum+=nums;
                maxelem=max(maxelem,nums);
            }
    
            int left=maxelem;
            int right=tsum;
            while(left<right)
            {
                int mid=left+(right-left)/2;
                if(checking(weights,days,mid))
                {
                    right=mid;
                }
                else
                {
                    left=mid+1;
                }
            }
            return right;
        }
    
        bool checking(vector<int>& weights, int days,int i)
        {
            int sum=0;
            int count=0;
            for(int j=0;j<weights.size();j++)
            {
                if((sum+weights[j])<=i)
                {
                    sum+=weights[j];
                }
                else
                {
                    count++;
                    sum=weights[j];
                }
    
                if(count>days)
                {
                        break;
                }
            }
            if(count+1<=days)
            {
                return true;
            }
            return false;
        }
    };

int main()
{
    Solution solution;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << solution.shipWithinDays(weights, days) << endl;
    return 0;
}

//Explanation:
//Here we are using binary search to find the minimum weight that can be shipped within D days.
//We are finding the sum of all the weights and the maximum weight in the array.
//Then we are using binary search to find the minimum weight that can be shipped within D days.
//We are checking if the sum of all the weights is less than or equal to the minimum weight
//If it is then we are adding the weight to the sum
//If it is not then we are increasing the count and adding the weight to the sum
//If the count is greater than the days then we are breaking the loop
//If the count is less than or equal to the days then we are returning true
//If the count is greater than the days then we are returning false
//Finally we are returning the right value
//The time complexity is O(nlogn) and the space complexity is O(1)
