//Two Sum II - Input Array Is Sorted(Medium)
//two pointers
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int left=0;
            int right=numbers.size()-1;
            while(left<right)
            {
                int sum=numbers[left]+numbers[right];
                if(sum==target)return{left+1,right+1};
                if(sum>target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return {-1,-1};
        }
    };

int main()
{
    Solution s;
    vector<int> numbers={2,7,11,15};
    int target=9;
    vector<int> ans=s.twoSum(numbers,target);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
/*
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/