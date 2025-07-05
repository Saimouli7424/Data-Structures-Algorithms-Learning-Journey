#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);  // Initialize with a large number (amount+1)
        dp[0] = 0;  // Base case: 0 coins needed to make amount 0

        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (i - coin >= 0) {
                    // Try using this coin and update dp[i]
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still amount+1, it means amount can't be formed
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Minimum coins for amount " << amount1 << ": "
         << sol.coinChange(coins1, amount1) << endl;  // Expected: 3

    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Minimum coins for amount " << amount2 << ": "
         << sol.coinChange(coins2, amount2) << endl;  // Expected: -1

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Minimum coins for amount " << amount3 << ": "
         << sol.coinChange(coins3, amount3) << endl;  // Expected: 0

    return 0;
}
