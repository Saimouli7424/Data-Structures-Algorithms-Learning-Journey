//Longest Substring Without Repeating Characters(Medium)
//Using sliding window and set
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> temp;
        int maxelem = 0;
        int i = 0, j = 0;
        
        while (j < s.length()) {
            if (temp.find(s[j]) == temp.end()) {
                temp.insert(s[j]);
                maxelem = max(maxelem, (j - i) + 1);
                j++;
            } else {
                temp.erase(s[i]);
                i++;
            }
        }
        return maxelem;
    }
};

int main() {
    Solution solution;
    string s ="abcabcbb";
    
    
    
    int result = solution.lengthOfLongestSubstring(s);
    
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    
    return 0;
}
// Time complexity: O(n), where n is the length of the string s
// Space complexity: O(min(n, m)), where n is the length of the string s and m is the size of the character set
// This is because we are using a set to store the characters in the current substring, and the size of the set can be at most m (the number of unique characters in the string).
// The sliding window approach allows us to efficiently find the longest substring without repeating characters by maintaining a window of characters and adjusting its size as we encounter duplicates.
// The set data structure provides O(1) average time complexity for insertions and deletions, making it suitable for this problem.
