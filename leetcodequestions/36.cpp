//Valid Sudoku(medium)
//time complexity: 0(N*N);

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> values(9, false);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        char ch = board[k][l];
                        if (ch == '.') continue;
                        int val = ch - '0';
                        if (rows[k][val - 1]==true || cols[l][val - 1]==true || values[val - 1]==true)
                            return false;
                        rows[k][val - 1] = true;
                        cols[l][val - 1] = true;
                        values[val - 1] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // ✅ Test Case 1: Valid Sudoku
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Test Case 1 (Valid): " << (sol.isValidSudoku(board1) ? "Valid" : "Invalid") << endl;

    // ❌ Test Case 2: Invalid Sudoku (duplicate '5' in same row)
    vector<vector<char>> board2 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','5','1','9','5','.','.','.'}, // duplicate '5'
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Test Case 2 (Invalid): " << (sol.isValidSudoku(board2) ? "Valid" : "Invalid") << endl;

    // ❌ Test Case 3: Invalid Sudoku (duplicate '6' in same column)
    vector<vector<char>> board3 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','6','.','8','.','.','7','9'} // duplicate '6' in column 2
    };

    cout << "Test Case 3 (Invalid): " << (sol.isValidSudoku(board3) ? "Valid" : "Invalid") << endl;

    return 0;
}
