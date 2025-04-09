//Pow(x, n)(Medium)
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // convert to long long to handle negative range of int
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Sample test cases
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = sol.myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
