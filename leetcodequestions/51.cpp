//N-Queens(Hard)
//using recursion and backtracking
//time complexity: O(N!)
//space complexity: O(N^2)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> grid(n, string(n, '.'));
        vector<bool> col(n, true);
        vector<bool> diag1(2 * n - 1, true);  // row - col + n - 1
        vector<bool> diag2(2 * n - 1, true);  // row + col

        backtracking(n, 0, col, diag1, diag2, grid, result);
        return result;
    }

    void backtracking(int n, int row, vector<bool>& col, vector<bool>& diag1,
                      vector<bool>& diag2, vector<string>& grid,
                      vector<vector<string>>& result)
    {
        if (row == n) {
            result.emplace_back(grid);
            return;
        }

        for (int c = 0; c < n; ++c) {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            if (col[c] && diag1[d1] && diag2[d2]) {
                grid[row][c] = 'Q';
                col[c] = diag1[d1] = diag2[d2] = false;

                backtracking(n, row + 1, col, diag1, diag2, grid, result);

                grid[row][c] = '.';
                col[c] = diag1[d1] = diag2[d2] = true;
            }
        }
    }
};

void printSolutions(const vector<vector<string>>& solutions) {
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << "---------------------" << endl;
    }
}

int main() {
    Solution s;

    // Test Case 1: n = 4
    cout << "Test Case n = 4\n";
    auto result1 = s.solveNQueens(4);
    printSolutions(result1);

    // Test Case 2: n = 1
    cout << "Test Case n = 1\n";
    auto result2 = s.solveNQueens(1);
    printSolutions(result2);

    // Test Case 3: n = 5
    cout << "Test Case n = 5\n";
    auto result3 = s.solveNQueens(5);
    printSolutions(result3);

    return 0;
}
