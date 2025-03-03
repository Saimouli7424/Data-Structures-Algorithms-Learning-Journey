#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> data;

        if(nums.size() == 1) {
            data.emplace_back(nums[0]);
            return data;
        }

        // Count frequency of each element
        for(auto i : nums) {
            hash[i]++;
        }

        // Find elements with frequency greater than n/3
        for(auto it : hash) {
            if(it.second > (nums.size() / 3)) {
                data.emplace_back(it.first);
            }
        }

        return data;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution obj;
    vector<int> result = obj.majorityElement(nums);

    cout << "Majority Elements: ";
    for(auto i : result) {
        cout << i << " ";
    }
    return 0;
}
