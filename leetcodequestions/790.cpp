//Domino and Tromino Tiling(Medium)
//using Dp
//time complexity O(n)
//space complexity O(n)
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    int numTilings(int n) {
        const int MOD = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        vector<long long> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
    */
    int numTilings(int n) {
        const int MOD = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        long long a = 1; // dp[n - 3]
        long long b = 2; // dp[n - 2]
        long long c = 5; // dp[n - 1]
        long long d;

        for (int i = 4; i <= n; ++i) {
            d = (2 * c + a) % MOD;
            a = b;
            b = c;
            c = d;
        }

        return c;
    }
};

int main() {
    Solution sol;

    cout << "n = 2 → " << sol.numTilings(2) << endl; // Output: 2
    cout << "n = 3 → " << sol.numTilings(3) << endl; // Output: 5
    cout << "n = 4 → " << sol.numTilings(4) << endl; // Output: 11
    cout << "n = 7 → " << sol.numTilings(7) << endl; // Output: 117
    cout << "n = 1000 → " << sol.numTilings(1000) << endl; // Large test case

    return 0;
}
