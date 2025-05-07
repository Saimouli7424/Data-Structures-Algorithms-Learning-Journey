//Number of Equivalent Domino Pairs(Easy)
//using unordered_map to count pairs of dominoes
//Time complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        unordered_map<int, int> freq;

        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;  // unique key from 0 to 99

            count += freq[key];   // count of pairs formed so far
            freq[key]++;
        }

        return count;
    }
};

// Helper function to print test result
void test(vector<vector<int>> dominoes) {
    Solution sol;
    int result = sol.numEquivDominoPairs(dominoes);
    cout << "Number of Equivalent Domino Pairs: " << result << endl;
}

int main() {
    // Test case 1
    vector<vector<int>> test1 = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    test(test1);  // Output: 1

    // Test case 2
    vector<vector<int>> test2 = {{1, 2}, {1, 2}, {1, 2}, {1, 2}};
    test(test2);  // Output: 6

    // Test case 3
    vector<vector<int>> test3 = {{1, 1}, {1, 1}, {1, 2}, {2, 1}, {2, 2}};
    test(test3);  // Output: 3

    return 0;
}
