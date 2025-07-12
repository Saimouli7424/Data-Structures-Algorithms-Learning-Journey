//Path With Minimum Effort(Medium)
//Using BinarySearch+BFS method it's better approach (	O(m × n × log(maxHeightDiff)) )
//Using Dijkstra's algorithm + matrix(min value) is optimal approach
// Time complexity is O(m * n * log(m * n))
//space complexity is O(m * n) for the saving each cell min value

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //using Dijkstra Algorithm
        //time complexity O(m × n × log(m × n))
        int rows=heights.size();
        int cols=heights[0].size();

        //finding min diff at each cell same space complexity O(m*n)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});

        vector<int>rdir={0,0,-1,1};
        vector<int>cdir={-1,1,0,0};

        //time taken and push all the values O(m*n)
        // vector<vector<int>>visited(rows,vector<int>(cols,0));
        while(!pq.empty()){
            auto[wt,r,c]=pq.top();
            pq.pop();
            if(r==rows-1 && c==cols-1)return wt;

            for(int i=0;i<4;i++){
                int nr=r+rdir[i], nc=c+cdir[i];
                if(nr>=0 && nc>=0 && nr<rows && nc<cols){
                    int currWt = abs(heights[nr][nc]-heights[r][c]);
                    int maxWt = max(wt,currWt);

                    if(dist[nr][nc]>maxWt){
                        dist[nr][nc]=maxWt;
                        pq.push({maxWt,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};

// Utility function to run test cases
void runTest(vector<vector<int>> heights, int expected) {
    Solution sol;
    int result = sol.minimumEffortPath(heights);
    cout << "Result: " << result << " | Expected: " << expected;
    if (result == expected) cout << " ✅" << endl;
    else cout << " ❌" << endl;
}

int main() {
    // Test Case 1
    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    runTest(heights1, 2);  // Expected output: 2

    // Test Case 2
    vector<vector<int>> heights2 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}
    };
    runTest(heights2, 1);  // Expected output: 1

    // Test Case 3
    vector<vector<int>> heights3 = {
        {1, 2, 1, 1, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 1, 1, 2, 1}
    };
    runTest(heights3, 0);  // Expected output: 0

    return 0;
}
