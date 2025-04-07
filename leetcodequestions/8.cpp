//String to Integer (atoi)(Medium)
#include <iostream>
#include <string>
#include <climits>  // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int myAtoi(string s) 
    {
        int result = 0;
        bool negative = false;
        bool numberfound = false;

        for (int i = 0; i < s.length(); i++)
        {
            if (!numberfound && s[i] == ' ') continue;

            if (!numberfound && (s[i] == '-' || s[i] == '+'))
            {
                negative = (s[i] == '-');
                numberfound = true;
                continue;
            }

            if (!isdigit(s[i])) break;

            int val = s[i] - '0';
            numberfound = true;

            if (result > (INT_MAX - val) / 10)
                return negative ? INT_MIN : INT_MAX;

            result = result * 10 + val;
        }

        return negative ? -result : result;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "   -42";
    string s2 = "4193 with words";
    string s3 = "words and 987";
    string s4 = "-91283472332";
    string s5 = "+0000123";
    
    cout << "Input: \"" << s1 << "\" => Output: " << sol.myAtoi(s1) << endl;
    cout << "Input: \"" << s2 << "\" => Output: " << sol.myAtoi(s2) << endl;
    cout << "Input: \"" << s3 << "\" => Output: " << sol.myAtoi(s3) << endl;
    cout << "Input: \"" << s4 << "\" => Output: " << sol.myAtoi(s4) << endl;
    cout << "Input: \"" << s5 << "\" => Output: " << sol.myAtoi(s5) << endl;

    return 0;
}
