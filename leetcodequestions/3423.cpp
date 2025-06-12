//Maximum Difference Between Adjacent Elements in a Circular Array(easy)
//Time complexity: O(n)
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int maxDiff = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int temp = abs(nums[i] - nums[i + 1]);
            maxDiff = max(maxDiff, temp);
        }
        maxDiff = max(maxDiff, abs(nums[0] - nums[nums.size() - 1]));
        return maxDiff;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 3, 7, 2};
    vector<int> test2 = {10, 20, 30, 40};
    vector<int> test3 = {5, 1, 5};

    cout << "Test 1: " << sol.maxAdjacentDistance(test1) << endl;  // Expected: 5 (|7 - 2|)
    cout << "Test 2: " << sol.maxAdjacentDistance(test2) << endl;  // Expected: 10
    cout << "Test 3: " << sol.maxAdjacentDistance(test3) << endl;  // Expected: 4 (|5 - 1| or |1 - 5|)

    return 0;
}
