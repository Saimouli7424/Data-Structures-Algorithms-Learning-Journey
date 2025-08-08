//Soup Servings(Medium)
//using dp and dfs
//time complexity: O(n^2)
//space complexity: O(n^2)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<double>> dp;

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (dp[a][b] != -1.0) return dp[a][b];

        dp[a][b] = 0.25 * (
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );
        return dp[a][b];
    }

    double soupServings(int n) {
        int m = (n + 24) / 25; // convert ml → serving units
        if (m >= 200) return 1.0; // large n approximation
        dp.assign(m + 1, vector<double>(m + 1, -1.0));
        return dfs(m, m);
    }
};

int main() {
    Solution sol;

    vector<int> testcases = {50, 100, 660295675}; // small, medium, very large
    for (int n : testcases) {
        double ans = sol.soupServings(n);
        cout << "n = " << n << " → probability = " << fixed << setprecision(6) << ans << "\n";
    }

    return 0;
}
