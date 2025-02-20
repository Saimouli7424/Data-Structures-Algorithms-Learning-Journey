//using Greedy Approach
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(NULL), right(NULL) {}
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->ch != '#')
        cout << root->ch << " -> " << code << endl;
    
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}


void huffmanCoding(vector<pair<char, int>> chars) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto c : chars)
        pq.push(new Node(c.first, c.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    vector<pair<char, int>> chars = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    
    huffmanCoding(chars);
    
    return 0;
}
