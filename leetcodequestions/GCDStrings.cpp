//leetcode 1071
#include<bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1 + str2 != str2 + str1) return "";

        int gcdLength = gcd(str1.length(), str2.length());

        return str1.substr(0, gcdLength);
    }

// private:

//     int gcd(int a, int b) {
//         return b == 0 ? a : gcd(b, a % b);
//     }
};

int main() {
    Solution sol;
    cout << sol.gcdOfStrings("ABCABC", "ABC") << endl; // Output: "ABC"
    cout << sol.gcdOfStrings("ABABAB", "ABAB") << endl; // Output: "AB"
    cout << sol.gcdOfStrings("LEET", "CODE") << endl; // Output: ""
    return 0;
}


//second approach using Euclid formula
// class Solution {
//     public:
//         int findGCD(int a, int b) { 
//             while (b != 0) { 
//                 int temp = b;
//                 b = a % b; 
//                 a = temp;
//             } 
//             return a;
//         }
    
//         string gcdOfStrings(string str1, string str2) {
//             // Check if str1 + str2 == str2 + str1 (ensures a common divisor string exists)
//             if (str1 + str2 != str2 + str1) 
//                 return "";
    
//             // Find GCD of the lengths of str1 and str2
//             int gcdLength = findGCD(str1.length(), str2.length());
    
//             // Return the substring of str1 from index 0 to gcdLength
//             return str1.substr(0, gcdLength);
//         }
//     };

    
    