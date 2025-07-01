//Amount of Time for Binary Tree to Be Infected(Medium)
//using unordered_map for saving the parent nodes
//using unordered_set for saving the infected nodes
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};


//optimal code will find the target node once we find that we will find the depth of the tree and then we will use dfs to find the max depth of the tree
//than while returning back to parent node we will find the opposite subtree depth and add it to the current depth and update the ans
//in this way we will find the max time taken to infect the whole tree
class Solution {
public:
    int ans = 0;
    int subtree = 0;
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    int dfs(TreeNode* root, int start){
        if(root == NULL) return -1;
        if(root->val == start) {
            ans = max(ans,depth(root)-1);
            return 0;
        }
        int left = dfs(root->left, start);
        if (left != -1) {
            ans = max(ans, left + 1 + depth(root->right));
            return left + 1;
        }

        int right = dfs(root->right, start);
        if (right != -1) {
            ans = max(ans, right + 1 + depth(root->left));
            return right + 1;
        }

        return -1;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return ans;
    }
};

/*
// Original code using unordered_map and set time complexity and space complexity is high
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> mp;
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* temp = nullptr;
        traversal(root, nullptr, temp, start);
        set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(temp);
        visited.insert(temp);
        int burningtime = 0;

        while (!q.empty()) {
            int n = q.size();
            bool spread = false;
            for (int i = 0; i < n; i++) {
                TreeNode* ptr = q.front(); q.pop();

                if (ptr->left && !visited.count(ptr->left)) {
                    q.push(ptr->left);
                    visited.insert(ptr->left);
                    spread = true;
                }

                if (ptr->right && !visited.count(ptr->right)) {
                    q.push(ptr->right);
                    visited.insert(ptr->right);
                    spread = true;
                }

                if (mp[ptr] && !visited.count(mp[ptr])) {
                    q.push(mp[ptr]);
                    visited.insert(mp[ptr]);
                    spread = true;
                }
            }
            if (spread) burningtime++;
        }
        return burningtime;
    }

    void traversal(TreeNode* root, TreeNode* parent, TreeNode*& temp, int target) {
        if (!root) return;
        if (root->val == target) temp = root;
        mp[root] = parent;
        traversal(root->left, root, temp, target);
        traversal(root->right, root, temp, target);
    }
};*/

// ------------ Test Case Helpers ------------

TreeNode* buildTree1() {
    // Tree:
    //      1
    //     / \
    //    5   3
    //       / \
    //      10  6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    return root;
}

TreeNode* buildTree2() {
    // Tree:
    //     1
    //      \
    //       2
    //        \
    //         3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    return root;
}

TreeNode* buildTree3() {
    // Tree:
    //     1
    TreeNode* root = new TreeNode(1);
    return root;
}

// ------------ Main Function ------------

int main() {
    Solution sol;

    TreeNode* root1 = buildTree1();
    cout << "Test Case 1 (start = 3): " << sol.amountOfTime(root1, 3) << endl; // Expected: 2

    TreeNode* root2 = buildTree2();
    cout << "Test Case 2 (start = 2): " << sol.amountOfTime(root2, 2) << endl; // Expected: 1

    TreeNode* root3 = buildTree3();
    cout << "Test Case 3 (start = 1): " << sol.amountOfTime(root3, 1) << endl; // Expected: 0

    return 0;
}
