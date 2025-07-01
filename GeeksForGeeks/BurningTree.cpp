//Burning Tree
//using unorderedmap for the parent node saving
//using unordered_set for visited nodes
//time complexity is O(n) where n is the number of nodes in the tree
//space complexity is O(n) for the unordered_map and unordered_set
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    int minTime(Node* root, int target) {
        Node* targetNode = nullptr;
        traversal(root, nullptr, targetNode, target);

        set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);

        int burningtime = 0;
        while (!q.empty()) {
            int n = q.size();
            bool spread = false;

            for (int i = 0; i < n; ++i) {
                Node* ptr = q.front(); q.pop();

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

    void traversal(Node* root, Node* parent, Node*& temp, int target) {
        if (!root) return;
        if (root->data == target) temp = root;
        mp[root] = parent;

        traversal(root->left, root, temp, target);
        traversal(root->right, root, temp, target);
    }
};

// ---------- Helper Function to Build Tree for Testing ----------
Node* buildTree1() {
    // Tree:
    //        1
    //      /   \
    //     2     3
    //          / \
    //         4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    return root;
}

Node* buildTree2() {
    // Tree:
    //       10
    //      /
    //     20
    //    /
    //   30
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    return root;
}

Node* buildTree3() {
    // Tree:
    //     1
    Node* root = new Node(1);
    return root;
}

// ---------- Main Function ----------
int main() {
    Solution sol;

    Node* root1 = buildTree1();
    cout << "Test Case 1 (target = 3): " << sol.minTime(root1, 3) << endl; // Expected: 2

    Node* root2 = buildTree2();
    cout << "Test Case 2 (target = 20): " << sol.minTime(root2, 20) << endl; // Expected: 2

    Node* root3 = buildTree3();
    cout << "Test Case 3 (target = 1): " << sol.minTime(root3, 1) << endl; // Expected: 0

    return 0;
}

