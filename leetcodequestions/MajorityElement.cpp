//leetcode 169
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int> hash;
            int maxelem=0;
            int index;
            if(nums.size() == 1) {
                return nums[0];
            }
            for(auto i : nums) {
                hash[i]++;
            }
    
            
            for(auto it : hash)
            {
                if(it.second > (nums.size() / 2))
                {
                    if(maxelem<it.second)
                    {
                        maxelem=it.second;
                        index=it.first;
                    }
                }
            }
    
            return index;
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {2,2,1,1,1,2,2};
        cout<<s.majorityElement(nums);
        return 0;
    }