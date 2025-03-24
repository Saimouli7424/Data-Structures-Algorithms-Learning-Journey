//Count Days Without Meetings(Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int val = 0, prev = 1, maxelem = 0;

        if (meetings.empty()) return days; // If no meetings, all days are free

        if (meetings.size() == 1) {
            if (meetings[0][0] > 1) { // Count free days before the first meeting
                val += meetings[0][0] - 1;
            }
            val += (days - meetings[0][1]); // Free days after the last meeting
            return val;
        }

        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i][0] > prev) { // Count free days correctly
                val += meetings[i][0] - prev;
            }
            prev = max(prev, meetings[i][1] + 1); // Update last occupied day
            maxelem = max(maxelem, meetings[i][1]);
        }

        if (maxelem < days) val += (days - maxelem); // Count remaining free days
        return val;
    }
};

int main() {
    Solution sol;
    
    int days = 10;
    vector<vector<int>> meetings = {{2, 3}, {5, 7}, {8, 9}}; // Example test case
    
    cout << "Free days: " << sol.countDays(days, meetings) << endl;
    
    return 0;
}
