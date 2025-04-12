//Unique Paths(Medium)
//Using Dynamic Programming(Tabulation Approach) which is top down approach
//Time Complexity: O(m*n)
//TIME LIMIT EXCEEDED to the approaches for BFS,DFS
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n)
        {
            // vector<vector<int>>dp(m,vector<int>(n,1)); 
            //if using above comment no need of if condition in for loop and also can start directly from i=j=1

            vector<vector<int>>dp(m,vector<int>(n,0));
            dp[0][0]=1;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0 || j==0){
                        dp[i][j]=1; //if we are in first row or first column then only one way to reach there
                        continue; //continue to next iteration of inner loop
                    }
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
    
            return dp[m-1][n-1];
        }
    };

int main() {
    Solution sol;

    // ✅ Test Case 1
    int m1 = 3, n1 = 7;
    cout << "Test Case 1 (m = " << m1 << ", n = " << n1 << "): ";
    cout << sol.uniquePaths(m1, n1) << " unique paths\n";

    // ✅ Test Case 2
    int m2 = 3, n2 = 2;
    cout << "Test Case 2 (m = " << m2 << ", n = " << n2 << "): ";
    cout << sol.uniquePaths(m2, n2) << " unique paths\n";

    // ✅ Test Case 3
    int m3 = 1, n3 = 10;
    cout << "Test Case 3 (m = " << m3 << ", n = " << n3 << "): ";
    cout << sol.uniquePaths(m3, n3) << " unique paths\n";

    return 0;
}
