//Minimize the Maximum Difference of Pairs(Medium)
//Using binarysearch on answers by using the difference and checking the pairs to find the minimum maximum difference of pairs.
//time complexity: O(nlogn)
//space complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Check if we can form at least 'p' pairs with maxDiff or less
    bool pairCheck(const vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // pair used, skip both
            } else {
                i++; // try next element
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        if (p == 0) return 0;

        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (pairCheck(nums, mid, p)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

// Test function
void runTest(vector<int> nums, int p, int expected) {
    Solution sol;
    int result = sol.minimizeMax(nums, p);
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "], p = " << p << "\n";
    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << "\n\n";
}

// Main function
int main() {
    runTest({1, 3, 6, 19, 20}, 2, 2);
    runTest({10, 1, 2, 7, 12, 15}, 2, 2);
    runTest({1, 1000}, 1, 999);
    runTest({1, 1, 1, 1}, 2, 0);
    runTest({1, 5, 9, 12, 15, 17}, 2, 4);

    return 0;
}
