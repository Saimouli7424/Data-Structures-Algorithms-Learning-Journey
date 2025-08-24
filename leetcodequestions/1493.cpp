//Longest Subarray of 1's After Deleting One Element(Medium)
//TimeComplexity: O(n)
//SpaceComplexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeroCount = 0, maxLen = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;

            while (zeroCount > 1) {   // shrink window if more than 1 zero
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen, right - left); // length after deleting one zero
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1,1,0,1},             // Expected output: 3
        {0,1,1,1,0,1,1,0,1},   // Expected output: 5
        {1,1,1,1},             // Expected output: 3 (delete one element)
        {0,0,0},               // Expected output: 0
    };

    for (auto &tc : testCases) {
        cout << "Input: ";
        for (int x : tc) cout << x << " ";
        cout << "\nOutput: " << sol.longestSubarray(tc) << endl << endl;
    }

    return 0;
}
