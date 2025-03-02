//leetcode 2

#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int data = 0;
            if (l1 != NULL && l2 != NULL) {
                data = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != NULL) {
                data = l1->val + carry;
                l1 = l1->next;
            }
            else {
                data = l2->val + carry;
                l2 = l2->next;
            }

            if (data >= 10) {
                carry = data / 10;
                data = data % 10;
            }
            else {
                carry = 0;
            }

            ListNode* newnode = new ListNode(data);
            if (head == NULL) {
                head = newnode;
            }
            else {
                ListNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }

        if (carry != 0) {
            ListNode* newnode = new ListNode(carry);
            ListNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating static inputs
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Resultant Linked List: ";
    printList(result);

    return 0;
}
