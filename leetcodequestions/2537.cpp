//Count the Number of Good Subarrays(Medium)
//using atleast approach k distinct elements in the array
//time complexity O(n)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int arrsize = nums.size();
        long long totalsubarrays = (long long)arrsize * (arrsize + 1) / 2;
        return totalsubarrays - atMostk(nums, k - 1);
    }

    long long atMostk(vector<int>& nums, int k) {
        long long count = 0;
        unordered_map<int, int> hash;
        long long temp = 0;
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            temp += hash[nums[i]];
            hash[nums[i]]++;

            while (temp > k) {
                hash[nums[j]]--;
                temp -= hash[nums[j]];
                j++;
            }

            count += (i - j + 1);
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;

    long long result = sol.countGood(nums, k);
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}

