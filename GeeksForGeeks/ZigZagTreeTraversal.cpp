//ZigZag Tree Traversal(Medium)
//using BFS with flag
//time complexity: O(N)
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

// Binary Tree Node definition
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Zigzag traversal solution
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        bool reversal = false;

        while (!q.empty()) {
            deque<int> values;
            int n = q.size();

            for (int i = 0; i < n; ++i) {
                Node* temp = q.front();
                q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                if (reversal) {
                    values.push_front(temp->data);
                } else {
                    values.push_back(temp->data);
                }
            }

            result.insert(result.end(), values.begin(), values.end());
            reversal = !reversal;
        }

        return result;
    }
};

// Helper function to print the result
void printZigzag(const vector<int>& res) {
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the code
int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           /     \
          4       5

        Expected Zigzag Output: 1 3 2 4 5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    printZigzag(result);

    // Free memory
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

