//Coin Change(Medium)
//using Dynamic Programming and Memoization
//time complexity: O(n * amount), where n is the number of coins
//space complexity: O(amount), for the dp array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // Initialize with amount+1 (impossible value)
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test Case 1: " << sol.coinChange(coins1, amount1) << endl; // Expected: 3 (5+5+1)

    // Test Case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test Case 2: " << sol.coinChange(coins2, amount2) << endl; // Expected: -1

    // Test Case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test Case 3: " << sol.coinChange(coins3, amount3) << endl; // Expected: 0

    return 0;
}
