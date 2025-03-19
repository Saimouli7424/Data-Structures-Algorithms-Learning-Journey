//3191. Minimum Operations to Make Binary Array Elements Equal to One I(Medium)
//using sliding window
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int ops = 0;
    
            for (int i = 0; i <= n - 3; i++) {
                if ((nums[i] & 1) == 0) {  
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                    ops++;
                }
            }
            return all_of(nums.begin(), nums.end(), [](int x) { return x == 1; }) ? ops : -1;
        }
    };

int main(){
    Solution s;
    vector<int> nums = {0,1,1,1,0,0};
    cout<<s.minOperations(nums)<<endl;
    return 0;
}
// Time: O(n)
// Space: O(1)
/*
Input: nums = [0,1,1,1,0,0]

Output: 3

Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
*/