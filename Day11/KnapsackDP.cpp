#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming (Tabulation)
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Either take the item or leave it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Cannot take the item
            }
        }
    }
    
    return dp[n][W]; // Maximum value that can be obtained
}

int main() {
    int W = 50; // Maximum weight of the knapsack
    vector<int> wt = {10, 20, 30};  // Weights of items
    vector<int> val = {60, 100, 120}; // Values of items
    int n = wt.size();

    cout << "Maximum value in Knapsack: " << knapsack(W, wt, val, n) << endl;
    
    return 0;
}
