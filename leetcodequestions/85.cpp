//Maximal Rectangle(Hard)
//using monotonic stack
//time complexity: O(M*N)
//space complexity: O(N)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate largest rectangle in histogram
    int findArea(vector<int> &rows) {
        stack<pair<int, int>> s; // {height, start index}
        int maxArea = 0;
        int n = rows.size();

        for (int i = 0; i < n; i++) {
            int val = rows[i];
            int start = i;

            while (!s.empty() && s.top().first > val) {
                int height = s.top().first;
                int index = s.top().second;
                s.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }

            s.push({val, start});
        }

        // Process remaining elements in the stack
        while (!s.empty()) {
            int height = s.top().first;
            int index = s.top().second;
            s.pop();
            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }

    // Function to calculate maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int cols = matrix[0].size();
        vector<int> rows(cols, 0);  // heights for histogram
        int maxRect = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') rows[j] = 0;
                else rows[j] += 1;
            }
            maxRect = max(maxRect, findArea(rows));
        }
        return maxRect;
    }
};

// Helper to run a test case
void runTest(vector<vector<char>> matrix) {
    Solution sol;
    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << "\n\n";
}

int main() {
    // Test Case 1
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    runTest(matrix1); // Expected: 6

    // Test Case 2
    vector<vector<char>> matrix2 = {
        {'1', '0'}
    };
    runTest(matrix2); // Expected: 1

    // Test Case 3
    vector<vector<char>> matrix3 = {
        {'0', '0'},
        {'0', '0'}
    };
    runTest(matrix3); // Expected: 0

    return 0;
}
