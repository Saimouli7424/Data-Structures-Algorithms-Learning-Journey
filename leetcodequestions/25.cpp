//Reverse Nodes in k-Group(Hard)
//using in-place reversal
//Time Complexity: O(n)
//Space Complexity: O(1)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k<=1)return head;

        ListNode* firsthead = nullptr, *frontHead = head, *prevTail = nullptr;
        bool first=false;

        while(head){
            int count = 0;
            ListNode* temp = head;
            while(temp && count<k){
                temp = temp->next;
                count++;
            }

            if(count<k)break;

            ListNode* tailHead, *nextHead;
            tailHead = nextHead = head;

            ListNode* prev;
            count=0;
            while(head && count<k){
                prev = head->next;
                frontHead = head;
                frontHead->next = nextHead;
                nextHead = frontHead;
                head = prev;
                count++;
            }
            if(!first){
                first = true;
                firsthead = frontHead;
            }
            else{
                prevTail->next = frontHead;
            }
            prevTail = tailHead;
            frontHead = tailHead;
        }

        if(prevTail) prevTail->next = head;
        return firsthead;
    }
};

// ---------- Helpers for testing ----------
ListNode* createList(vector<int> vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(int i=1; i<vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ---------- Main function with testcases ----------
int main() {
    Solution sol;

    // Testcase 1
    vector<int> v1 = {1,2,3,4,5};
    ListNode* head1 = createList(v1);
    cout << "Original List 1: ";
    printList(head1);
    ListNode* res1 = sol.reverseKGroup(head1, 2);
    cout << "Reversed in groups of 2: ";
    printList(res1);
    cout << endl;

    // Testcase 2
    vector<int> v2 = {1,2,3,4,5};
    ListNode* head2 = createList(v2);
    cout << "Original List 2: ";
    printList(head2);
    ListNode* res2 = sol.reverseKGroup(head2, 3);
    cout << "Reversed in groups of 3: ";
    printList(res2);
    cout << endl;

    // Testcase 3
    vector<int> v3 = {1,2,3,4,5,6};
    ListNode* head3 = createList(v3);
    cout << "Original List 3: ";
    printList(head3);
    ListNode* res3 = sol.reverseKGroup(head3, 4);
    cout << "Reversed in groups of 4: ";
    printList(res3);
    cout << endl;

    return 0;
}

