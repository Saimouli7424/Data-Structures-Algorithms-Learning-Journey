//Rotate a matrix 90degrees (medium)
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            int n=matrix.size()-1;
            int left = -1;
            int count = 0;
            int j=-1;
            while(n>left)
            {
                j++;
                left++;
                int top = n;
                for(int i=j;i<n;i++)
                {
                    int temp1 = matrix[i][n];
                    matrix[i][n]=matrix[left][i];
    
                    int temp2=matrix[n][top];
                    matrix[n][top]=temp1;
    
                    int temp3=matrix[top][left];
                    matrix[top][left]=temp2;
    
                    matrix[left][i]=temp3;
                    top--;
                }
                n--;
            }
        }
    };

    int main(){
        Solution s;
        vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
        s.rotate(matrix);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }