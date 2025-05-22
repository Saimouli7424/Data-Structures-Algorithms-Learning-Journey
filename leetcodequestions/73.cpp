//Set Matrix Zeroes(Medium)
//Time complexity:- O(m*n)
//space complexity:- O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool FirstRowZero = false;
        bool FirstColZero = false;

        int m=matrix.size();//row size
        int n=matrix[0].size();//col size
        

        //we are seperately checking the first row and firstcol because for the first row top there is no row
        //in the same way for first col left there is no col
        //Step1:- checking first row
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                FirstColZero=true;
                break;
            }
        }

        //checking first col
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                FirstRowZero=true;
                break;
            }
        }

        //Step2:- making using row first cell and col first cell as markers
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;//mark col first cell as zero
                    matrix[i][0]=0;//mark row first cell as zero
                }
            }
        }

        //Step3:- Based on the markers making the whole rows and cols as zero
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        //now if any first row or first col is zero making them as zero whole row or col
        if (FirstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (FirstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

    }
};

// Utility function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "---------------------\n";
}

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(matrix1);
    cout << "Test Case 1:\n";
    printMatrix(matrix1);

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {0, 2, 3},
        {4, 5, 6},
        {7, 0, 9}
    };
    sol.setZeroes(matrix2);
    cout << "Test Case 2:\n";
    printMatrix(matrix2);

    // Test Case 3
    vector<vector<int>> matrix3 = {
        {1, 2, 3, 4},
        {5, 6, 0, 8},
        {9,10,11,12},
        {0,14,15,16}
    };
    sol.setZeroes(matrix3);
    cout << "Test Case 3:\n";
    printMatrix(matrix3);

    return 0;
}
