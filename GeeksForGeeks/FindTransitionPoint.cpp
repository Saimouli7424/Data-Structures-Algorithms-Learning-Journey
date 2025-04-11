//https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == 1) {
                result = mid;       // Potential answer, go left for earlier 1
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {0, 0, 0, 1, 1};
    vector<int> arr2 = {0, 0, 0, 0};
    vector<int> arr3 = {1, 1, 1, 1};

    cout << "Transition Point in arr1: " << sol.transitionPoint(arr1) << endl; // Output: 3
    cout << "Transition Point in arr2: " << sol.transitionPoint(arr2) << endl; // Output: -1
    cout << "Transition Point in arr3: " << sol.transitionPoint(arr3) << endl; // Output: 0

    return 0;
}
