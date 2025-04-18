//Maze problem using DFS
//time complexity O(4^(n*m)) where n is the number of rows and m is the number of columns in the grid
//space complexity O(n*m) for the recursion stack and result storage
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<char>>& result,vector<char>& temp)
{
    int rows = grid.size();
    int cols = grid[0].size();
    if(i==rows-1 && j==cols-1)
    {
        result.emplace_back(temp);
        return;
    }
    vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // D L R U
    vector<char> d = {'D', 'L', 'R', 'U'};

    grid[i][j]=0;//Marking as Visited

    for(int k=0;k<4;k++)
    {
        int nr=i+directions[k].first, nc=j+directions[k].second;
        if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]==1)
        {
            temp.emplace_back(d[k]);
            dfs(grid,nr,nc,result,temp);
            temp.pop_back();
        }
    }
    grid[i][j]=1;
}

int main()
{
    vector<vector<int>> grid =  { {1, 0, 0, 0} , {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    vector<vector<char>>result;
    vector<char>temp;
    dfs(grid,0,0,result,temp);
    for (auto& path : result) {
        for (char c : path) cout << c;
        cout << endl;
    }
    return 0;
}