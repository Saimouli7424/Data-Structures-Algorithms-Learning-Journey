//Lowest Common Ancestor of a Binary Search Tree(Medium)
//using LOWEST COMMON ANCESTOR OF A BINARY SEARCH TREE
//time complexity: O(h), where h is the height of the tree
//space complexity: O(1)
#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;

        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

// Helper function to insert nodes into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Helper function to find a node by value
TreeNode* find(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return find(root->left, val);
    return find(root->right, val);
}

int main() {
    Solution sol;

    // Create BST:       6
    //                 /   \
    //                2     8
    //               / \   / \
    //              0   4 7   9
    //                 / \
    //                3   5
    TreeNode* root = nullptr;
    int nodes[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int val : nodes) root = insert(root, val);

    // Test Case 1: LCA of 2 and 8 → should return 6
    TreeNode* p1 = find(root, 2);
    TreeNode* q1 = find(root, 8);
    TreeNode* ans1 = sol.lowestCommonAncestor(root, p1, q1);
    cout << "LCA of 2 and 8 is: " << ans1->val << endl;

    // Test Case 2: LCA of 2 and 4 → should return 2
    TreeNode* p2 = find(root, 2);
    TreeNode* q2 = find(root, 4);
    TreeNode* ans2 = sol.lowestCommonAncestor(root, p2, q2);
    cout << "LCA of 2 and 4 is: " << ans2->val << endl;

    // Test Case 3: LCA of 3 and 5 → should return 4
    TreeNode* p3 = find(root, 3);
    TreeNode* q3 = find(root, 5);
    TreeNode* ans3 = sol.lowestCommonAncestor(root, p3, q3);
    cout << "LCA of 3 and 5 is: " << ans3->val << endl;

    return 0;
}
