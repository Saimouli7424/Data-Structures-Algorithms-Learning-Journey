//Merge Intervals leetcode 56(medium)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};  // Handle empty input case early
        
        sort(intervals.begin(), intervals.end());  // Sort intervals based on start time
        vector<vector<int>> result;
        
        result.push_back(intervals[0]);  // Start with the first interval
        
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i][0]) {  // If overlap occurs
                result.back()[1] = max(result.back()[1], intervals[i][1]);  // Merge intervals
            } else {
                result.push_back(intervals[i]);  // No overlap, add new interval
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
