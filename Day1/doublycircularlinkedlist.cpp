#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() {
        head = NULL;
    }

    // Insert at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = newNode->prev = newNode;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Deletion of a node
    void deleteNode(int key) {
        if (head == NULL) return;
        
        Node* temp = head;
        Node* prevNode = NULL;
        while (temp->data != key) {
            if (temp->next == head) return;
            prevNode = temp;
            temp = temp->next;
        }
        
        if (temp->next == head && temp->prev == head) {
            head = NULL;
            delete temp;
            return;
        }
        
        if (temp == head) {
            head = temp->next;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    //To Display the doubly circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList dcll;

    dcll.insert(10);
    dcll.insert(20);
    dcll.insert(30);
    dcll.insert(40);
    
    cout << "Doubly Circular Linked List: ";
    dcll.display();

    dcll.deleteNode(20);
    cout << "After deleting 20: ";
    dcll.display();

    return 0;
}
