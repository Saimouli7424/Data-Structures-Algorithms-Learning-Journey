//Intersection of Two Linked Lists(Easy)
#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a; // Intersection node or nullptr
    }
};

// Utility to print list from given node
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create two intersecting linked lists:
    // A: 1 → 2
    //            \
    //             3 → 4 → 5
    //            /
    // B:     6 →

    ListNode* common = new ListNode(3);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = common;

    ListNode* headB = new ListNode(6);
    headB->next = common;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}

/*
🔄 Step-by-step explanation with your case:No Intersection
Input:
List A = 1 → 2 → 3 → 4 → length = 4

List B = 6 → 7 → length = 2

Traverse:
Step	a	        b
1	    1	        6
2	    2	        7
3	    3	        nullptr
4	    4	        1 (headA)
5	    nullptr	    2
6	    6 (headB)	3
7	    7	        4
8	nullptr	nullptr ✅ → loop ends
*/