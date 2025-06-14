//Maximum Difference by Remapping a Digit(Easy)
//Time complexity: O(n)
//Space complexity: O(1)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string maxS = to_string(num);
        string minS = to_string(num);
        bool Mfound = false, Sfound = false;
        char maxval, minval;

        for (int i = 0; i < maxS.length(); i++) {
            if (maxS[i] != '9' && !Mfound) {
                Mfound = true;
                maxval = maxS[i];
                maxS[i] = '9';
            } else if (Mfound && maxS[i] == maxval) {
                maxS[i] = '9';
            }

            if (minS[i] != '0' && !Sfound) {
                Sfound = true;
                minval = minS[i];
                minS[i] = '0';
            } else if (Sfound && minS[i] == minval) {
                minS[i] = '0';
            }
        }

        int finalMax = stoi(maxS);
        int finalMin = stoi(minS);
        return finalMax - finalMin;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    int num1 = 11891;
    cout << "minMaxDifference(" << num1 << ") = " << sol.minMaxDifference(num1) << endl;

    // Test Case 2
    int num2 = 90;
    cout << "minMaxDifference(" << num2 << ") = " << sol.minMaxDifference(num2) << endl;

    // Test Case 3
    int num3 = 1001;
    cout << "minMaxDifference(" << num3 << ") = " << sol.minMaxDifference(num3) << endl;

    return 0;
}
