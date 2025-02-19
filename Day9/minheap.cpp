#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1, right = 2 * index + 2, smallest = index;
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
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
    MinHeap minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);

    cout << "Min Heap Top: " << minHeap.top() << endl; // 10
    minHeap.pop(); 
    cout << "Min Heap Top after pop: " << minHeap.top() << endl; // 15

    return 0;
}
