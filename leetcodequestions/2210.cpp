//Count Hills and Valleys in an Array(Easy)
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1]) continue;

            int left = i - 1;
            while (left >= 0 && nums[left] == nums[i]) left--;

            int right = i + 1;
            while (right < n && nums[right] == nums[i]) right++;

            if (left >= 0 && right < n) {
                if ((nums[i] > nums[left] && nums[i] > nums[right]) ||
                    (nums[i] < nums[left] && nums[i] < nums[right])) {
                    total++;
                    }
            }
        }

        return total;
    }
};

// Helper to print test case results
void runTest(vector<int> nums, int expected) {
    Solution sol;
    int result = sol.countHillValley(nums);
    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << "\nOutput: " << result << " | Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed" : "❌ Failed") << "\n\n";
}

int main() {
    runTest({2, 4, 1, 1, 6, 5}, 3);            // Hills: 4, 6 | Valleys: 1 => total 3
    runTest({6, 6, 5, 5, 4, 1}, 0);            // No hill or valley
    runTest({1, 2, 2, 3, 2, 1}, 1);            // Valley at 2 (between 3 and 1)
    runTest({5, 5, 5, 5}, 0);                  // All same elements
    return 0;
}
