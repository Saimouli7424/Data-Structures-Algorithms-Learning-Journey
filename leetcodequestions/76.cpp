//Minimum Window Substring(Hard)
//Using sliding window and unordered_map 
//time complexity: O(n)
//space complexity: O(m) where m is the number of unique characters in t

#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> tmp;
        unordered_map<char, int> windowmp;

        for (auto c : t) {
            tmp[c]++;
        }

        int left = 0, right = 0, have = 0, startIdx = 0;
        int needed = tmp.size(), minLen = INT_MAX;

        for (; right < s.length(); right++) {
            char ch = s[right];
            if (tmp.count(ch)) {
                windowmp[ch]++;
                if (windowmp[ch] == tmp[ch]) have++;
            }

            while (have == needed) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                if (tmp.count(leftChar)) {
                    windowmp[leftChar]--;
                    if (windowmp[leftChar] < tmp[leftChar]) {
                        have--;
                    }
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Test 1: " << sol.minWindow(s1, t1) << endl; // Expected: "BANC"

    // Test case 2
    string s2 = "a";
    string t2 = "a";
    cout << "Test 2: " << sol.minWindow(s2, t2) << endl; // Expected: "a"

    // Test case 3
    string s3 = "a";
    string t3 = "aa";
    cout << "Test 3: " << sol.minWindow(s3, t3) << endl; // Expected: ""

    return 0;
}

