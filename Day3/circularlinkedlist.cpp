#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // Insert at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;  // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete a node
    void deleteNode(int key) {
        if (head == NULL) return;

        Node *temp = head, *prev = NULL;
        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        // If head needs to be deleted
        if (head->data == key) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            prev->next = head->next;
            delete head;
            head = prev->next;
            return;
        }

        // Search for the key
        while (temp->next != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was found
        if (temp->data == key) {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    
    cout << "Circular Linked List: ";
    cll.display();

    cll.deleteNode(20);
    cout << "After deleting 20: ";
    cll.display();

    return 0;
}