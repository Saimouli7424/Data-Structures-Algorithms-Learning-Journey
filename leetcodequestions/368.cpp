//Largest Divisible Subset(Medium)
//Dynamic Programming
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> dp(n, 1), prev(n, -1);
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        result.push_back(nums[i]);
        if (prev[i] == -1) break;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {1, 2, 4, 8};

    vector<int> result = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
