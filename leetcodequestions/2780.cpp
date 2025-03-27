//Minimum Index of a Valid Split(Medium)
//using unordered_map

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        if (nums.empty()) return -1;

        int n = nums.size();
        unordered_map<int, int> temp;
        int val = 0;
        int maxfreq = INT_MIN;

        // Step 1: Find the dominant element
        for (int num : nums) {
            temp[num]++;
            if (maxfreq < temp[num]) {
                maxfreq = temp[num];
                val = num;
            }
        }

        // Step 2: Check if a valid split is possible
        if (maxfreq * 2 <= n) return -1;

        // Step 3: Find the minimum valid split index
        int tempcount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                tempcount++;
                int firsthalf = i + 1;
                int secondhalf = n - (i + 1);
                int secondhcount = maxfreq - tempcount;

                if (tempcount * 2 > firsthalf && secondhcount * 2 > secondhalf)
                    return i;
            }
        }

        return -1;
    }
};

// Main function to test multiple cases
int main() {
    Solution sol;
    
    vector<vector<int>> testCases = {
        {1, 2, 2, 2},         // Expected Output: 2
        {3, 3, 3, 3, 7, 2, 2}, // Expected Output: -1
        {4, 4, 4, 4, 4, 5, 5}, // Expected Output: 3
        {1, 1, 1, 2, 2, 2, 1}, // Expected Output: -1
        {8, 8, 8, 8, 8, 8}     // Expected Output: 2 (or any valid index)
    };

    for (auto& test : testCases) {
        cout << "Input: ";
        for (int num : test) cout << num << " ";
        cout << "\nOutput: " << sol.minimumIndex(test) << "\n\n";
    }

    return 0;
}
