//leetcode 326

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (sol.isPowerOfThree(n)) {
        cout << n << " is a power of 3." << endl;
    } else {
        cout << n << " is NOT a power of 3." << endl;
    }
    return 0;
}

//Another approach
/*
Any valid power of 3 must perfectly divide 3^19.

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
*/
