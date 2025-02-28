//leetcode 985

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        int intermediate = 0;
        
        // Calculate the initial sum of even numbers
        for (auto i : nums) {
            if (i % 2 == 0) {
                intermediate += i;
            }
        }

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][1];  // The index in nums where the query is applied
            int temp = nums[index];      // The original value at the index

            // Apply the query: update the number at the given index
            nums[index] = temp + queries[i][0];
            
            // If the value has changed, we need to update the intermediate sum
            if (nums[index] != temp) {
                // If the original value was even, remove it from intermediate
                if (temp % 2 == 0) {
                    intermediate -= temp;
                }
                
                // If the updated value is even, add it to intermediate
                if (nums[index] % 2 == 0) {
                    intermediate += nums[index];
                }
            }

            // Store the result after processing the query
            result.push_back(intermediate);
        }

        return result;
    }
};

int main() {

    vector<int> nums = {8,-10,10,-7,4,-2};
    vector<vector<int>> queries = {{6,4},{-7,0},{-3,5},{6,1},{-8,1},{-10,2}};
    //[16,8,10,16,8,-2]
    Solution sol;
    vector<int> result = sol.sumEvenAfterQueries(nums, queries);
    
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;
    
    return 0;
}
