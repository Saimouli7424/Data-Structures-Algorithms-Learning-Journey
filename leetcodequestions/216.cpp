//Combination Sum III
//using recursion and backtracking
// Time complexity: O(2^n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum3(int k, int n) {
        if (k > n) return {};
        if (k == 1) return {{n}};
        vector<int> temp;
        backtracking(k, n, 1, temp, 0);
        return result;
    }

    void backtracking(int k, int n, int index, vector<int>& temp, int sum) {
        if (sum == n && temp.size() == k) {
            result.emplace_back(temp);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (sum + i > n) break;  // Optimal pruning
            if (temp.size() < k) {
                temp.emplace_back(i);
                backtracking(k, n, i + 1, temp, sum + i);
                temp.pop_back();
            }
        }


        /*
        //cleaner code than this
        if (temp.size() == k && sum == n) {
            result.push_back(temp);
            return;
        }

        if (temp.size() >= k || sum > n) return;

        for (int i = index; i <= 9; ++i) {
            if (sum + i > n) break; // optimal pruning
            temp.push_back(i);
            backtracking(k, n, i + 1, temp, sum + i);
            temp.pop_back();
        }
        */
    }
};

int main() {
    Solution sol;

    vector<vector<int>> res1 = sol.combinationSum3(3, 7);
    cout << "Test case 1 - k=3, n=7:" << endl;
    for (auto& vec : res1) {
        for (int num : vec) cout << num << " ";
        cout << endl;
    }

    sol.result.clear(); // Clear results before next test
    vector<vector<int>> res2 = sol.combinationSum3(3, 9);
    cout << "\nTest case 2 - k=3, n=9:" << endl;
    for (auto& vec : res2) {
        for (int num : vec) cout << num << " ";
        cout << endl;
    }

    sol.result.clear();
    vector<vector<int>> res3 = sol.combinationSum3(4, 1);
    cout << "\nTest case 3 - k=4, n=1 (edge case):" << endl;
    if (res3.empty()) cout << "No combinations" << endl;
    else {
        for (auto& vec : res3) {
            for (int num : vec) cout << num << " ";
            cout << endl;
        }
    }

    return 0;
}
