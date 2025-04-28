//Trapping Rain Water(Hard)
//using two pointers
//Time complexity: O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int left = 0, leftmax = 0;
        int right = n - 1, rightmax = 0;
        int totalwater = 0;
        
        while (left < right)
        {
            if (height[left] < height[right]) {
                if (height[left] >= leftmax) {
                    leftmax = height[left];
                }
                totalwater += leftmax - height[left];
                left++;
            } else {
                if (height[right] >= rightmax) {
                    rightmax = height[right];
                }
                totalwater += rightmax - height[right];
                right--;
            }
        }

        return totalwater;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test Case 1 Water Trapped: " << sol.trap(height1) << endl;  // Output: 6

    // Test case 2
    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Test Case 2 Water Trapped: " << sol.trap(height2) << endl;  // Output: 9

    // Test case 3
    vector<int> height3 = {2,0,2};
    cout << "Test Case 3 Water Trapped: " << sol.trap(height3) << endl;  // Output: 2

    return 0;
}
