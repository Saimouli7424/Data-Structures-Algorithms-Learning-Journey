//Merge k Sorted Lists(Hard)
//using priority queue
//time complexity: O(n log k), space complexity: O(k)
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto list : lists) {
            while (list) {
                minHeap.push(list->val);
                list = list->next;
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!minHeap.empty()) {
            current->next = new ListNode(minHeap.top());
            minHeap.pop();
            current = current->next;
        }

        return dummy.next;
    }
};
int main() {
    Solution sol;
    vector<ListNode*> lists;

    // Example: Creating three linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* mergedList = sol.mergeKLists(lists);

    // Print merged linked list
    while (mergedList) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    // Clean up memory
    for (auto list : lists) {
        while (list) {
            ListNode* temp = list;
            list = list->next;
            delete temp;
        }
    }

    return 0;
}