//Ways to Express an Integer as Sum of Powers
//using Dynmic Programming
//time complexity: O(n * log n), space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1'000'000'007;

        // Precompute powers safely (no floating point)
        vector<int> powers;
        for (int i = 1;; i++) {
            long long p = 1;
            for (int j = 0; j < x; j++) {
                p *= i;
                if (p > n) break; // early stop for this base
            }
            if (p > n) break; // stop when first power exceeds n
            powers.push_back((int)p);
        }

        // 1D DP array
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int sum = n; sum >= p; sum--) {
                dp[sum] = (dp[sum] + dp[sum - p]) % MOD;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    // Testcase 1
    int n1 = 10, x1 = 2;
    cout << "n=10, x=2 -> " << sol.numberOfWays(n1, x1) << endl;
    // Expected: 1 ({1, 9})

    // Testcase 2
    int n2 = 4, x2 = 1;
    cout << "n=4, x=1 -> " << sol.numberOfWays(n2, x2) << endl;
    // Expected: 1 ({4})

    // Testcase 3
    int n3 = 100, x3 = 2;
    cout << "n=100, x=2 -> " << sol.numberOfWays(n3, x3) << endl;
    // Expected: depends, multiple combinations possible

    return 0;
}
