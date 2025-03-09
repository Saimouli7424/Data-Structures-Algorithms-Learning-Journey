//3sum (medium level using sliding window)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // Sort the array
        
        for (int ipoint = 0; ipoint < nums.size() - 2; ++ipoint) {
            if (ipoint > 0 && nums[ipoint] == nums[ipoint - 1]) continue;  // Skip duplicates
            
            int jpoint = ipoint + 1;
            int kpoint = nums.size() - 1;
            
            while (jpoint < kpoint) {
                int sum = nums[ipoint] + nums[jpoint] + nums[kpoint];
                
                if (sum == 0) {
                    result.push_back({nums[ipoint], nums[jpoint], nums[kpoint]});
                    
                    while (jpoint < kpoint && nums[jpoint] == nums[jpoint + 1]) jpoint++;  // Skip duplicates
                    while (jpoint < kpoint && nums[kpoint] == nums[kpoint - 1]) kpoint--;  // Skip duplicates
                    
                    jpoint++;
                    kpoint--;
                } 
                else if (sum < 0) {
                    jpoint++;
                } 
                else {
                    kpoint--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> result = s.threeSum(nums);
    
    cout << "Triplets that sum to zero:\n";
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    
    return 0;
}
