#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> maxHeap;  // Max Heap (default)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap

    // Inserting elements
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);

    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);

    cout << "Max Heap Top: " << maxHeap.top() << endl; // 20
    maxHeap.pop(); // Remove 20

    cout << "Min Heap Top: " << minHeap.top() << endl; // 10
    minHeap.pop();

    return 0;
}
