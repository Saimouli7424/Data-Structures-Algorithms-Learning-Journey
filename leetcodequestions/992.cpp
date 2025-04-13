//Subarrays with K Different Integers(Medium)
//Using sliding window
//Time complexity: O(n)
//Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return findoccurrences(nums, k) - findoccurrences(nums, k - 1);
        //always use the above formula whenever they ask k distinct elements
    } 

    int findoccurrences(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int totalcount = 0, j = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;

            // Shrink the window when the size of the map exceeds k
            while (mp.size() > k)
            {
                mp[nums[j]]--;
                if (mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }

            totalcount += (i - j) + 1; // Count the subarrays with at most k distinct elements
        }

        return totalcount;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Test case 1: " << sol.subarraysWithKDistinct(nums1, k1) << endl;  // Expected output: 7

    // Test case 2
    vector<int> nums2 = {1, 2, 1, 2, 3};
    int k2 = 3;
    cout << "Test case 2: " << sol.subarraysWithKDistinct(nums2, k2) << endl;  // Expected output: 6

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 4};
    int k3 = 4;
    cout << "Test case 3: " << sol.subarraysWithKDistinct(nums3, k3) << endl;  // Expected output: 4

    return 0;
}
