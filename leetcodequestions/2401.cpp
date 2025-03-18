//Longest Nice Subarray(Medium)
//Sliding window
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) 
        {
            int left = 0, orVal = 0, maxLen = 0;
    
            for (int right = 0; right < nums.size(); right++) {
                while ((orVal & nums[right]) != 0) {
                    orVal ^= nums[left];
                    left++;
                }
                orVal |= nums[right];
                maxLen = max(maxLen, right - left + 1);
            }
    
            return maxLen;
        }
    };

int main()
{
    Solution s;
    vector<int> nums = {1,3,8,48,10};
    cout<<s.longestNiceSubarray(nums)<<endl;
    return 0;
}

//Time Complexity: O(n)
//Space Complexity: O(1)
/*
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Step-by-Step Execution Using the Sliding Window Approach:
Initialization:
left = 0: The start of the sliding window.
orVal = 0: Maintains the bitwise OR of elements in the current window.
maxLen = 0: Stores the length of the longest nice subarray.
Iterate Over nums Using Right Pointer (right)
Step	right	nums[right]	OR Value Before	OR Value After	Conflict?	left Moves?	MaxLen
1	0	1	0	1	No	No	1
2	1	3	1	`1	3 = 3`	No	No
3	2	8	3	`3	8 = 11`	No	No
4	3	48	11	`11	48 = 59`	No	No
5	4	10	59	`59	10 = 59`	Yes	Yes (left++ to shrink window)
Why Does the left Pointer Move?
At right = 4 (element 10), orVal | nums[right] = 59, which means there is bit overlap.
We must shrink the window (left++) until orVal & nums[right] == 0.
Shrinking the Window (left Moves Right)
Remove nums[left] = 1: orVal ^= 1 (OR value remains 58).
Remove nums[left] = 3: orVal ^= 3 (OR value becomes 56).
Remove nums[left] = 8: orVal ^= 8 (OR value becomes 48).
Now, [3, 8, 48] was the longest valid subarray before a conflict arose, so maxLen = 3.

Final Output:
cpp
Copy
Edit
3
Final Longest Nice Subarray: [3, 8, 48]
Key Takeaways:
Use a sliding window: Expand right, and shrink left when a conflict arises.
Maintain an orVal: If orVal & nums[right] != 0, move left forward.
Keep track of the max valid subarray length
*/