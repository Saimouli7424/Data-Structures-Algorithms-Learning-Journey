//using for setbits
#include <iostream>
using namespace std;

// Function to count set bits using Brian Kernighan's Algorithm
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // clear the least significant bit set
        count++;
    }
    return count;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = countSetBits(num);
    cout << "Number of set bits in " << num << " is: " << result << endl;

    return 0;
}
