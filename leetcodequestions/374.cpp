//Guess Number Higher or Lower(Easy)
//binary search
#include <iostream>
using namespace std;

// Mock guess API (you need to implement it based on the actual number to guess)
int target; // Global variable to store the correct number
int guess(int num) {
    if (num == target) return 0;
    return (num < target) ? 1 : -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter the range (n): ";
    cin >> n;
    
    cout << "Enter the target number: ";
    cin >> target; // Set the correct number to guess
    
    Solution sol;
    int result = sol.guessNumber(n);
    cout << "The guessed number is: " << result << endl;
    
    return 0;
}
