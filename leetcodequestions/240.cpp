//Search a 2D Matrix II(Medium)
//using basic iteration condition
//time complexity: O(m + n), where m is the number of rows and n is the number of columns in the matrix.
//space complexity: O(1), since we are using only a constant amount of extra space
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--; // move left
        } else {
            i++; // move down
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix1 = {
        {0, 4, 7, 11, 15},
        {8, 12, 13, 15, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    vector<vector<int>> matrix2 = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };

    vector<vector<int>> matrix3 = {
        {1}
    };

    // Test Cases
    cout << "Test Case 1 (Target = 8): " << (searchMatrix(matrix1, 8) ? "Found" : "Not Found") << endl;
    cout << "Test Case 2 (Target = 10): " << (searchMatrix(matrix2, 10) ? "Found" : "Not Found") << endl;
    cout << "Test Case 3 (Target = 1): " << (searchMatrix(matrix3, 1) ? "Found" : "Not Found") << endl;

    return 0;
}

/*dry run
Test Case 1:
matrix1 = {
    {0, 4, 7, 11, 15},
    {8, 12, 13, 15, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
}
    i = 0, j = 4, target = 8
    matrix1[0][4] = 15 >8
    j--
    j = 3
    matrix1[0][3] = 11 >8
    j--
    j = 2
    matrix1[0][2] = 13 >
    j = 1
    matrix1[1][1] = 7<8
    i++

    i=1
    j = 1
    matrix1[1][1] = 12>8
    j--;

    i=1
    j=1
    matrix1[0][0] = 8==8
    return true
*/
