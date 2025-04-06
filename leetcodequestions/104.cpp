//Maximum Depth of Binary Tree(Easy)
//BFS
//Time Complexity: O(n)
#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS-based solution to find maximum depth
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int count = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at current level
            count++;             // One level deeper

            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
        }

        return count;
    }
};

int main() {
    /*
         Tree structure:
             1
            / \
           2   3
          /     \
         4       5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    return 0;
}
