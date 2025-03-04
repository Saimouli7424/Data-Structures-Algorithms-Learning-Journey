//leetcode 128
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case: empty array

        unordered_set<int> numSet(nums.begin(), nums.end()); // Store unique elements
        int maxLength = 0; // Track max sequence length

        for (int num : numSet) { // Iterate over unique numbers
            // Start counting only when `num-1` is NOT in the set (beginning of sequence)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int count = 1;

                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    count++;
                }

                maxLength = max(maxLength, count);
            }
        }
        return maxLength;
    }
};

// Driver Code
int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << solution.longestConsecutive(nums) << endl;
    return 0;
}
