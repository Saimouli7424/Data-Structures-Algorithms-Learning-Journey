//Tree Boundary Traversal
//using basic traversal
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  private:
    bool isLeafNode(Node* root){
        return !root->left && !root->right;
    }

    void leftTraversal(Node* root, vector<int>& result){
        Node* curr = root->left;
        while(curr) {
            if (!isLeafNode(curr)) result.emplace_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
            //why the else is required best example is the given first testcase
        }
    }

    void addLeafNode(Node* root, vector<int>& result){
        if (!root) return;
        if (isLeafNode(root)) {
            result.emplace_back(root->data);
            return;
        }
        addLeafNode(root->left, result);
        addLeafNode(root->right, result);
    }

    void rightTraversal(Node* root, vector<int>& result){
        Node* curr = root->right;
        vector<int> temp;
        while(curr) {
            if (!isLeafNode(curr)) temp.emplace_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
            //why the else is required best example is the given first testcase
        }
        reverse(temp.begin(), temp.end());
        result.insert(result.end(), temp.begin(), temp.end());
    }

  public:
    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};
        vector<int> result;
        if (!isLeafNode(root)) result.emplace_back(root->data);
        leftTraversal(root, result);
        addLeafNode(root, result);
        rightTraversal(root, result);
        return result;
    }
};

// Helper function to build tree from input string
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return nullptr;

    stringstream ss(str);
    string word;
    vector<string> tokens;

    while (ss >> word) tokens.push_back(word);

    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* curr = q.front();
        q.pop();

        if (tokens[i] != "N") {
            curr->left = new Node(stoi(tokens[i]));
            q.push(curr->left);
        }
        i++;

        if (i >= tokens.size()) break;

        if (tokens[i] != "N") {
            curr->right = new Node(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Main function
int main() {
    Solution sol;

    // Test Case 1
    string input1 = "1 2 3 N N 4 N 5 N N N";
    Node* root1 = buildTree(input1);
    vector<int> result1 = sol.boundaryTraversal(root1);
    cout << "Test Case 1 Output: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    // Test Case 2
    string input2 = "1 2 3 4 5 6 7";
    Node* root2 = buildTree(input2);
    vector<int> result2 = sol.boundaryTraversal(root2);
    cout << "Test Case 2 Output: ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    return 0;
}
