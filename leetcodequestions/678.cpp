//Valid Parenthesis String(Using greedy approach)
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else if (ch == '*') {
                low--;      // consider '*' as ')'
                high++;     // consider '*' as '('
            }

            if (high < 0) return false;  // too many ')'
            if (low < 0) low = 0;        // can't have negative '('
        }

        return low == 0;
    }
};

int main() {
    Solution sol;
    string test = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    
    if (sol.checkValidString(test)) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}
