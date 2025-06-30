//Left View of Binary Tree
//time complexity: O(n)
//space complexity: O(n)

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    map<int, int> mp;

    vector<int> leftView(Node *root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->data};

        mp.clear(); // clear map before use
        vector<int> result;
        leftViewUtil(root, 0);

        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }

    void leftViewUtil(Node *root, int row) {
        if (!root) return;
        if (!mp.count(row)) mp[row] = root->data;
        leftViewUtil(root->left, row + 1);
        leftViewUtil(root->right, row + 1);
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test Case 1:
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->right = new Node(5);
    cout << "Left View 1: ";
    printVector(sol.leftView(root1)); // Output: 1 2 4

    // Test Case 2:
    //       10
    //         \
    //          20
    //         /
    //        30
    Node* root2 = new Node(10);
    root2->right = new Node(20);
    root2->right->left = new Node(30);
    cout << "Left View 2: ";
    printVector(sol.leftView(root2)); // Output: 10 20 30

    // Test Case 3:
    //       5
    //      /
    //     1
    //      \
    //       2
    Node* root3 = new Node(5);
    root3->left = new Node(1);
    root3->left->right = new Node(2);
    cout << "Left View 3: ";
    printVector(sol.leftView(root3)); // Output: 5 1 2

    return 0;
}
