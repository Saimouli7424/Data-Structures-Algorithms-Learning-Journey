//Ugly Number(Easy)
// Given an integer n, return true if n is a ugly number.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* 
    //cleaner code below one
    bool isUgly(int n)
    {
        if (n <= 0) return false;

        for (int factor : {2, 3, 5})
        {
            while (n % factor == 0)
            {
                n /= factor;
            }
        }

        return n == 1;
        }
    */

    //my code
    bool isUgly(int n)
    {
        if(n<=0)return false;
        while(n)
        {
            if(n==1)return true;
            if(n%2==0)n/=2;
            else if(n%3==0)n/=3;
            else if(n%5==0)n/=5;
            else return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> testCases = {6, 14, 0};
    for (int n : testCases) {
        cout << "Input: " << n << " → Output: " 
             << (sol.isUgly(n) ? "true" : "false") << endl;
    }

    return 0;
}
