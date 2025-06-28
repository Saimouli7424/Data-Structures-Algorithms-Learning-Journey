//Top View of Binary Tree
//using same approach as vertical traversal but only saving each weighted only single time
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        if (!root) return {};
        if (!root->left && !root->right) return {root->data};

        map<int, int> mp; // HD -> node data
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* temp = q.front().first;
                int val = q.front().second;
                q.pop();

                if (!mp.count(val)) {
                    mp[val] = temp->data;
                }

                if (temp->left) q.push({temp->left, val - 1});
                if (temp->right) q.push({temp->right, val + 1});
            }
        }

        vector<int> result;
        for (auto& i : mp) {
            result.emplace_back(i.second);
        }
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test case 1:
    //     1
    //    / \
    //   2   3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    cout << "Top View 1: ";
    printVector(sol.topView(root1)); // Output: 2 1 3

    // Test case 2:
    //        1
    //       / \
    //      2   3
    //       \   \
    //        4   5
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(4);
    root2->right->right = new Node(5);
    cout << "Top View 2: ";
    printVector(sol.topView(root2)); // Output: 2 1 3 5

    // Test case 3:
    //         1
    //        /
    //       2
    //      /
    //     3
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->left->left = new Node(3);
    cout << "Top View 3: ";
    printVector(sol.topView(root3)); // Output: 3 2 1

    return 0;
}

