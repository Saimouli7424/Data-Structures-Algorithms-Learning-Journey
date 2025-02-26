//leetcode 9

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false; 

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Compare original half with reversed half
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << sol.isPalindrome(121) << endl;  // Output: 1 (true)
    cout << sol.isPalindrome(-121) << endl; // Output: 0 (false)
    cout << sol.isPalindrome(10) << endl;   // Output: 0 (false)
    cout << sol.isPalindrome(12321) << endl; // Output: 1 (true)

    return 0;
}
