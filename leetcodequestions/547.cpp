//Number of Provinces(Medium)
//using BFS
//TIME COMPLEXITY: O(n^2)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int rows = isConnected.size();
        vector<bool> visited(rows, false);
        int provincescount = 0;

        if (rows == 1) return 1;

        for (int i = 0; i < rows; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                // Remove this loop — it was redundant
                // Instead do everything inside the BFS loop below
                while (!q.empty()) {
                    int row = q.front();
                    q.pop();
                    for (int k = 0; k < rows; k++) {
                        if (isConnected[row][k] == 1 && !visited[k]) {
                            visited[k] = true;
                            q.push(k);
                        }
                    }
                }

                provincescount++;
            }
        }

        return provincescount;
    }
};

// ----------- Main Function with Test Cases ---------------
int main() {
    Solution sol;

    vector<vector<int>> test1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << "Test 1 Output: " << sol.findCircleNum(test1) << endl;  // Expected: 2

    vector<vector<int>> test2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    cout << "Test 2 Output: " << sol.findCircleNum(test2) << endl;  // Expected: 3

    vector<vector<int>> test3 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "Test 3 Output: " << sol.findCircleNum(test3) << endl;  // Expected: 1

    return 0;
}
