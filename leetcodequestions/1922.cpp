//Count Good Numbers(Medium)
//using forloop got TLE
//using math and exponential theorem
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) 
    {
        long long mod = 1e9 + 7;
        long long even = 5, prime = 4;
        long long res;

        if (n % 2 == 0)
        {
            res = (modpow(prime, n / 2, mod) * modpow(even, n / 2, mod)) % mod;
        }
        else
        {
            res = (modpow(prime, n / 2, mod) * modpow(even, (n / 2) + 1, mod)) % mod;
        }

        return (int)res;

        /*
        //GOT TLE
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)res=(res*prime)%mod;
            else res=(res*even)%mod;
        }
        return (int)res;
        */
    }
};

int main() {
    Solution sol;

    // Test Case 1
    long long n1 = 1;
    cout << "countGoodNumbers(" << n1 << ") = " << sol.countGoodNumbers(n1) << endl;

    // Test Case 2
    long long n2 = 4;
    cout << "countGoodNumbers(" << n2 << ") = " << sol.countGoodNumbers(n2) << endl;

    // Test Case 3
    long long n3 = 50;
    cout << "countGoodNumbers(" << n3 << ") = " << sol.countGoodNumbers(n3) << endl;

    return 0;
}
