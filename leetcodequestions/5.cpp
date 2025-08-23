//Longest Palindromic Substring(Medium)
//Time complexity: O(n^2)
//Space complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        string result = "";
        int n = s.size();
        if (n <= 1) return s;

        for (int i = 1; i < n; i++)
        {
            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            left++; right--;
            string temp = s.substr(left, (right - left + 1));
            if (temp.size() > result.size()) result = temp;

            // Even length palindrome
            left = i - 1; right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            left++; right--;
            temp = s.substr(left, (right - left + 1));
            if (temp.size() > result.size()) result = temp;
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Testcase 1
    string s1 = "babad";
    cout << "Input: " << s1 << "\n";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s1) << "\n\n";

    // Testcase 2
    string s2 = "cbbd";
    cout << "Input: " << s2 << "\n";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s2) << "\n\n";

    // Testcase 3
    string s3 = "racecar";
    cout << "Input: " << s3 << "\n";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s3) << "\n\n";

    return 0;
}
