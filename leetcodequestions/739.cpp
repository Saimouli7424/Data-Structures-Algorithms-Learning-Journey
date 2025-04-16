//Daily Temperatures(Medium)
//Using Monotonic stack approach
//time complexity: O(n)
//space complexity: O(n)
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            st.push(i);
        }

        return result;
    }
};

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> test1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result1 = sol.dailyTemperatures(test1);
    cout << "Test Case 1: ";
    printVector(result1);  // Expected: 1 1 4 2 1 1 0 0

    vector<int> test2 = {30, 40, 50, 60};
    vector<int> result2 = sol.dailyTemperatures(test2);
    cout << "Test Case 2: ";
    printVector(result2);  // Expected: 1 1 1 0

    vector<int> test3 = {30, 60, 90};
    vector<int> result3 = sol.dailyTemperatures(test3);
    cout << "Test Case 3: ";
    printVector(result3);  // Expected: 1 1 0

    return 0;
}
