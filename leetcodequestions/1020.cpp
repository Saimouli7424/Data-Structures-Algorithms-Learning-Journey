//Number of Enclaves(Medium)
//using DFS and BFS to find the number of enclaves in a grid
//Time complexity: O(n*m)
//space complexity: O(n)
//got best time complexity in BFS approach
#include<bits/stdc++.h>
using namespace std;
//BFS Approach
class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid)
        {
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
            queue<pair<int,int>>q;
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if((i==0||i==rows-1||j==0||j==cols-1)&&grid[i][j]==1)
                    {
                        q.push({i,j});
                        grid[i][j]=0;
                    }
                }
            }
    
            while(!q.empty())
            {
                auto[r,c]=q.front();
                q.pop();
                for(auto i:directions)
                {
                    int nr=r+i[0], nc=c+i[1];
                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc])
                    {
                        q.push({nr,nc});
                        grid[nr][nc]=0;
                    }
                }
            }
    
            int count=0;
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if(grid[i][j])count++;
                }
            }
    
            return count;
        }
    };
/*
//DFS Approach
class Solution {
    public:
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        void dfs(int rows,int cols,int r,int c,vector<vector<int>>& grid)
        {
            for(auto i:directions)
            {
                grid[r][c]=0;
                int nr = r+i[0], nc = c+i[1];
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc])
                {
                    dfs(rows,cols,nr,nc,grid);
                }
            }
        }
    
        int numEnclaves(vector<vector<int>>& grid)
        {
            int rows = grid.size();
            int cols = grid[0].size();
            //not using boolean because by default using grid values as already 0 and 1
            for(int j=0;j<cols;j++)
            {
                if(grid[0][j])dfs(rows,cols,0,j,grid);
                if(grid[rows-1][j])dfs(rows,cols,rows-1,j,grid);
            }
    
            for(int i=0;i<rows;i++)
            {
                if(grid[i][0])dfs(rows,cols,i,0,grid);
                if(grid[i][cols-1])dfs(rows,cols,i,cols-1,grid);
            }
    
            int count=0;
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if(grid[i][j])count++;
                }
            }
    
            return count;
        }
    };
*/

void printGrid(const vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> test1 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    vector<vector<int>> test2 = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };

    vector<vector<int>> test3 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    cout << "Test 1:\n";
    printGrid(test1);
    cout << "Enclaves: " << sol.numEnclaves(test1) << endl;

    cout << "Test 2:\n";
    printGrid(test2);
    cout << "Enclaves: " << sol.numEnclaves(test2) << endl;

    cout << "Test 3:\n";
    printGrid(test3);
    cout << "Enclaves: " << sol.numEnclaves(test3) << endl;

    return 0;
}