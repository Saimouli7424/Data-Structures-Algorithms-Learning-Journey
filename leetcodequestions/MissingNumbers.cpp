//leetcode 448
#include <iostream>
#include <vector>
#include <cmath>  // For abs() function

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Mark the visited numbers by making them negative
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;  // Get the correct index
            if (nums[index] > 0) {
                nums[index] = -nums[index];  // whatever the value there that particular index that value will be -value;
            }
        }

        vector<int> result;
        // Find numbers that were not visited (still positive)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);  // Missing number
            }
        }

        return result;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // Example input
    vector<int> missingNumbers = sol.findDisappearedNumbers(nums);

    // Print the missing numbers
    cout << "Missing numbers: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
