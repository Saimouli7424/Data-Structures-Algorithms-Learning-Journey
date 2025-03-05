//count total number of coloured cells leetcode 2579

#include <iostream>
using namespace std;
class Solution {
public:
    long long coloredCells(int n) {
        long long val = 0;
        long long temp = 1;
        for (int i = 1; i < n; i++) {
            val += (temp + temp);
            temp += 2;
        }
        val += temp;
        return val;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long result = solution.coloredCells(n);
    cout << "Total colored cells: " << result <<endl;
    return 0;
}
