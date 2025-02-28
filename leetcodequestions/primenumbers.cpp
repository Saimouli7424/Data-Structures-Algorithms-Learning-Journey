//leetcode 204
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // No prime numbers less than 2

        vector<bool> isPrime(n, true); // Create an array of size n, initialized to true
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i < n; i++) { // Iterate up to sqrt(n)
            if (isPrime[i]) { // If i is prime, mark its multiples
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false; // Mark multiples of i as non-prime
                }
            }
        }

        // Count the prime numbers
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int primeCount = sol.countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << primeCount << endl;

    return 0;
}


/*
The Sieve of Eratosthenes is already efficient with O(N log log N) complexity

Explaination:-
Let's go step by step for n = 11 using the Sieve of Eratosthenes.

Initialization:
We create an isPrime array of size n (11 in this case) and initialize all values to true, except 0 and 1, which are set to false (since they are not prime).

r
Copy
Edit
Index:    0   1   2   3   4   5   6   7   8   9   10  
isPrime:  F   F   T   T   T   T   T   T   T   T   T  
(F = false, T = true)

Step 1: i = 2
Since isPrime[2] = true, mark all multiples of 2 (starting from 2*2 = 4) as false.

Multiples of 2 within range: 4, 6, 8, 10

r
Copy
Edit
Index:    0   1   2   3   4   5   6   7   8   9   10  
isPrime:  F   F   T   T   F   T   F   T   F   T   F  
Step 2: i = 3
Since isPrime[3] = true, mark all multiples of 3 (starting from 3*3 = 9) as false.

Multiples of 3 within range: 9

r
Copy
Edit
Index:    0   1   2   3   4   5   6   7   8   9   10  
isPrime:  F   F   T   T   F   T   F   T   F   F   F  
Step 3: i = 4
Since isPrime[4] = false, skip it.

Step 4: i = 5
Since 5×5=25>11, the loop stops

Final Prime Numbers:
All true values in isPrime[] indicate prime numbers.
Prime numbers < 11: 2, 3, 5, 7

Final Output: 4 (because there are 4 primes)
*/