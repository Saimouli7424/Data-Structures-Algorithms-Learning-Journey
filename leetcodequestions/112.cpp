//Path Sum(Medium)
//using DFS
//Time Complexity: O(n)

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    //my code
    bool found = false;
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode* root, int target, int sum) {
        if (root == nullptr) return false;
        sum += root->val;

        if (!root->left && !root->right && sum == target) {
            found = true;
            return true;
        }

        dfs(root->left, target, sum);
        if (found) return true;
        dfs(root->right, target, sum);
        if (found) return true;

        return false;
    }
    /*
    //clean code
    bool dfs(TreeNode* root, int target, int sum) {
        if (root == nullptr) return false;

        sum += root->val;

        // If it's a leaf node and the sum equals target
        if (!root->left && !root->right && sum == target) {
            return true;
        }

        // Short-circuit: return true if either side is true
        return dfs(root->left, target, sum) || dfs(root->right, target, sum);
    }
    */
};

// ---------- Test Cases ----------

int main() {
    Solution sol;

    // Test Case 1:
    // Tree:      5
    //           / \
    //          4   8
    //         /   / \
    //        11  13  4
    //       /  \      \
    //      7    2      1
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);

    cout << "Test Case 1: " << sol.hasPathSum(root1, 22) << " (Expected: 1)" << endl;

    // Test Case 2:
    // Tree: 1
    //       \
    //        2
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);

    sol.found = false; // reset for new test
    cout << "Test Case 2: " << sol.hasPathSum(root2, 1) << " (Expected: 0)" << endl;

    // Test Case 3:
    TreeNode* root3 = nullptr;

    sol.found = false;
    cout << "Test Case 3: " << sol.hasPathSum(root3, 0) << " (Expected: 0)" << endl;

    return 0;
}
