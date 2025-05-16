//Longest Unequal Adjacent Groups Subsequence I(Medium)
//Time Complexity: O(n)
//Using Greedy Approach
//Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        if(groups.empty() || words.empty()) return {};

        int expected = 0;
        vector<string> expectedzero;

        for(int i = 0; i < words.size(); i++)
        {
            if(groups[i] == expected)
            {
                expectedzero.emplace_back(words[i]);
                expected ^= 1;
            }
        }

        vector<string> expectedone;
        expected = 1;
        for(int i = 0; i < words.size(); i++)
        {
            if(groups[i] == expected)
            {
                expectedone.emplace_back(words[i]);
                expected ^= 1;
            }
        }

        return (expectedone.size() < expectedzero.size()) ? expectedzero : expectedone;
    }
};

// Utility function to print a vector of strings
void printVector(const vector<string>& vec) {
    for(const string& word : vec) {
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<string> words1 = {"a", "b", "c", "d", "e"};
    vector<int> groups1 = {0, 1, 0, 1, 0};
    cout << "Test Case 1 Output: ";
    printVector(sol.getLongestSubsequence(words1, groups1));

    // Test Case 2
    vector<string> words2 = {"one", "two", "three", "four", "five"};
    vector<int> groups2 = {1, 1, 0, 1, 0};
    cout << "Test Case 2 Output: ";
    printVector(sol.getLongestSubsequence(words2, groups2));

    // Test Case 3
    vector<string> words3 = {"apple", "banana", "cherry", "date"};
    vector<int> groups3 = {0, 0, 1, 1};
    cout << "Test Case 3 Output: ";
    printVector(sol.getLongestSubsequence(words3, groups3));

    return 0;
}
