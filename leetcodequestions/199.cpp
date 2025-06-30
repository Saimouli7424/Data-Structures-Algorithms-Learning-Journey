//Binary Tree Right Side View(Medium)
//using unordered_map
//time complexity: O(n)
//space complexity: O(n)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Tree Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    map<int, int> mp;

    vector<int> leftView(Node* root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->data};

        mp.clear(); // Clear map before every run
        vector<int> result;
        dfs(root, 0);

        for (auto& i : mp) {
            result.push_back(i.second);
        }

        return result;
    }

    void dfs(Node* root, int row) {
        if (!root) return;

        if (!mp.count(row))
            mp[row] = root->data;

        dfs(root->left, row + 1);
        dfs(root->right, row + 1);
    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int val : v)
        cout << val << " ";
    cout << endl;
}

// Main function with test cases
int main() {
    Solution sol;

    // Test Case 1:
    //      1
    //     / \
    //    2   3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    cout << "Left View 1: ";
    printVector(sol.leftView(root1)); // Output: 1 2

    // Test Case 2:
    //      1
    //     /
    //    2
    //     \
    //      4
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->right = new Node(4);
    cout << "Left View 2: ";
    printVector(sol.leftView(root2)); // Output: 1 2 4

    // Test Case 3:
    //      10
    //     /  \
    //    20   30
    //   /    /  \
    //  40   50   60
    Node* root3 = new Node(10);
    root3->left = new Node(20);
    root3->right = new Node(30);
    root3->left->left = new Node(40);
    root3->right->left = new Node(50);
    root3->right->right = new Node(60);
    cout << "Left View 3: ";
    printVector(sol.leftView(root3)); // Output: 10 20 40

    return 0;
}
