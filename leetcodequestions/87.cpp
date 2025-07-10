//Scramble string(Hard)
//using DFS with memoization
//time complexity: O(n^4), space complexity: O(n^3)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> memo;

    bool dfs(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + '#' + s2;
        if (memo.count(key)) return memo[key];

        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return memo[key] = false;

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            // Without swap
            if (dfs(s1.substr(0, i), s2.substr(0, i)) &&
                dfs(s1.substr(i), s2.substr(i)))
                return memo[key] = true;

            // With swap
            if (dfs(s1.substr(0, i), s2.substr(n - i)) &&
                dfs(s1.substr(i), s2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        memo.clear();
        return dfs(s1, s2);
    }
};

// 🔽 Main function with test cases
int main() {
    Solution sol;

    // Test Case 1
    string s1 = "great";
    string s2 = "rgeat";
    cout << "Is '" << s2 << "' a scramble of '" << s1 << "'? "
         << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    // Test Case 2
    s1 = "abcde";
    s2 = "caebd";
    cout << "Is '" << s2 << "' a scramble of '" << s1 << "'? "
         << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    // Test Case 3
    s1 = "a";
    s2 = "a";
    cout << "Is '" << s2 << "' a scramble of '" << s1 << "'? "
         << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    return 0;
}
