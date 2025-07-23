//Maximum Score From Removing Substrings(Medium)
//using stack
//time complexity: O(n)
//space complexity: O(n)

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int maximumGain(string s, int x, int y) {
    if (y > x) {
        swap(x, y);
        for (char &c : s) {
            if (c == 'a') c = 'b';
            else if (c == 'b') c = 'a';
        }
    }

    int total = 0;
    stack<char> st;

    // First pass: remove "ab"
    for (char c : s) {
        if (!st.empty() && st.top() == 'a' && c == 'b') {
            st.pop();
            total += x;
        } else {
            st.push(c);
        }
    }

    // Remaining string after first pass
    string rem;
    while (!st.empty()) {
        rem += st.top();
        st.pop();
    }
    reverse(rem.begin(), rem.end());

    // Second pass: remove "ba"
    for (char c : rem) {
        if (!st.empty() && st.top() == 'b' && c == 'a') {
            st.pop();
            total += y;
        } else {
            st.push(c);
        }
    }

    return total;
}

int main() {
    // Test case 1
    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << "Test case 1: " << maximumGain(s1, x1, y1) << endl; // Expected: 19

    // Test case 2
    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << "Test case 2: " << maximumGain(s2, x2, y2) << endl; // Expected: 20

    // Test case 3
    string s3 = "ababab";
    int x3 = 10, y3 = 20;
    cout << "Test case 3: " << maximumGain(s3, x3, y3) << endl; // Expected: 50

    return 0;
}
