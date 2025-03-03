//leetcode 229
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        int n = nums.size();

        // Step 1: Find potential candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) {
                count1++;
            }
            else if (nums[i] == num2) {
                count2++;
            }
            else if (count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the candidates
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) count1++;
            else if (nums[i] == num2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.emplace_back(num1);
        if (count2 > n / 3) result.emplace_back(num2);

        return result;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution obj;
    vector<int> result = obj.majorityElement(nums);

    cout << "Majority Elements: ";
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
