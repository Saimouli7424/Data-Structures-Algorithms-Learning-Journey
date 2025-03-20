//Reverse Linked List(Easy)
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) 
        {
            if(!head || !head->next)return head;
            ListNode* temp=head;
            ListNode* prev=nullptr;
            ListNode* nextt=nullptr;
            ListNode* current=nullptr;
            while(temp!=nullptr){
                current=temp;
                nextt=temp->next;
                temp->next=prev;
                temp=nextt;
                prev=current;
            }
            return current;
        }
    };

int main()
    {
        ListNode* head=new ListNode(1);
        head->next=new ListNode(2);
        head->next->next=new ListNode(3);
        head->next->next->next=new ListNode(4);
        head->next->next->next->next=new ListNode(5);
        Solution s;
        ListNode* ans=s.reverseList(head);
        while(ans!=nullptr){
            cout<<ans->val<<" ";
            ans=ans->next;
        }
        return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
// Input: 1->2->3->4->5
// Output: 5->4->3->2->1

//Note: In the above code, we are using three pointers to swap the values of the nodes in the list. This approach has a time complexity of O(n) and a space complexity of O(1). The head of the reversed list is returned as the result.
