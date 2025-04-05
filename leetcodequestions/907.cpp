//Sum of Subarray Minimums(medium)
//using monotonic stack and contribution of each element to the sum of subarray minimums
//time complexity: O(n) where n is the number of elements in arr
//space complexity: O(n) for the left and right arrays
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> left(n), right(n);

        // Find previous less element count
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Find next less or equal element count
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            res = (res + (long)arr[i] * left[i] * right[i]) % mod;
        }

        return (int)res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};

    int result = sol.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl;

    return 0;
}
