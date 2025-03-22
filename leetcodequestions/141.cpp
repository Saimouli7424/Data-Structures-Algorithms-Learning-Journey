//Linked List Cycle(easy)
//using tortoise and hares algorithm
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(!head || !head->next)return false;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast)return true;
            }
            // unordered_map<ListNode*,int>ptrmap;
            // ListNode* temp = head;
            // while(temp!=nullptr)
            // {
            //     if(ptrmap.find(temp)!=ptrmap.end())return true;
            //     ptrmap[temp]++;
            //     temp=temp->next;
            // }
            return false;
        }
    };
int main() {
    Solution solution;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout<<solution.hasCycle(head);
    return 0;
}

//Using Floyd's Tortoise and Hare Algorithm
//Time complexity: O(n)
//Space complexity: O(1)
//where n is the number of nodes in the linked list.
//The algorithm uses two pointers, called the tortoise and the hare. The tortoise moves one step at a time, and the hare moves two steps at a time. If there is a cycle in the linked list, the hare will eventually catch up to the tortoise. If there is no cycle, the hare will reach the end of the linked list.
//The algorithm has a time complexity of O(n) and a space complexity of O(1), where n is the number of nodes in the linked list.
//The algorithm is efficient and does not require any extra space. It is a widely used algorithm for detecting cycles in linked lists.
//The algorithm is also known as Floyd's cycle-finding algorithm, and it is named after Robert W. Floyd, who first described it in 1967.
//The algorithm is simple and easy to implement. It is a good choice for detecting cycles in linked lists.
//The algorithm is widely used in computer science and is a fundamental algorithm for detecting cycles in linked lists.
//The algorithm is efficient and has a time complexity of O(n) and a space complexity of O(1), where n is the number of nodes in the linked list.
//The algorithm is widely used in computer science and is a fundamental algorithm for detecting cycles in linked lists.
//The algorithm is efficient and has a time complexity of O(n) and a space complexity of O(1), where n is the number of nodes in the linked list.