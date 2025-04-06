//Reverse Words in a String
//using stack to reverse the words in a string
//Time complexity: O(n), where n is the length of the string
//Space complexity: O(n), for the stack used to store characters of each word
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string result = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ' && !st.empty()) {
                while (!st.empty()) {
                    result += st.top();
                    st.pop();
                }
                result += ' ';
            } else if (isalnum(s[i])) {
                st.push(s[i]);
            }
        }

        // Add last word if any
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Remove trailing space if present
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input = "a good   example";
    cout << "Original: \"" << input << "\"" << endl;
    string reversed = sol.reverseWords(input);
    cout << "Reversed: \"" << reversed << "\"" << endl;
    return 0;
}
// Output:
// Original: "a good   example"
// Reversed: "example good a"