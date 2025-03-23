//Search a 2D Matrix(Medium)
//Using BinarySearch
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int left=0;
            int divisor=matrix[0].size();
            int right=(matrix.size()*matrix[0].size())-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                int row=mid/divisor;
                int column=mid%divisor;
                int val=matrix[row][column];
                if(val==target)return true;
                else if(val>target)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            return false;
        }
    };

int main()
{
    Solution obj;
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    cout<<obj.searchMatrix(matrix,target)<<endl;
    return 0;
}
//Time Complexity: O(log(m*n))
//Space Complexity: O(1)
//leetcodequestions/74.cpp