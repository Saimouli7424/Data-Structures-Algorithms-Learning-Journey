//Closest prime numbers in range leetcode 2523(Medium level)
//Sieve of Eratosthenes Algo

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> result = {-1, -1};
        if (right < 2 || left > right) return result; // No primes below 2 or invalid range
        
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        
        // Use Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for (int i = max(left, 2); i <= right; i++) {
            if (isPrime[i]) {
                primes.emplace_back(i);
            }
        }
        
        int minDiff = INT_MAX;
        if (primes.size() >= 2) {
            for (int i = 1; i < primes.size(); i++) {
                int diff = primes[i] - primes[i - 1];
                if (diff < minDiff) {
                    minDiff = diff;
                    result[0] = primes[i - 1];
                    result[1] = primes[i];
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int left, right;
    cout << "Enter left and right range: ";
    cin >> left >> right;
    vector<int> result = sol.closestPrimes(left, right);
    
    if (result[0] == -1 && result[1] == -1) {
        cout << "No closest primes found in the given range." << endl;
    } else {
        cout << "Closest primes: " << result[0] << " and " << result[1] << endl;
    }
    return 0;
}
