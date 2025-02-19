#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1, right = 2 * index + 2, largest = index;
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);

    cout << "Max Heap Top: " << maxHeap.top() << endl; // 20
    maxHeap.pop(); 
    cout << "Max Heap Top after pop: " << maxHeap.top() << endl; // 15

    return 0;
}
