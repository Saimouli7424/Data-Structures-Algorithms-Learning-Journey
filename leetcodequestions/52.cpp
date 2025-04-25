// N-Queens II(Hard)
//time complexity: O(N!)
//space complexity: O(N)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 1) return 1;
        vector<bool> cols(n, false);
        vector<bool> leftdiag(2 * n, false);     // updated size
        vector<bool> rightdiag(2 * n, false);    // updated size
        return backtracking(cols, leftdiag, rightdiag, n, 0);
    }

    int backtracking(vector<bool>& cols, vector<bool>& leftdiag, vector<bool>& rightdiag, int n, int row) {
        if (row == n) return 1;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int ldval = row + i;
            int rdval = row - i + n;
            if (!cols[i] && !leftdiag[ldval] && !rightdiag[rdval]) {
                cols[i] = leftdiag[ldval] = rightdiag[rdval] = true;
                count += backtracking(cols, leftdiag, rightdiag, n, row + 1);
                cols[i] = leftdiag[ldval] = rightdiag[rdval] = false;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int n1 = 1;
    cout << "Total solutions for N = " << n1 << " : " << sol.totalNQueens(n1) << endl;

    // Test case 2
    int n2 = 4;
    cout << "Total solutions for N = " << n2 << " : " << sol.totalNQueens(n2) << endl;

    // Test case 3
    int n3 = 8;
    cout << "Total solutions for N = " << n3 << " : " << sol.totalNQueens(n3) << endl;

    return 0;
}
