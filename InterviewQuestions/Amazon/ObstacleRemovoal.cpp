/*
📌 Amazon Demolition Robot - Remove the Obstacle
You are in charge of preparing a recently purchased lot for one of Amazon's new buildings. The lot is covered with trenches and has a single obstacle that needs to be taken down before construction can begin.

A demolition robot is placed at the top-left corner (0,0) of the lot and can move up, down, left, or right. The robot cannot enter trenches (0) and must find the shortest path to reach the obstacle (9).

Your task is to determine the minimum distance the robot must travel to remove the obstacle. If the obstacle cannot be reached, return -1.

🔹 Function Signature
cpp
Copy
Edit
int minimumDistance(vector<vector<int>> lot);
🔹 Input Format
A 2D grid lot of size R x C, where:

1 represents a flat area (the robot can move here).

0 represents a trench (the robot cannot enter this area).

9 represents the obstacle (the target location).

The robot always starts at (0,0), which is guaranteed to be 1.

🔹 Output Format
Return an integer representing the minimum distance required for the demolition robot to reach the obstacle.

If it is impossible to reach the obstacle, return -1.

🔹 Constraints
1 ≤ R, C ≤ 10^3 (Grid can be large, so BFS is preferred over DFS).

There is exactly one 9 in the grid.

The robot can only move up, down, left, or right.

🔹 Example 1
Input:
cpp
Copy
Edit
vector<vector<int>> lot = {
    {1, 0, 0},
    {1, 0, 0},
    {1, 9, 1}
};
Output:
Copy
Edit
3
Explanation:
The shortest path is:

scss
Copy
Edit
(0,0) → (1,0) → (2,0) → (2,1)
Total distance = 3.

🔹 Example 2
Input:
cpp
Copy
Edit
vector<vector<int>> lot = {
    {1, 1, 0},
    {1, 1, 1},
    {1, 9, 0}
};
Output:
Copy
Edit
3
Explanation:
The shortest path is:

scss
Copy
Edit
(0,0) → (1,0) → (2,0) → (2,1)
Total distance = 3.

🔹 Example 3
Input:
cpp
Copy
Edit
vector<vector<int>> lot = {
    {1, 0, 0},
    {0, 0, 0},
    {9, 1, 1}
};
Output:
diff
Copy
Edit
-1
Explanation:
The robot cannot reach 9 due to trenches (0).

So, return -1.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distanceTraversed(vector<vector<int>>& lot) {
    int rows = lot.size();
    int cols = lot[0].size();
    
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    //the directions can be anyorder
    queue<pair<int, int>> q;
    q.push({0, 0});
    int steps = 0;

    if (lot[0][0] == 9) return 0;  // If the obstacle is at (0,0), no movement needed

    lot[0][0] = 0; // Mark as visited

    while (!q.empty()) 
    {
        int size = q.size();
        // cout<<"size: "<<q.size()<<endl;
        steps++;

        for (int i = 0; i < size; i++) 
        {
            pair<int, int> cell = q.front();
            q.pop();
            int r = cell.first, c = cell.second;

            for (auto& d : directions) 
            {
                int nr = r + d[0], nc = c + d[1];
                //nr=newrow nc=newcolumn
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && lot[nr][nc] != 0) {
                    // cout<<nr<<" "<<nc<<endl;
                    if (lot[nr][nc] == 9) return steps;  // Found the obstacle
                    q.push({nr, nc});
                    lot[nr][nc] = 0; // Mark as visited
                }
            }
        }
    
    }

    return -1;  // If we never found the obstacle
}

int main() {
    vector<vector<int>> lot = {{1, 1, 1}, {1, 1, 9}, {1, 1, 1}};
    cout << distanceTraversed(lot) << endl; // Output: 3
    return 0;
}

// 🔹 Solution Approach
// ✅ Use Breadth-First Search (BFS)

// BFS is ideal for finding the shortest path in an unweighted grid.

// Use a queue to explore possible moves in all 4 directions.

// Track visited positions to avoid cycles.