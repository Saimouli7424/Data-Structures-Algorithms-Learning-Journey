//Odd Even Linked List
//using linkedlist and dummy node
//time complexity: O(n)
//space complexity: O(1)
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;  // If the list is empty or has only one element
        
        ListNode* even = new ListNode(0);  // Placeholder for even indexed nodes
        ListNode* odd = new ListNode(0);   // Placeholder for odd indexed nodes
        ListNode* evenTemp = even;          // Pointer to even list
        ListNode* oddTemp = odd;            // Pointer to odd list
        
        int count = 0;
        while (head != nullptr) 
        {
            if (count % 2 == 0) 
            {
                evenTemp->next = head;  // Add the current node to even list
                evenTemp = evenTemp->next;  // Move the pointer to the next even node
            } 
            else 
            {
                oddTemp->next = head;  // Add the current node to odd list
                oddTemp = oddTemp->next;  // Move the pointer to the next odd node
            }
            head = head->next;  // Move to the next node in the original list
            count++;  // Increment the count to track even and odd positions
        }
        
        oddTemp->next = nullptr;  // End the odd list
        evenTemp->next = odd->next;  // Link the even list with the odd list
        
        return even->next;  // Return the head of the rearranged list
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array of values
ListNode* createList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Main function with test cases
int main() {
    Solution solution;

    // Test Case 1: Example list [1, 2, 3, 4, 5]
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    head1 = solution.oddEvenList(head1);
    cout << "Rearranged List 1: ";
    printList(head1);  // Expected Output: 1 3 5 2 4

    // Test Case 2: Example list [1, 2, 3, 4, 5, 6]
    int arr2[] = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createList(arr2, 6);
    head2 = solution.oddEvenList(head2);
    cout << "Rearranged List 2: ";
    printList(head2);  // Expected Output: 1 3 5 2 4 6

    // Test Case 3: Example list [1, 2]
    int arr3[] = {1, 2};
    ListNode* head3 = createList(arr3, 2);
    head3 = solution.oddEvenList(head3);
    cout << "Rearranged List 3: ";
    printList(head3);  // Expected Output: 1 2

    // Test Case 4: Empty list []
    ListNode* head4 = nullptr;
    head4 = solution.oddEvenList(head4);
    cout << "Rearranged List 4: ";
    printList(head4);  // Expected Output: (nothing)

    return 0;
}
