//Largest Rectangle in Histogram(Hard)
//using Monotonic stack
//time complexity: O(n)
//space complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s; // {height, start index}
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int val = heights[i];
            int start = i;

            while (!s.empty() && s.top().first > val) {
                int height = s.top().first;
                int index = s.top().second;
                s.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }

            s.push({val, start});
        }

        while (!s.empty()) {
            int height = s.top().first;
            int index = s.top().second;
            s.pop();
            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};

// Helper to run test
void runTest(vector<int> heights) {
    Solution sol;
    int area = sol.largestRectangleArea(heights);
    cout << "Heights: ";
    for (int h : heights) cout << h << " ";
    cout << "\nMax Area: " << area << "\n\n";
}

int main() {
    // Test case 1
    runTest({2, 1, 5, 6, 2, 3}); // Expected: 10

    // Test case 2
    runTest({2, 4}); // Expected: 4

    // Test case 3
    runTest({2, 1, 2}); // Expected: 3

    return 0;
}

