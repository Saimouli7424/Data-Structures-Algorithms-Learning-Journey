//Permutations(Medium)
//using recursion and backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        permutation(nums, result, 0);
        return result;
    }

    void permutation(vector<int>& nums, vector<vector<int>>& results, int index)
    {
        if (index == nums.size())
        {
            results.emplace_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permutation(nums, results, index + 1);
            swap(nums[index], nums[i]); // backtrack
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);

    cout << "Permutations:\n";
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
// Time Complexity: O(n! * n) where n is the size of the input array
// Space Complexity: O(n) for the recursion stack
//if without backtracing only recursion when nums is passed by value than time complexity is O(n! * n^2) and space complexity is O(n^2) for the recursion stack