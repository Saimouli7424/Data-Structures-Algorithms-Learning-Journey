//Path Sum II(Medium)
//using DFS
//time complexity: O(n), where n is the number of nodes in the tree
//space complexity: O(h), where h is the height of the tree
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root, temp, 0, targetSum);
        return result;
    }

    void dfs(TreeNode* root, vector<int> &temp, int sum, int targetSum) {
        if (!root) return;

        temp.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == targetSum) {
            result.emplace_back(temp);
        }

        dfs(root->left, temp, sum, targetSum);
        dfs(root->right, temp, sum, targetSum);

        temp.pop_back(); // backtrack
    }
};

// Helper to print result
void printResult(const vector<vector<int>>& res) {
    for (const auto& path : res) {
        cout << "[ ";
        for (int val : path)
            cout << val << " ";
        cout << "]" << endl;
    }
}

// Test Case Builder
TreeNode* buildTestTree1() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

TreeNode* buildTestTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

TreeNode* buildTestTree3() {
    TreeNode* root = new TreeNode(-2);
    root->right = new TreeNode(-3);
    return root;
}

int main() {
    Solution sol;

    cout << "Test Case 1 (targetSum = 22):\n";
    TreeNode* root1 = buildTestTree1();
    auto res1 = sol.pathSum(root1, 22);
    printResult(res1);

    cout << "\nTest Case 2 (targetSum = 5):\n";
    TreeNode* root2 = buildTestTree2();
    auto res2 = sol.pathSum(root2, 5);
    printResult(res2);

    cout << "\nTest Case 3 (targetSum = -5):\n";
    TreeNode* root3 = buildTestTree3();
    auto res3 = sol.pathSum(root3, -5);
    printResult(res3);

    return 0;
}
