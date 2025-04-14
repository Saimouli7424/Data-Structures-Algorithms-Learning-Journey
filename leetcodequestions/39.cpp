//Combination Sum(Medium)
//using recursion and backtracking
//time complexity O(2^n) where n is the number of elements in the array
//space complexity O(n) where n is the number of elements in the array

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        backtracking(candidates, target, result, temp, sum, 0);
        return result;
    }

    void backtracking(vector<int> candidates, int target, vector<vector<int>>& result, vector<int> temp, int sum, int index) {
        if (sum == target) {
            result.emplace_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            sum += candidates[i];
            if (sum > target) {
                sum -= candidates[i];
                continue;
            }
            temp.emplace_back(candidates[i]);
            backtracking(candidates, target, result, temp, sum, i);  // i, not i+1 (reuse allowed)
            sum -= candidates[i];
            temp.pop_back();
        }
    }
};

// Helper function to print the results
void printResult(const vector<vector<int>>& result) {
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << "--------------------\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Test Case 1 (target = 7):\n";
    vector<vector<int>> result1 = sol.combinationSum(candidates1, target1);
    printResult(result1);

    // Test Case 2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    cout << "Test Case 2 (target = 8):\n";
    vector<vector<int>> result2 = sol.combinationSum(candidates2, target2);
    printResult(result2);

    // Test Case 3
    vector<int> candidates3 = {2};
    int target3 = 1;
    cout << "Test Case 3 (target = 1):\n";
    vector<vector<int>> result3 = sol.combinationSum(candidates3, target3);
    printResult(result3);

    return 0;
}
