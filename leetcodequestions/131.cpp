//Palindrome Partitioning(Medium)
//using backtracking and recursion to find all possible palindrome partitions of a string
//time complexity is O(n*2^n) and space complexity is O(n)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtracking(s, result, temp, 0);
        return result;
    }

    void backtracking(string s, vector<vector<string>>& result, vector<string>& temp, int index) {
        if (index == s.length()) {
            result.emplace_back(temp);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (palindrome(s, index, i)) {
                string present = s.substr(index, i - index + 1);
                temp.push_back(present);
                backtracking(s, result, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    bool palindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string input = "aab";

    vector<vector<string>> partitions = sol.partition(input);

    cout << "Palindrome partitions of \"" << input << "\":" << endl;
    for (const auto& partition : partitions) {
        cout << "[ ";
        for (const string& s : partition) {
            cout << "\"" << s << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
