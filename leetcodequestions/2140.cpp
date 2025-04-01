//Solving Questions With Brainpower(Medium) using Array and DynamicProgramming
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        vector<long long> dp(n + 1);

        for (int i = n - 1; i >= 0; --i) {
            const int points = questions[i][0];
            const int brainpower = questions[i][1];
            const int nextIndex = i + brainpower + 1;
            const long long nextPoints = nextIndex < n ? dp[nextIndex] : 0;
            dp[i] = max(points + nextPoints, dp[i + 1]);
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> questions1 = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << "Test Case 1: " << sol.mostPoints(questions1) << endl; // Output: 5
    
    vector<vector<int>> questions2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    cout << "Test Case 2: " << sol.mostPoints(questions2) << endl; // Output: 7
    
    vector<vector<int>> questions3 = {{2, 2}, {3, 1}, {4, 2}, {5, 3}, {1, 1}};
    cout << "Test Case 3: " << sol.mostPoints(questions3) << endl; // Output: 7
    
    return 0;
}