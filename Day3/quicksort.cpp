#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }

        while (arr[j] > pivot && j > low) {
            j--;
        }

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case

    int pivotIndex = partition(arr, low, high);
    
    quicksort(arr, low, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, high);
}

int main() {
    vector<int> arr = {3, 7, 1, 9, 2, 5, 8};

    int n = arr.size();
    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
