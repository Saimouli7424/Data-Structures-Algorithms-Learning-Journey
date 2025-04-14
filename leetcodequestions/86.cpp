//Partition List(Medium)
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0); // dummy node for < x
        ListNode* afterHead = new ListNode(0);  // dummy node for >= x
        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        while (head != nullptr) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        after->next = nullptr; // end the list
        before->next = afterHead->next;

        return beforeHead->next;
    }
};

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> input1 = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    ListNode* head1 = createList(input1);
    cout << "Original List 1: ";
    printList(head1);
    ListNode* result1 = sol.partition(head1, x1);
    cout << "Partitioned List 1 (x = " << x1 << "): ";
    printList(result1);

    // Test case 2
    vector<int> input2 = {2, 1};
    int x2 = 2;
    ListNode* head2 = createList(input2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    ListNode* result2 = sol.partition(head2, x2);
    cout << "Partitioned List 2 (x = " << x2 << "): ";
    printList(result2);

    // Test case 3
    vector<int> input3 = {3, 5, 8, 5, 10, 2, 1};
    int x3 = 5;
    ListNode* head3 = createList(input3);
    cout << "\nOriginal List 3: ";
    printList(head3);
    ListNode* result3 = sol.partition(head3, x3);
    cout << "Partitioned List 3 (x = " << x3 << "): ";
    printList(result3);

    return 0;
}
