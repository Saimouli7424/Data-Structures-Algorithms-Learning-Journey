//leetcode 1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> result; // HashMap to store value -> index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i]; // Find the complement

            // If complement exists in map, return indices
            if (result.find(diff) != result.end()) {
                return {result[diff], i};
            }

            // Store the current number and its index
            result[nums[i]] = i;
        }

        return {}; // No solution (as per problem statement, this won't happen)
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15}; 
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
