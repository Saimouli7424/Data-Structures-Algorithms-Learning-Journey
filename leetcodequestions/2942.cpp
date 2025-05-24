//Find Words Containing Character(Easy)
//space complexity: O(n), where n is the number of words in the input vector.
//time complexity: O(m * n), where m is the average length of the words and n is the number of words in the input vector.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

void printResult(const vector<int>& indices) {
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<string> words1 = {"apple", "banana", "cherry", "date"};
    char x1 = 'a';
    vector<int> result1 = sol.findWordsContaining(words1, x1);
    cout << "Test Case 1 (char: 'a') Output: ";
    printResult(result1);

    // Test Case 2
    vector<string> words2 = {"dog", "cat", "elephant", "tiger"};
    char x2 = 'e';
    vector<int> result2 = sol.findWordsContaining(words2, x2);
    cout << "Test Case 2 (char: 'e') Output: ";
    printResult(result2);

    // Test Case 3
    vector<string> words3 = {"mango", "peach", "plum"};
    char x3 = 'z';
    vector<int> result3 = sol.findWordsContaining(words3, x3);
    cout << "Test Case 3 (char: 'z') Output: ";
    printResult(result3);

    return 0;
}
