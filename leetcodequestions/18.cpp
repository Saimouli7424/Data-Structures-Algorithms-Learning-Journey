//4sum leetcode 18 medium level question

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        
        sort(nums.begin(), nums.end());  // Sort the array
        
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates
            
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates
                
                int k = j + 1, l = nums.size() - 1;
                
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;  // Skip duplicates
                        while (k < l && nums[l] == nums[l + 1]) l--;  // Skip duplicates
                    } 
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        l--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    
    vector<vector<int>> result = s.fourSum(nums, target);
    
    cout << "Quadruplets that sum to target:\n";
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i] << (i < quad.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    
    return 0;
}
