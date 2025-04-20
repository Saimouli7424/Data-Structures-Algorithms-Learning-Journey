//Shortest Path in Binary Matrix
//using BFS
//Time Complexity: O(N^2)
//Space Complexity: O(N^2)

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
        {
            int n = grid.size();
            if(n==0 || grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
            //left,right,top,bottom,topleft,topright,bottomleft, bottomright
            vector<vector<int>>directions={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
            queue<pair<int,int>>q;
            int count=1;
            // vector<vector<bool>>visited(n,vector<bool>(n,false));
            // visited[0][0]=true;
            q.push({0,0});
            grid[0][0]=1;
            while(!q.empty())
            {
                int qsize = q.size();
                for(int i=0;i<qsize;i++)
                {
                    auto[r,c]=q.front();
                    if(r==n-1 && c==n-1)return count;
                    q.pop();
    
                    //all directions
                    for(auto i:directions)
                    {
                        int nr = r+i[0], nc=c+i[1];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                        {
                            // visited[nr][nc]=true;
                            grid[nr][nc]=1;
                            q.push({nr,nc});
                        }
                    }
                }
                count++;
            }
            return -1;
        }
};

void testShortestPath(vector<vector<int>> grid, const string& testName) {
    Solution sol;
    int result = sol.shortestPathBinaryMatrix(grid);
    cout << testName << " => Shortest Path Length: " << result << endl;
}

int main() {
    vector<vector<int>> test1 = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> test2 = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    vector<vector<int>> test3 = {
        {1, 0},
        {0, 0}
    };

    testShortestPath(test1, "Test Case 1");
    testShortestPath(test2, "Test Case 2");
    testShortestPath(test3, "Test Case 3");

    return 0;
}