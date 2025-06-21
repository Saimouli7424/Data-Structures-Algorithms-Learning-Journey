// Problem: A Love Triangle
// Problem Link: https://codeforces.com/problemset/problem/1639/A
//time complexity: O(n)
//space complexity: O(1)
#include<iostream>
#include<vector>
using namespace std;

bool checkLoveTriangle(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int first = i + 1;
        int second = arr[arr[i] - 1];
        int third = arr[second - 1];
        if(first == third) {
            return true;
        }
    }
    return false;
}

int main() {
    // Test Case 1
    vector<int> test1 = {2, 3, 1};  // 1→2→3→1 ⇒ YES
    cout << "Test Case 1: ";
    cout << (checkLoveTriangle(test1) ? "YES" : "NO") << endl;

    // Test Case 2
    vector<int> test2 = {2, 3, 4, 5, 1};  // No triangle ⇒ NO
    cout << "Test Case 2: ";
    cout << (checkLoveTriangle(test2) ? "YES" : "NO") << endl;

    // Test Case 3
    vector<int> test3 = {2, 3, 1, 5, 4};  // 1→2→3→1 and 4→5→4 ⇒ YES
    cout << "Test Case 3: ";
    cout << (checkLoveTriangle(test3) ? "YES" : "NO") << endl;

    return 0;
}
