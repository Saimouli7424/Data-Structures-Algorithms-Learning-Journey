//Leetcode 136
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; 
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    int singleNum = solution.singleNumber(nums);
    cout << "The single number is: " << singleNum << endl;

    return 0;
}

    
/* Explanation:
    ex:- vector<int> nums = {4, 1, 2, 1, 2};
    Step-by-Step Execution:
    Step	Current i	XOR Operation (val ^= i)	val Value
    1	        4	            0 ^ 4                  4
    2	        1	            4 ^ 1                  5
    3	        2	            5 ^ 2                  7
    4	        1	            7 ^ 1                  6
    5	        2	            6 ^ 2                  4

    the thing was whatever the value done by xor if it occurred again by xor operation properties the value becomes diff
*/