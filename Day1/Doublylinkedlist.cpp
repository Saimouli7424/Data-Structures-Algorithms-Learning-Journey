#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    if(head==nullptr)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &tail,int val){
    Node* newNode = new Node(val);
    if(tail==nullptr){
        tail = newNode;
        return;
    }

    Node* temp = tail;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void insertAtAfter(Node* &head, int newval,int afterval)
{
    Node* newNode = new Node(newval);
    if(head->data==afterval)
    {
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        return;
    }
    Node* temp = head;
    while(temp!=nullptr && temp->data!=afterval)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(Node* &tail,int val){
    if(tail->data==val)
    {
        Node* toDelete = tail;
        tail = tail->next;
        tail->prev = nullptr;
        delete toDelete;
    }

    Node* temp = tail;
    while(temp!=nullptr && temp->data!=val)
    {
        temp = temp->next;
    }
    if(temp->next==nullptr && temp->data==val)
    {
        Node* toDelete = temp;
        temp->prev->next = nullptr;
        delete toDelete;
        return;
    }
    else
    {
        Node* toDelete = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete toDelete;
    }
}

void display(Node* temp)
{
    cout<<"NULL";
    while(temp!=nullptr)
    {
        cout<<" <-"<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    cout<<"DOUBLY LINKED LIST:- "<<endl;
    Node* head = nullptr;
    cout<<"Insertion at Head: "<<endl;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    display(head);
    insertAtHead(head, 40);
    insertAtHead(head, 60);
    display(head);
    

    cout<<"\nInsertion at tail: "<<endl;
    Node* tail = nullptr;
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    insertAtTail(tail, 30);
    display(tail);
    insertAtTail(tail, 40);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    display(tail);

    cout<<"\nInsertion at after Specific Position for head: "<<endl;
    insertAtAfter(head,50,40);
    display(head);
    cout<<"\nInsertion at after Specific Position for tail: "<<endl;
    insertAtAfter(tail,50,40);
    display(tail);

    cout<<"\nDeletion of value in tail: "<<endl;
    deleteNode(tail,25);
    deleteNode(tail,70);
    display(tail);
    return 0;
}
