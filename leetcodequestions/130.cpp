//Surrounded Regions(Medium)
//Using DFS and BFS but DFS is better
//time complexity is O(n*m) and space complexity is O(n*m)

#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    void dfs(int r, int c, int rows, int cols, vector<vector<bool>>& visited, vector<vector<char>>& board)
    {
        visited[r][c] = true;
        for(auto& dir : directions)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O' && !visited[nr][nc])
            {
                dfs(nr, nc, rows, cols, visited, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int rows = board.size();
        if(rows == 0) return;
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Check boundary rows
        for(int j = 0; j < cols; ++j)
        {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, rows, cols, visited, board);
            if(board[rows - 1][j] == 'O' && !visited[rows - 1][j])
                dfs(rows - 1, j, rows, cols, visited, board);
        }

        // Check boundary columns
        for(int i = 0; i < rows; ++i)
        {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, rows, cols, visited, board);
            if(board[i][cols - 1] == 'O' && !visited[i][cols - 1])
                dfs(i, cols - 1, rows, cols, visited, board);
        }

        // Flip surrounded 'O' to 'X'
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

/*
//using BFS
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        if(board.size()==1 || board.empty())return;
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O' && (i==0 || j==0 || j==cols-1 || i==rows-1))
                {
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!q.empty())
        {
            auto[r,c]=q.front();
            q.pop();
            if(visited[r][c])continue;
            visited[r][c]=true;
            for(auto j: directions)
            {
                int nr = j[0]+r;
                int nc = j[1]+c;
                if(nr>=0 && nr<rows && nc>=0 && nc<cols)
                {
                    if(board[nr][nc]=='O' && !visited[nr][nc]) q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(!visited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
*/

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

int main() 
{
    Solution sol;

    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<char>> board2 = {
        {'O', 'O'},
        {'O', 'O'}
    };

    vector<vector<char>> board3 = {
        {'X'}
    };

    cout << "Before:\n";
    printBoard(board1);
    sol.solve(board1);
    cout << "After:\n";
    printBoard(board1);

    cout << "Before:\n";
    printBoard(board2);
    sol.solve(board2);
    cout << "After:\n";
    printBoard(board2);

    cout << "Before:\n";
    printBoard(board3);
    sol.solve(board3);
    cout << "After:\n";
    printBoard(board3);

    return 0;
}
