#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Interval class definition
class Interval {
public:
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

// Solution class
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        // Min-heap to track end times
        priority_queue<int, vector<int>, greater<int>> pq;

        // Add the first meeting's end time
        pq.push(intervals[0].end);

        // Iterate over the rest
        for (int i = 1; i < intervals.size(); ++i) {
            int currStart = intervals[i].start;
            int currEnd = intervals[i].end;

            // If a room is free (start >= earliest end), reuse it
            if (currStart >= pq.top()) {
                pq.pop();
            }

            pq.push(currEnd);
        }

        return pq.size();
    }
};

// Utility function to print test results
void test(vector<Interval> intervals, int expected, int testCase) {
    Solution sol;
    int result = sol.minMeetingRooms(intervals);
    cout << "Test Case " << testCase << ": ";
    cout << (result == expected ? "Passed" : "Failed");
    cout << " (Expected: " << expected << ", Got: " << result << ")\n";
}

int main() {
    // Test Case 1: Overlapping intervals
    vector<Interval> test1 = { Interval(5, 8), Interval(6, 8) };
    test(test1, 2, 1);

    // Test Case 2: Non-overlapping meetings
    vector<Interval> test2 = { Interval(1, 2), Interval(3, 4), Interval(5, 6) };
    test(test2, 1, 2);

    // Test Case 3: Mixed overlaps
    vector<Interval> test3 = { Interval(0, 30), Interval(5, 10), Interval(15, 20) };
    test(test3, 2, 3);

    return 0;
}
