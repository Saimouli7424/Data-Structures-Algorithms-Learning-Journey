//Maximum Profit in Job Scheduling(Hard)
//using priority queue
//can do using binary search+dfs aswell
//time complexity: O(nlogn) is same for both
//space complexity: O(n) is same for both
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();

        // Step 1: Create vector of jobs as tuples: {startTime, endTime, profit}
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Step 2: Sort jobs by startTime
        sort(jobs.begin(), jobs.end());

        // Min-heap: stores {endTime, totalProfit}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            int s, e, p;
            tie(s, e, p) = jobs[i];

            // Step 3: Remove all jobs that end before current job starts
            while (!pq.empty() && pq.top().first <= s) {
                maxProfit = max(maxProfit, pq.top().second);
                pq.pop();
            }

            // Step 4: Profit = max of previous non-overlapping + current job
            int sum = maxProfit + p;
            pq.push({e, sum});
        }

        // Step 5: Final max profit might still be in heap
        while (!pq.empty()) {
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }

        return maxProfit;
    }
};

// =====================
// ✅ Driver Code
// =====================
int main() {
    Solution sol;

    // Test Case 1
    vector<int> s1 = {1, 2, 3, 3};
    vector<int> e1 = {3, 4, 5, 6};
    vector<int> p1 = {50, 10, 40, 70};
    cout << "Test 1 Expected: 120, Got: " << sol.jobScheduling(s1, e1, p1) << endl;

    // Test Case 2
    vector<int> s2 = {1, 2, 3, 4, 6};
    vector<int> e2 = {3, 5, 10, 6, 9};
    vector<int> p2 = {20, 20, 100, 70, 60};
    cout << "Test 2 Expected: 150, Got: " << sol.jobScheduling(s2, e2, p2) << endl;

    // Test Case 3 (Edge Case: All jobs overlap, pick max profit one)
    vector<int> s3 = {1, 1, 1};
    vector<int> e3 = {3, 3, 3};
    vector<int> p3 = {5, 10, 15};
    cout << "Test 3 Expected: 15, Got: " << sol.jobScheduling(s3, e3, p3) << endl;

    return 0;
}
