//Vertical Order Traversal of a Binary Tree(Hard)
//using DFS can use BFS as well
//time complexity: O(N log N)
//space complexity: O(N)
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

// Tree Node Definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    map<int, vector<pair<int, int>>> mp;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        traversal(root, 0, 0);

        vector<vector<int>> result;
        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            for (auto& i : it.second) {
                temp.push_back(i.second);
            }
            result.push_back(temp);
        }
        return result;
    }

    void traversal(TreeNode* root, int col, int row) {
        if (!root) return;
        mp[col].emplace_back(row, root->val);
        traversal(root->left, col - 1, row + 1);
        traversal(root->right, col + 1, row + 1);
    }
};

// Helper to build tree from level-order input string
TreeNode* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return nullptr;

    vector<string> nodes;
    stringstream ss(str);
    string token;
    while (ss >> token) {
        nodes.push_back(token);
    }

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "N") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "N") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to print 2D vector result
void printResult(const vector<vector<int>>& result) {
    for (const auto& col : result) {
        for (int val : col) cout << val << " ";
        cout << endl;
    }
}

// Main
int main() {
    Solution sol;

    // Test Case 1
    string input1 = "3 9 20 N N 15 7";
    TreeNode* root1 = buildTree(input1);
    cout << "Test Case 1 Output:\n";
    printResult(sol.verticalTraversal(root1));
    cout << endl;

    // Test Case 2
    string input2 = "1 2 3 4 5 6 7";
    TreeNode* root2 = buildTree(input2);
    cout << "Test Case 2 Output:\n";
    printResult(sol.verticalTraversal(root2));
    cout << endl;

    // Test Case 3
    string input3 = "1 2 3 N N 4 5";
    TreeNode* root3 = buildTree(input3);
    cout << "Test Case 3 Output:\n";
    printResult(sol.verticalTraversal(root3));
    cout << endl;

    return 0;
}

