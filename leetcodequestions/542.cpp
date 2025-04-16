//01 Matrix (Medium)
//USING BFS
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    //the below approach push 0 values row,col in queue
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        queue<pair<int,int>>q;
        int rowsize = mat.size();
        int colsize = mat[0].size();
        vector<vector<int>> result(rowsize, vector<int>(colsize, -1));
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        for(int i = 0; i < rowsize; i++)
        {
            for(int j = 0; j < colsize; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for(auto d : directions)
            {
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nr < rowsize && nc >= 0 && nc < colsize && result[nr][nc] == -1)
                {
                    result[nr][nc] = result[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return result;
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (auto row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> mat2 = {
        {0, 1, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    vector<vector<int>> mat3 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Test Case 1:\n";
    printMatrix(sol.updateMatrix(mat1));

    cout << "Test Case 2:\n";
    printMatrix(sol.updateMatrix(mat2));

    cout << "Test Case 3:\n";
    printMatrix(sol.updateMatrix(mat3));

    return 0;
}


/*
//the below code got TLE which we push into q only values of 1 row,col
int rowsize=mat.size();
        int colsize=mat[0].size();
        vector<vector<int>> result(rowsize,vector<int>(colsize,0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    result[i][j]=bfs(mat,i,j,rowsize,colsize);
                }
            }
        }
        return result;
    }

    int bfs(vector<vector<int>>&mat,int row,int col,int rowsize,int colsize)
    {
        queue<pair<int,int>>pq;
        pq.push({row,col});
        vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> visited(rowsize, vector<bool>(colsize, false));
        visited[row][col]=true;
        int count=0;
        while(!pq.empty())
        {
            int pqsize=pq.size();
            count++;
            for(int i=0;i<pqsize;i++)
            {
                auto[r,c]=pq.front();
                pq.pop();
                for(auto j:directions)
                {
                    int nr=r+j[0], nc=c+j[1];
                    if(nr>=0 && nr<rowsize && nc>=0 && nc<colsize && !visited[nr][nc])
                    {
                        visited[nr][nc]=true;
                        if(mat[nr][nc]==0)return count;
                        else pq.push({nr,nc});
                    }
                }
            }
        }
        return count;  it's TLE
*/