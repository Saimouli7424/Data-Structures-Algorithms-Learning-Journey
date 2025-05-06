//Build Array from Permutation(Easy)
//Time Complexity: O(n)
//Space Complexity: O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.emplace_back(nums[nums[i]]);
        }
        return result;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {0, 2, 1, 5, 3, 4};
    vector<int> result1 = sol.buildArray(nums1);
    cout << "Test Case 1: ";
    printVector(result1);  // Output: 0 1 2 4 5 3

    // Test case 2
    vector<int> nums2 = {5, 0, 1, 2, 3, 4};
    vector<int> result2 = sol.buildArray(nums2);
    cout << "Test Case 2: ";
    printVector(result2);  // Output: 4 5 0 1 2 3

    // Test case 3
    vector<int> nums3 = {4, 3, 2, 1, 0};
    vector<int> result3 = sol.buildArray(nums3);
    cout << "Test Case 3: ";
    printVector(result3);  // Output: 0 1 2 3 4

    return 0;
}
