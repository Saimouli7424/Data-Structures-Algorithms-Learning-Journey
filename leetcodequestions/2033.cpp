//Minimum Operations to Make a Uni-Value Grid(Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if (x == 0 || grid.empty()) return -1;

        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp;

        // Taking a reference element to check divisibility by x
        int ref = grid[0][0];
        for (const auto& row : grid)
        {
            for (int num : row) {
                // if ((num - ref) % x != 0) return -1;
                // if(grid.size()==1 && grid[0].size()==1)return 0;
                //taking as reference firstelement or anyelement with it can be divisible by 0 so that we can make further process
                temp.push_back(num);
            }
        }

        // Finding the median element efficiently
        int middleIndex = temp.size() / 2;
        nth_element(temp.begin(), temp.begin() + middleIndex, temp.end());
        /*
         * `nth_element` places the correct `nth` element (median) at its exact position,
         * but does not fully sort the array—it only partially partitions it.
         */

        int middleVal = temp[middleIndex];

        int count = 0;
        for (int num : temp) {
            int val = abs(num - middleVal);
            count += val / x;
        }
        return count;
    }
};

// Driver Code (Main Function)
int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{2, 4}, {6, 8}};
    int x1 = 2;
    cout << "Test Case 1: " << sol.minOperations(grid1, x1) << endl; // Expected Output: 4

    vector<vector<int>> grid2 = {{1, 5}, {2, 3}};
    int x2 = 1;
    cout << "Test Case 2: " << sol.minOperations(grid2, x2) << endl; // Expected Output: 5

    vector<vector<int>> grid3 = {{1, 2}, {3, 4}};
    int x3 = 2;
    cout << "Test Case 3: " << sol.minOperations(grid3, x3) << endl; // Expected Output: -1

    vector<vector<int>> grid4 = {{931, 128}, {639, 712}};
    int x4 = 73;
    cout << "Test Case 4: " << sol.minOperations(grid4, x4) << endl; // Expected Output: 12

    vector<vector<int>> grid5 = {{146}};
    int x5 = 86;
    cout << "Test Case 5: " << sol.minOperations(grid5, x5) << endl; // Expected Output: 0

    return 0;
}

// Time Complexity: O(n*m*log(n*m))
// Space Complexity: O(n*m)

