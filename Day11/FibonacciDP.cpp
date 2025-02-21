#include <iostream>
#include <vector>
using namespace std;

// Memoization (Top-Down) Approach
int fibMemo(int n, vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n]; // Check if already computed
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// Tabulation (Bottom-Up) Approach
int fibTabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    
    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci (Memoization): " << fibMemo(n, dp) << endl;
    
    // Tabulation
    cout << "Fibonacci (Tabulation): " << fibTabulation(n) << endl;
    
    return 0;
}
