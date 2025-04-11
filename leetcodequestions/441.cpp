//Arranging Coins(Easy)
//Using Binary Search
//Time Complexity: O(log n)
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coins = mid * (mid + 1) / 2;
            if (coins == n) return mid;
            if (coins < n) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

int main() {
    Solution sol;
    int n=5;
    int result = sol.arrangeCoins(n);
    cout << "Maximum complete rows of staircase: " << result << endl;

    return 0;
}
