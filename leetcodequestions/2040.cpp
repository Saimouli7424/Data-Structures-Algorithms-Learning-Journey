//Kth Smallest Product of Two Sorted Arrays(Hard)
//using binary search
//time complexity: O(nlog(max(a*b)))
//space complexity: O(1)
//Binarysearch on answers we will find whether it's possible to find k products less than or equal to mid
//We will count how many products are less than or equal to mid using binary search on nums

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long mid) {
        long long count = 0;
        int m = nums2.size();

        for (int i = 0; i < nums1.size(); ++i) {
            int a = nums1[i];
            if (a == 0) {
                if (mid >= 0) count += m; // 0 * anything <= mid if mid ≥ 0
            }
            else if (a > 0) {
                // count number of nums2[j] where a * nums2[j] <= mid
                int left = 0, right = m - 1, pos = -1;
                while (left <= right) {
                    int middle = left + (right - left) / 2;
                    if (1LL * a * nums2[middle] <= mid) {
                        pos = middle;
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                count += (pos + 1);
            }
            else { // a < 0
                // count number of nums2[j] where a * nums2[j] <= mid
                int left = 0, right = m - 1, pos = m;
                while (left <= right) {
                    int middle = left + (right - left) / 2;
                    if (1LL * a * nums2[middle] <= mid) {
                        pos = middle;
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
                count += (m - pos);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {2, 4};
    long long k = 6;

    cout << "K-th smallest product is: " << s.kthSmallestProduct(nums1, nums2, k) << endl;
    return 0;
}
// Example usage:
// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
// Output: 0
// Explanation: The products are [-8, -4, 0, 6, -6, -2, 0, 12], and the 6th smallest is 0.
// Note: The code uses binary search to efficiently find the k-th smallest product of two sorted arrays.
// The countLessEqual function counts how many products are less than or equal to mid.
// The main function demonstrates how to use the Solution class to find the k-th smallest product.
// Note: The code assumes that nums1 and nums2 are sorted arrays and k is a valid index.
// The code is designed to handle edge cases such as negative numbers and zeroes in the input arrays.

// The time complexity is O(n log(max(a*b))) where n is the size of nums1 and nums2.
// The space complexity is O(1) since we are using a constant amount of extra space.
// The code is efficient and works well for the problem constraints.
// The code is written in C++ and uses the standard library for input/output and vector operations