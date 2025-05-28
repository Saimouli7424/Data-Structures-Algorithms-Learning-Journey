//Divisible and Non-divisible Sums Difference(Easy)
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int result = 0;
        if (n < 1 || m > 1000) return 0;
        for (int i = 1; i <= n; i++) {
            if (i % m != 0) result += i;
            else result -= i;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int n1 = 10, m1 = 3;
    cout << "Test Case 1: differenceOfSums(" << n1 << ", " << m1 << ") = "
         << sol.differenceOfSums(n1, m1) << endl;

    // Test Case 2
    int n2 = 15, m2 = 5;
    cout << "Test Case 2: differenceOfSums(" << n2 << ", " << m2 << ") = "
         << sol.differenceOfSums(n2, m2) << endl;

    // Test Case 3
    int n3 = 20, m3 = 7;
    cout << "Test Case 3: differenceOfSums(" << n3 << ", " << m3 << ") = "
         << sol.differenceOfSums(n3, m3) << endl;

    return 0;
}
