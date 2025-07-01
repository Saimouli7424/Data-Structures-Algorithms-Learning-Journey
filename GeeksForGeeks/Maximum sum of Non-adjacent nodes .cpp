//Maximum sum of Non adjacent nodes
//using pick and not pick approach
//time complexity: O(n)
//space complexity: O(n) which n is stack
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    // the pairs consists of {include, exclude}
    pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Include current node: skip children (use left.second and right.second)
        int include = root->data + left.second + right.second;

        // Exclude current node: take best of including or excluding children
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};

// ----------- Helper Functions to Build Test Trees -----------

Node* buildTree1() {
    // Tree:
    //       10
    //      /  \
    //     1    2
    //    / \    \
    //   3   4    5
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    return root;
}

Node* buildTree2() {
    // Tree:
    //      1
    //     / \
    //    2   3
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return root;
}

Node* buildTree3() {
    // Tree:
    //       5
    //      /
    //     1
    //    /
    //   2
    Node* root = new Node(5);
    root->left = new Node(1);
    root->left->left = new Node(2);
    return root;
}

// ----------- Main Function to Run Test Cases -----------
int main() {
    Solution sol;

    Node* root1 = buildTree1();
    cout << "Test Case 1 Answer: " << sol.getMaxSum(root1) << endl; // Expected: 22

    Node* root2 = buildTree2();
    cout << "Test Case 2 Answer: " << sol.getMaxSum(root2) << endl; // Expected: 5

    Node* root3 = buildTree3();
    cout << "Test Case 3 Answer: " << sol.getMaxSum(root3) << endl; // Expected: 7

    return 0;
}
