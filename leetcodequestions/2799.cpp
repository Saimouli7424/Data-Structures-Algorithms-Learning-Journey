//Count Complete Subarrays in an Array(Medium)
//using sliding window + Atmost technique
//time complexity O(n)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int elements = unique.size();
        return Atmost(elements, nums) - Atmost(elements - 1, nums);
    }

    int Atmost(int k, vector<int>& nums) {
        unordered_map<int, int> freq;
        int j = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            while (freq.size() > k) {
                freq[nums[j]]--;
                if (freq[nums[j]] == 0) {
                    freq.erase(nums[j]);
                }
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1, 2, 2};

    int result = sol.countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl;

    return 0;
}
