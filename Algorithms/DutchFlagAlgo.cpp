#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int num : vec)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    cout << "Sorted colors (Test 1): ";
    printVector(nums1);

    // Test Case 2
    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    cout << "Sorted colors (Test 2): ";
    printVector(nums2);

    // Test Case 3
    vector<int> nums3 = {1, 2, 0, 1, 2, 0, 1};
    sol.sortColors(nums3);
    cout << "Sorted colors (Test 3): ";
    printVector(nums3);

    return 0;
}
