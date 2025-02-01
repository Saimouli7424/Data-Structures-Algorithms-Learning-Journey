#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
        next = nullptr;
    }
};

void insertAtHead(Node* &head,int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insertAtTail(Node* &head, int val)
{
    Node* newnode = new Node(val);
    if(head==nullptr)
    {
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next = newnode;
}

void insertAtAfter(Node* &head,int newval,int prevval){
    Node* newnode = new Node(newval);
    Node* prev = nullptr;
    Node* temp = head;
    while(temp->next!=NULL && temp->data!=prevval)
    {
            temp=temp->next;
    }
    prev = temp->next;
    temp->next = newnode;
    newnode->next = prev;
}

void deleteNode(Node* &head,int val){

    if(head==nullptr || head->next==nullptr)
    {
        return;
    }

    if(head->data==val)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr && temp->next->data!=val)
    {
        temp=temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 7);
    printList(head);

    insertAtTail(tail, 9);
    insertAtTail(tail, 11);
    insertAtTail(tail, 13);
    printList(tail);


    insertAtAfter(tail,12,11);
    insertAtAfter(tail,10,9);
    insertAtAfter(tail,14,12);
    cout<<"\nAfter insertion of new value at after specific position: "<<endl;
    printList(tail);


    deleteNode(tail,14);
    cout<<"\nAfter deletion of value at after specific position: "<<endl;
    printList(tail);
    return 0;
}