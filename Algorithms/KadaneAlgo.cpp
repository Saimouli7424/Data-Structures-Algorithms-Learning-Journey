#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Function to find the maximum subarray sum using Kadane’s Algorithm.
 * It keeps track of the maximum sum ending at each position and updates the overall max sum.
 * 
 * @param nums - The input array of integers.
 * @return The maximum subarray sum.
 */
int kadane(vector<int>& nums) {
    int maxSum = INT_MIN; // Stores the maximum sum found so far
    int currentSum = 0;   // Stores the sum of the current subarray

    for (int num : nums) {
        // Either extend the current subarray or start a new subarray
        currentSum = max(num, currentSum + num);

        // Update the maximum subarray sum found so far
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    // Output the maximum subarray sum
    cout << "Maximum Subarray Sum: " << kadane(nums) << endl; // Expected Output: 6
    
    return 0;
}


// Step-by-Step Execution
// Step	Element	currSum (Current Subarray Sum)	maxSum (Max Sum Found)
// 1	-2	-2	-2
// 2	1	1 (Reset since 1 > -1)	1
// 3	-3	-2	1
// 4	4	4 (Reset)	4
// 5	-1	3	4
// 6	2	5	5
// 7	1	6	6
// 8	-5	1	6
// 9	4	5	6
// The final answer is: 6 (subarray: [4, -1, 2, 1])
// The maximum subarray is [4, -1, 2, 1] which sums to 6.