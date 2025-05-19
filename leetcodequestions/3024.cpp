//Type of Triangle
//time complexity: O(1)
//space complexity: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums.size() != 3) return "none";

        int a = nums[0], b = nums[1], c = nums[2];

        // Triangle validity check
        if (a + b <= c || a + c <= b || b + c <= a) return "none";

        // Triangle type
        if (a == b && b == c) return "equilateral";
        if (a == b || b == c || a == c) return "isosceles";
        return "scalene";
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 3, 3},    // equilateral
        {3, 4, 5},    // scalene
        {1, 1, 2}     // none (invalid triangle)
    };

    for (auto& test : testCases) {
        cout << "Triangle: [" << test[0] << ", " << test[1] << ", " << test[2] << "] => ";
        cout << sol.triangleType(test) << endl;
    }

    return 0;
}
