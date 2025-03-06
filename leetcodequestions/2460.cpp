//Apply Operations on Array leetcode 2460

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        vector<int> result(n, 0);
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                result[index++] = nums[i];
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {2, 2, 0, 4, 4, 8};
    Solution sol;
    vector<int> result = sol.applyOperations(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

