//Max Difference You Can Get From Changing an Integer(Medium)
//using Unordered Map
//time complexity: O(n)
//space complexity: O(n)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxS = s;
        string minS = s;

        // Maximize: Replace first non-9 digit with '9'
        char toReplaceMax = '\0';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax != '\0') {
            for (char &c : maxS) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // Minimize: If first digit is not 1, replace it with '1'
        char toReplaceMin = '\0';
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char &c : minS) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            // Replace next digit (not 0 or 1) with 0
            for (int i = 1; i < minS.size(); ++i) {
                if (minS[i] != '0' && minS[i] != '1') {
                    toReplaceMin = minS[i];
                    break;
                }
            }
            if (toReplaceMin != '\0') {
                for (int i = 1; i < minS.size(); ++i) {
                    if (minS[i] == toReplaceMin) minS[i] = '0';
                }
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};

int main() {
    Solution sol;

    // Test case 1
    int num1 = 9288;
    cout << "Test case 1: Input = " << num1 << endl;
    cout << "Output = " << sol.maxDiff(num1) << endl << endl;

    // Test case 2
    int num2 = 555;
    cout << "Test case 2: Input = " << num2 << endl;
    cout << "Output = " << sol.maxDiff(num2) << endl << endl;

    // Test case 3
    int num3 = 10000;
    cout << "Test case 3: Input = " << num3 << endl;
    cout << "Output = " << sol.maxDiff(num3) << endl << endl;

    return 0;
}
