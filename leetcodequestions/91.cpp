//Decode Ways(Medium)
//using DFS and memoization
//Time complexity: O(n)
//Space complexity: O(n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> memo(n, -1);
        return dfs(s, 0, memo);
    }

    int dfs(string s, int start, vector<int>& memo) {
        int ssize = s.length();
        if (start == ssize) return 1;
        if (s[start] == '0') return 0;
        if (memo[start] != -1) return memo[start];

        int count = dfs(s, start + 1, memo);

        if (start + 1 < ssize) {
            int val = (s[start] - '0') * 10 + (s[start + 1] - '0');
            if (val >= 10 && val <= 26) {
                count += dfs(s, start + 2, memo);
            }
        }

        return memo[start] = count;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "12";
    cout << "Input: " << s1 << " → Output: " << sol.numDecodings(s1) << endl;

    // Test Case 2
    string s2 = "226";
    cout << "Input: " << s2 << " → Output: " << sol.numDecodings(s2) << endl;

    // Test Case 3
    string s3 = "06";
    cout << "Input: " << s3 << " → Output: " << sol.numDecodings(s3) << endl;

    // Test Case 4 (Optional)
    string s4 = "11106";
    cout << "Input: " << s4 << " → Output: " << sol.numDecodings(s4) << endl;

    return 0;
}
