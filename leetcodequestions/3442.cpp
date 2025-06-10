//Maximum Difference Between Even and Odd Frequency I
//using unordered_map
//time complexity: O(n)
//space complexity: O(n)
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s) 
    {
        unordered_map<char, int> mp;
        for (auto ch : s)
            mp[ch]++;

        int oddfreq = 0;
        int evenfreq = INT_MAX;
        bool hasEven = false, hasOdd = false;

        for (auto i : mp)
        {
            if (i.second % 2 == 0) {
                hasEven = true;
                evenfreq = min(evenfreq, i.second);
            } else {
                hasOdd = true;
                oddfreq = max(oddfreq, i.second);
            }
        }

        if (hasEven && hasOdd)
            return oddfreq - evenfreq;
        else if (hasOdd)
            return oddfreq;
        else if (hasEven)
            return evenfreq;

        return 0; // Edge case: empty string
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "tzt";
    cout << "maxDifference(\"" << s1 << "\") = " << sol.maxDifference(s1) << endl;

    // Test case 2
    string s2 = "aabbccc";
    cout << "maxDifference(\"" << s2 << "\") = " << sol.maxDifference(s2) << endl;

    // Test case 3
    string s3 = "zzz";
    cout << "maxDifference(\"" << s3 << "\") = " << sol.maxDifference(s3) << endl;

    return 0;
}
