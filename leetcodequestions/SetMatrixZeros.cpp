//leetcode 73
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> data;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int count = -1;
        
        // Store positions of zeros in a map
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                count++;
                if (matrix[i][j] == 0) {
                    data[count] = -1;
                }
            }
        }

        // Set entire row and column to zero
        for (auto i : data) {
            if (i.second < 0) {
                int val = i.first;
                int row = val / columns;
                int col = val % columns;

                for (int i = 0; i < rows; i++) {
                    matrix[i][col] = 0;
                }
                for (int i = 0; i < columns; i++) {
                    matrix[row][i] = 0;
                }
            }
        }
    }
};

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    solution.setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";
    printMatrix(matrix);

    return 0;
}
