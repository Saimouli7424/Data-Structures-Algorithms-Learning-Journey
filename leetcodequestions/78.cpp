//Subsets using backtracking (medium)
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>result;
            result.reserve(1 << nums.size());
            vector<int> subset;
            subset.reserve(nums.size());
            backtrack(nums,subset,result,0);
            return result;
        }
    
        void backtrack(vector<int>& nums,vector<int>& subset, vector<vector<int>>& result,int index)
        {
            result.emplace_back(subset);
    
            for(int i=index;i<nums.size();i++)
            {
                subset.emplace_back(nums[i]);
                backtrack(nums,subset,result,i+1);
                subset.pop_back();
            }   
        }
    };

    int main(){
        Solution s;
        vector<int> nums = {1,2,3};
        vector<vector<int>> result = s.subsets(nums);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }