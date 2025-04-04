//Maximum Alternating Subsequence Sum(Medium)

#include <iostream>
#include <vector>
#include <algorithm> // for max
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        long long even = 0, odd = 0;
        for (int num : nums) {
            long long new_even = max(even, odd + num);
            long long new_odd = max(odd, even - num);
            even = new_even;
            odd = new_odd;
        }
        return even;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {4, 2, 5, 3};

    // Call the function
    long long result = sol.maxAlternatingSum(nums);

    // Print the result
    cout << "Maximum Alternating Subsequence Sum: " << result << endl;

    return 0;
}
