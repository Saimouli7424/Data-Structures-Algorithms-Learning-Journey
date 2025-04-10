//Separate Black and White Balls(Medium)
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long onec = 0;         // Count of 1s encountered
        long long totalswap = 0;    // Total number of swaps needed

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                totalswap += onec;  // Every 0 needs to pass over all previous 1s
            } else {
                onec++;             // Count 1s
            }
        }

        return totalswap;
    }
};

int main() {
    Solution sol;

    string s="110010101"; // Example input string

    long long result = sol.minimumSteps(s);
    cout << "Minimum number of swaps to move all 0s to the left: " << result << endl;

    return 0;
}
