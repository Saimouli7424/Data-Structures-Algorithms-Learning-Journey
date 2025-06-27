//Longest Mountain in Array(Medium)
//intuition finding the peak element and then expanding left and right
//Time complexity: O(n)
//space complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 1;
        int len = 0;

        while (i < n - 1) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                while (left > 0 && arr[left] > arr[left - 1]) left--;
                while (right < n - 1 && arr[right] > arr[right + 1]) right++;

                len = max(len, (right - left + 1));
                i = right;
            } else {
                i++;
            }
        }

        return len;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2, 1, 4, 7, 3, 2, 5};
    vector<int> test2 = {2, 2, 2};
    vector<int> test3 = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    cout << "Test 1: " << sol.longestMountain(test1) << endl; // Expected: 5 (1 4 7 3 2)
    cout << "Test 2: " << sol.longestMountain(test2) << endl; // Expected: 0 (no mountain)
    cout << "Test 3: " << sol.longestMountain(test3) << endl; // Expected: 11 (full mountain)

    return 0;
}
