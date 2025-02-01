#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* right, *left;
    Node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

Node* Insertion(Node* root, int val)
{
    if(root == nullptr)
    {
        Node* newNode = new Node(val);
        return newNode;
    }

    if(val<root->data)
    {
        root->left = Insertion(root->left, val);
    }

    if(val>root->data)
    {
        root->right = Insertion(root->right, val);
    }

    return root;
}



void Inorder(Node* root)
{
    if(root == nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root){
    if(root == nullptr)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = nullptr;
    root=Insertion(root, 50);
    Insertion(root, 30);
    Insertion(root, 20);
    Insertion(root, 40);
    Insertion(root, 70);
    Insertion(root, 60);
    Insertion(root, 80);
    Insertion(root, 10);
    Insertion(root, 25);
    cout<<"InOrder: ";
    Inorder(root);
    cout<<"\nPreOrder: ";
    Preorder(root);
    cout<<"\nPostOrder: ";
    Postorder(root);
    return 0;
}