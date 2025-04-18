//Word Search(Medium)
//using dfs
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //optimal
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int p) {
        if (p == word.size()) return true;

        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[p])
            return false;

        char temp = board[i][j];
        board[i][j] = '*'; // mark as visited

        bool found = dfs(board, i + 1, j, word, p + 1) ||
                     dfs(board, i - 1, j, word, p + 1) ||
                     dfs(board, i, j + 1, word, p + 1) ||
                     dfs(board, i, j - 1, word, p + 1);

        board[i][j] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    //my code
    /*
    class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) 
        {
            int rows=board.size();
            int cols=board[0].size();
            vector<vector<bool>>visited(rows,vector<bool>(cols,false));
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if(board[i][j]==word[0])
                    {
                        if(dfs(i,j,board,word,0,visited))return true;
                    }
                }
            }
            return false;
        }

        bool dfs(int i,int j,vector<vector<char>>&board,string word,int idx,vector<vector<bool>>& visited)
        {
            int rows=board.size();
            int cols=board[0].size();
            
            if(idx>=word.size()-1)
            {
                return true;
            }

            visited[i][j]=true;
            vector<pair<int,int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto k:directions)
            {
                int nr=i+k.first, nc=j+k.second;
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && board[nr][nc]==word[idx+1] &&!visited[nr][nc])
                {
                    if(dfs(nr,nc,board,word,idx+1,visited))return true;
                }
            }
            visited[i][j]=false;
            return false;
        }
    };
    */
};

// Example main function
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    string word = "ABCCED";

    if (sol.exist(board, word)) {
        cout << "Word exists in the board!" << endl;
    } else {
        cout << "Word does NOT exist in the board." << endl;
    }

    return 0;
}
