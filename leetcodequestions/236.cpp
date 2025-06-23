// Lowest Common Ancestor of a Binary Tree(Medium)
//using dfs an backtracking time complexity is O(n) and space complexity is O(n) where h is the height of the tree
//optimal approach is LCA

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//optimal approach using LCA
//time complexity is O(n) and space complexity is O(N) which is stack
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr || root==p || root==q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);//it will return the first node which is either p or q or null which comes first
        TreeNode* right = lowestCommonAncestor(root->right,p,q);//it will return the first node which is either p or q or null which comes first

        if(left==NULL)return right;
        if(right==NULL)return left;
        else return root;//if both left and right are not null, then root is the LCA
    }
};

/*
//my naive approach
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root == nullptr) return false;

        path.push_back(root);

        if (root == p)
            return true;

        if (dfs(root->left, p, path) || dfs(root->right, p, path))
            return true;

        path.pop_back(); // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        dfs(root, p, path1);
        dfs(root, q, path2);

        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
            i++;

        return path1[i - 1];
    }
};
*/

// Utility to build nodes manually for testing
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root = buildTestTree();

    // Test Case 1
    TreeNode* p1 = root->left;        // Node 5
    TreeNode* q1 = root->right;       // Node 1
    TreeNode* lca1 = sol.lowestCommonAncestor(root, p1, q1);
    cout << "LCA of 5 and 1: " << lca1->val << endl; // Output: 3

    // Test Case 2
    TreeNode* p2 = root->left->left;  // Node 6
    TreeNode* q2 = root->left->right->right; // Node 4
    TreeNode* lca2 = sol.lowestCommonAncestor(root, p2, q2);
    cout << "LCA of 6 and 4: " << lca2->val << endl; // Output: 5

    // Test Case 3
    TreeNode* p3 = root->left->right->left; // Node 7
    TreeNode* q3 = root->left->right->right; // Node 4
    TreeNode* lca3 = sol.lowestCommonAncestor(root, p3, q3);
    cout << "LCA of 7 and 4: " << lca3->val << endl; // Output: 2

    return 0;
}
