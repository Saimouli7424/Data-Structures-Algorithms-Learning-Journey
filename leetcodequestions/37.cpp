//Sudoku Solver(Hard)
//using backtracking and recursion
//Time complexity: O(9^n) where n is the number of empty cells in the board
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> rows = vector<vector<int>>(9, vector<int>(9, 0));
        vector<vector<int>> cols = vector<vector<int>>(9, vector<int>(9, 0));
        vector<vector<int>> grid = vector<vector<int>>(9, vector<int>(9, 0));
    
        void solveSudoku(vector<vector<char>>& board) {
            // Fill initial board constraints into rows, columns, and grid
            for (int row = 0; row < 9; ++row) {
                for (int col = 0; col < 9; ++col) {
                    if (board[row][col] != '.') {
                        int val = board[row][col] - '1';  // subtract 1 to make the value 0-indexed
                        rows[row][val] = 1;
                        cols[col][val] = 1;
                        int gridIndex = (row / 3) * 3 + (col / 3);  // Calculate grid index
                        grid[gridIndex][val] = 1;
                    }
                }
            }
            backtracking(board, 0, 0);
        }
    
        bool reached = false;  // Flag to indicate the solution is found
    
        void backtracking(vector<vector<char>>& board, int i, int j) {
            if (i == 9) {
                reached = true;  // Solution found
                return;
            }
            if (j == 9) {
                backtracking(board, i + 1, 0);  // Move to the next row
                return;
            }
    
            if (board[i][j] != '.')
            {
                backtracking(board, i, j + 1);
                return;
            }
    
            int gridIndex = (i/ 3) * 3 + (j / 3);
            for (int val = 0; val < 9; ++val) 
            {
                if (!rows[i][val] && !cols[j][val] && !grid[gridIndex][val])
                {
                    board[i][j] = '1' + val;  // Convert number to char and assign to the board
                    rows[i][val] = cols[j][val] = grid[gridIndex][val] = 1;
    
                    backtracking(board, i, j + 1);  // Recur to next cell
    
                    if (reached) return;  // If solution is found, stop further recursion
    
                    // Backtrack
                    board[i][j] = '.';  // Reset the cell
                    rows[i][val] = cols[j][val] = grid[gridIndex][val] = 0;
                }
            }
        }
    };

    void printBoard(const vector<vector<char>>& board) {
        for (const auto& row : board) {
            for (char ch : row)
                cout << ch << " ";
            cout << endl;
        }
    }
    
    int main() {
        Solution solver;
    
        vector<vector<vector<char>>> testCases = {
            {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
            },
            {
                {'.','.','9','7','4','8','.','.','.'},
                {'7','.','.','.','.','.','.','.','.'},
                {'.','2','.','1','.','9','.','.','.'},
                {'.','.','7','.','.','.','2','4','.'},
                {'.','6','4','.','1','.','5','9','.'},
                {'.','9','8','.','.','.','3','.','.'},
                {'.','.','.','8','.','3','.','2','.'},
                {'.','.','.','.','.','.','.','.','6'},
                {'.','.','.','2','7','5','9','.','.'}
            },
            {
                {'.','.','.','.','7','.','.','.','9'},
                {'.','4','.','.','8','5','.','.','1'},
                {'9','.','3','.','.','.','.','.','.'},
                {'.','.','.','.','.','3','.','.','.'},
                {'6','.','.','.','.','.','.','.','2'},
                {'.','.','.','7','.','.','.','.','.'},
                {'.','.','.','.','.','.','7','.','6'},
                {'8','.','.','9','2','.','.','5','.'},
                {'5','.','.','.','3','.','.','.','.'}
            }
        };
    
        int tc = 1;
        for (auto& board : testCases) {
            cout << "\nTest Case " << tc++ << " - Original Sudoku:\n";
            printBoard(board);
            solver = Solution(); // Reset state
            solver.solveSudoku(board);
            cout << "\nSolved Sudoku:\n";
            printBoard(board);
        }
    
        return 0;
    }
    