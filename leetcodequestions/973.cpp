//K Closest Points to Origin(Medium)
//using minheap technique with priority queue
//Time complexity: O(nlogk) where n is the number of points and k is the number of closest points
//Space complexity: O(k) for the priority queue

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k > points.size() || k <= 0) return {{}};
        
        vector<vector<int>> result;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> data;
        
        for (int i = 0; i < points.size(); i++) {
            int Xaxis = points[i][0];
            int Yaxis = points[i][1];
            int sum = (Xaxis * Xaxis) + (Yaxis * Yaxis);  // Distance squared
            data.push({sum, Xaxis, Yaxis});
        }

        for (int i = 0; i < k; i++) {
            auto [sum, Xaxis, Yaxis] = data.top();
            data.pop();
            result.push_back({Xaxis, Yaxis});
        }

        return result;
    }
};

void printResult(const vector<vector<int>>& res) {
    for (auto& point : res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> test1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    cout << "Test Case 1:\n";
    printResult(sol.kClosest(test1, k1));  // Expected: [-2, 2]

    vector<vector<int>> test2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    cout << "Test Case 2:\n";
    printResult(sol.kClosest(test2, k2));  // Expected: [3,3] and [-2,4]

    vector<vector<int>> test3 = {{0, 1}, {1, 0}, {2, 2}, {1, 1}};
    int k3 = 3;
    cout << "Test Case 3:\n";
    printResult(sol.kClosest(test3, k3));  // Expected: [0,1], [1,0], [1,1]

    return 0;
}
