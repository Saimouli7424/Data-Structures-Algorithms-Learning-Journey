#include <iostream>
#include <vector>
using namespace std;

// Function to find all prime numbers up to 'n'
void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true); // Boolean array to mark primes
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not prime

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int n = 30;
    sieveOfEratosthenes(n);
    return 0;
}


// Step-by-Step Execution (For n = 10)
// Start with isPrime = [T, T, T, T, T, T, T, T, T, T, T]

// 2 is prime → Mark 4, 6, 8, 10 as non-prime

// 3 is prime → Mark 9 as non-prime

// Remaining primes: [2, 3, 5, 7]