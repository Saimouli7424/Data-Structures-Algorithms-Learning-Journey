//ortoise and Hare Algorithm, also known as Floyd’s Cycle Detection Algorithm
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle using Floyd's Tortoise and Hare Algorithm
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;          // Moves 1 step
        fast = fast->next->next;    // Moves 2 steps

        if (slow == fast) return true; // Cycle detected
    }
    return false;
}

// Driver code
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; // Creating a cycle

    if (hasCycle(head)) cout << "Cycle detected in linked list!" << endl;
    else cout << "No cycle found." << endl;

    return 0;
}

/*
Step-by-Step Execution
Initial Setup:

slow at 1, fast at 1

Step 1:

slow moves to 2, fast moves to 3

Step 2:

slow moves to 3, fast moves to 2

Step 3:

slow moves to 2, fast moves to 2 → Cycle Detected!
*/