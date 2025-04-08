//Minimum Number of Operations to Make Elements in Array Distinct(Easy)
//using unordered_set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int finalcount = 0;
        int i = 0;
        while (!makedistinct(nums, i))
        {
            finalcount++;
            i += 3;
        }
        return finalcount;
    }

    bool makedistinct(vector<int>& nums, int index)
    {
        unordered_set<int> s;
        for (int i = index; i < nums.size(); i++)
        {
            if (s.count(nums[i])) return false;
            s.insert(nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {5, 5, 3, 4};

    // Function call
    int result = sol.minimumOperations(nums);
    
    cout << "Minimum operations: " << result << endl;

    return 0;
}
