//Sum of nodes on the longest path
//using row count
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int sumOfLongRootToLeafPath(Node *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;

        int sum = 0;
        int row = 0;
        pathSum(root, 0, 0, sum, row);
        return sum;
    }

    void pathSum(Node *root, int tsum, int trow, int &sum, int &row) {
        if (!root) {
            if (trow - 1 > row) {
                row = trow - 1;
                sum = tsum;
            } else if (trow - 1 == row) {
                sum = max(sum, tsum);
            }
            return;
        }

        pathSum(root->left, tsum + root->data, trow + 1, sum, row);
        pathSum(root->right, tsum + root->data, trow + 1, sum, row);
    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1:
    //       1
    //      / \
    //     2   3
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    cout << "Test 1 Output: " << sol.sumOfLongRootToLeafPath(root1) << endl; // 1->3 = 4

    // Test case 2:
    //       10
    //      /  \
    //     5    12
    //    /
    //   4
    Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(12);
    root2->left->left = new Node(4);
    cout << "Test 2 Output: " << sol.sumOfLongRootToLeafPath(root2) << endl; // 10->5->4 = 19

    // Test case 3:
    //       5
    //      /
    //     4
    //    /
    //   3
    Node* root3 = new Node(5);
    root3->left = new Node(4);
    root3->left->left = new Node(3);
    cout << "Test 3 Output: " << sol.sumOfLongRootToLeafPath(root3) << endl; // 5->4->3 = 12

    return 0;
}
