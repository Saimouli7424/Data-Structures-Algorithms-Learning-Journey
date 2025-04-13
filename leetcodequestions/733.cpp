//Flood Fill(Easy)
//Using Breadth First Search
//Time Complexity: O(N)
//Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int rows = image.size();
        int cols = image[0].size();
        int actualvalue = image[sr][sc];
        if (actualvalue == color) return image; // Optimization

        vector<vector<int>> result = image;
        queue<pair<int, int>> q;
        vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};
        q.push({sr, sc});
        result[sr][sc] = color; // Mark start as visited

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto it : directions)
            {
                int nr = r + it[0];
                int nc = c + it[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && result[nr][nc] == actualvalue)
                {
                    result[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return result;
    }
};

// Helper function to print 2D vector
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> image1 = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr1 = 1, sc1 = 1, color1 = 2;
    auto result1 = sol.floodFill(image1, sr1, sc1, color1);
    printImage(result1);

    vector<vector<int>> image2 = {
        {0,0,0},
        {0,1,1}
    };
    int sr2 = 1, sc2 = 1, color2 = 1;
    auto result2 = sol.floodFill(image2, sr2, sc2, color2);
    printImage(result2);

    vector<vector<int>> image3 = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr3 = 0, sc3 = 0, color3 = 3;
    auto result3 = sol.floodFill(image3, sr3, sc3, color3);
    printImage(result3);

    return 0;
}
