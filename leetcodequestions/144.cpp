//Binary Tree Preorder Traversal(Easy)
//Given the root of a binary tree, return the preorder traversal of its nodes' values.
//Input: root = [1,null,2,3]
//Output: [1,2,3]


#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        result.emplace_back(root->val); // Store root value
        vector<int> left = preorderTraversal(root->left);  // Recursive call for left subtree
        vector<int> right = preorderTraversal(root->right); // Recursive call for right subtree

        result.insert(result.end(), left.begin(), left.end()); // Append left subtree values
        result.insert(result.end(), right.begin(), right.end()); // Append right subtree values

        return result;
    }
};

// Function to test the preorder traversal
void testPreorder() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    testPreorder();
    return 0;
}
