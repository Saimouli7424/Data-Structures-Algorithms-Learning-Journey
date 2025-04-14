//Flatten Binary Tree to Linked List
//using linkedlist and preorder traversal
// Time complexity: O(n)
// Space complexity: O(h) where h is the height of the tree

#include <iostream>
#include <vector>
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
    vector<int> v;

    void display(TreeNode* temp) {
        if (temp == nullptr) return;
        v.push_back(temp->val); // Store the current node's value
        display(temp->left);     // Traverse left subtree
        display(temp->right);    // Traverse right subtree
    }

    void flatten(TreeNode* root) {
        if (!root) return;  // If root is null, do nothing
        
        // Get the preorder traversal of the tree
        display(root);

        TreeNode* temp = root;
        // Start linking nodes from the second element in the vector
        for (int i = 1; i < v.size(); i++) {
            temp->left = nullptr;  // Set the left pointer to null
            temp->right = new TreeNode(v[i]);  // Create new node for right child
            temp = temp->right;    // Move the pointer to the next node
        }
    }
};

// Helper function to print the flattened tree (linked list)
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Main function with test cases
int main() {
    Solution solution;

    // Test Case 1: Simple binary tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);
    
    solution.flatten(root1);
    cout << "Flattened tree for Test Case 1: ";
    printFlattenedTree(root1);  // Expected output: 1 2 3 4 5 6

    // Test Case 2: Only one node
    TreeNode* root2 = new TreeNode(1);
    
    solution.flatten(root2);
    cout << "Flattened tree for Test Case 2: ";
    printFlattenedTree(root2);  // Expected output: 1

    // Test Case 3: Empty tree
    TreeNode* root3 = nullptr;
    
    solution.flatten(root3);
    cout << "Flattened tree for Test Case 3: ";
    printFlattenedTree(root3);  // Expected output: (nothing, empty)

    return 0;
}
