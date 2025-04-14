//Binary Tree Level Order Traversal(Medium)
//Using BFS
//Time Complexity: O(n)
//Space Complexity: O(n)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;

        while(!q.empty()) {
            int size = q.size();
            vector<int> inter;
            for(int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                inter.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            result.push_back(inter);
        }
        return result;
    }
};

// Helper function to print the level order result
void printLevelOrder(const vector<vector<int>>& result) {
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Test case 1: Balanced tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    cout << "Test Case 1:\n";
    printLevelOrder(sol.levelOrder(root1));
    cout << "------------------\n";

    // Test case 2: Left-skewed tree
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(9);
    root2->left->left = new TreeNode(8);
    root2->left->left->left = new TreeNode(7);

    cout << "Test Case 2:\n";
    printLevelOrder(sol.levelOrder(root2));
    cout << "------------------\n";

    // Test case 3: Single node
    TreeNode* root3 = new TreeNode(42);
    
    cout << "Test Case 3:\n";
    printLevelOrder(sol.levelOrder(root3));
    cout << "------------------\n";

    return 0;
}
