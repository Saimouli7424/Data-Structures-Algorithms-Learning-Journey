//leetcode 54
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            int rowsize = matrix.size();
            int colsize = matrix[0].size();
            if(rowsize==1)
            {
                return matrix[0];
            }
            if(colsize==1)
            {
                for(int i=0;i<rowsize;i++)
                {
                    result.emplace_back(matrix[i][0]);
                }
                return result;
            }
            int i=0;
            int j=0;
            int left=0;
            int total = rowsize*colsize;
            int count = 0;
            while(count!=total)
            {
                while(j<colsize && count!=total)
                {
                    result.emplace_back(matrix[i][j]);
                    j++;
                    count++;
                }
                j--;
                int temp=i;
                i++;
                while(i<rowsize && count!=total)
                {
                    result.emplace_back(matrix[i][j]);
                    i++;
                    count++;
                }
                i--;
                j--;
                while(j>=left && count!=total){
                    result.emplace_back(matrix[i][j]);
                    j--;
                    count++;
                }
                left++;
                j++;
                i--;
                while(i!=temp && count!=total){
                    result.emplace_back(matrix[i][j]);
                    i--;
                    count++;
                }
                i++;
                j++;
                colsize--;
                rowsize--;
            }
            return result;
        }
    };

int main() {
    // int rows, cols;
    // cout << "Enter number of rows and columns: ";
    // cin >> rows >> cols;

    // vector<vector<int>> matrix(rows, vector<int>(cols));
    // cout << "Enter the matrix elements:\n";
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

//output
//[1,2,3,4,8,12,16,20,24,23,22,21,17,13,9,5,6,7,11,15,19,18,14,10]