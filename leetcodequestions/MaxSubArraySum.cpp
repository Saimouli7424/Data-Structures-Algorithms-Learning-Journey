//leetcode 53
#include <iostream>
#include <climits>
using namespace std;

#include <iostream>
#include <climits>  // For INT_MIN
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxelem = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxelem)
            maxelem = sum;

        if (sum < 0)
            sum = 0;
    }

    return maxelem;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr, n) << endl;

    return 0;
}
