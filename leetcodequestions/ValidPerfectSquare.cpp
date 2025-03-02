//leetcode 367
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true; // 1 is a perfect square

        long long left = 1, right = num / 2;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == num) return true; // Found perfect square
            else if (square < num) left = mid + 1; // Move right
            else right = mid - 1; // Move left
        }
        return false;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is NOT a perfect square." << endl;
    }

    return 0;
}
