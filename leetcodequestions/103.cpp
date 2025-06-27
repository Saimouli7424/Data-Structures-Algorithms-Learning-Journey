//Binary Tree Zigzag Level Order Traversal(Medium)
//using BFS and dequeue
//time complexity: O(n), where n is the number of nodes in the binary tree
//space complexity: O(n), where n is the number of nodes in the binary tree

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            deque<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.emplace_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight;
        }

        return result;
    }
};

int main() {
    // Build tree: [1,2,3,4,null,null,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> res = sol.zigzagLevelOrder(root);

    for (const auto& level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Free memory
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
