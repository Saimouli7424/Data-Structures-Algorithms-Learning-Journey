//Subsets II(Medium)
//using backtracking
//Time complexity: O(n*2^n) where n is the length of the input array
//Space complexity: O(n) for the recursion stack
//The space complexity for the result is O(2^n) in the worst case, but we don't count it in the final answer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // Step 1: Sort input to handle duplicates
        backtracking(nums, result, subset, 0);
        return result;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index)
    {
        result.emplace_back(subset); // Store current subset

        for (int i = index; i < nums.size(); ++i)
        {
            if (i > index && nums[i] == nums[i - 1]) continue; // Step 2: Skip duplicates
            //i>index means we are not at the first element of the current subset of the duplicates because at first time have to find second repetition onwards have to ignore
            subset.emplace_back(nums[i]);
            backtracking(nums, result, subset, i + 1);
            subset.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 4, 4, 1, 4};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "[\n";
    for (const auto& subset : result) {
        cout << "  [";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}
