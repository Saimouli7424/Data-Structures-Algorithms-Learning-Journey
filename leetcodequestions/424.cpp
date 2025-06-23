// Longest Repeating Character Replacement(Medium)
//using sliding window technique
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char, int> mp;

        for (int right = 0; right < s.size(); ++right) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test Case 1: " << sol.characterReplacement(s1, k1) << endl; // Output: 4

    // Test Case 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test Case 2: " << sol.characterReplacement(s2, k2) << endl; // Output: 4

    // Test Case 3
    string s3 = "AAAA";
    int k3 = 2;
    cout << "Test Case 3: " << sol.characterReplacement(s3, k3) << endl; // Output: 4

    return 0;
}
