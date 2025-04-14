//Combination Sum II(Medium)
//using recursion and backtracking
//time complexity O(2^n) where n is the number of elements in the array
//space complexity O(n) where n is the number of elements in the array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, result, temp, sum);
        return result;
    }

    void backtracking(vector<int> candidates, int target, int index, vector<vector<int>>& result, vector<int>& temp, int sum) {
        if (sum == target) {
            result.emplace_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if(candidates[i]>target)continue;
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            sum += candidates[i];
            if (sum > target) {
                sum -= candidates[i];
                continue;
            }
            temp.emplace_back(candidates[i]);
            backtracking(candidates, target, i + 1, result, temp, sum);
            temp.pop_back();
            sum -= candidates[i];
        }
    }
};

void printResult(vector<vector<int>> &result) {
    for (auto &combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << "----------------------\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> candidates1 = {10,1,2,7,6,1,5};
    int target1 = 8;
    cout << "Test Case 1:\n";
    vector<vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    printResult(result1);

    // Test Case 2
    vector<int> candidates2 = {2,5,2,1,2};
    int target2 = 5;
    cout << "Test Case 2:\n";
    vector<vector<int>> result2 = sol.combinationSum2(candidates2, target2);
    printResult(result2);

    // Test Case 3
    vector<int> candidates3 = {1,1,1,2};
    int target3 = 3;
    cout << "Test Case 3:\n";
    vector<vector<int>> result3 = sol.combinationSum2(candidates3, target3);
    printResult(result3);

    return 0;
}
