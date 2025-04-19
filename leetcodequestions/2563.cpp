//Count the Number of Fair Pairs
//using binarysearch
//Time complexity: O(nlogn) for sorting and O(n) for the loop, so overall O(nlogn)
//and also using atmost(k) tehcnique to find the number of pairs
//Space complexity: O(1) for the variables used
//and O(n) for the input array

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    /* atmost k technique*/
    public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    
    sort(nums.begin(), nums.end());
    return countLess(nums, upper) - countLess(nums, lower - 1);
    }

private:
    long countLess(const vector<int>& nums, int sum) {
    long res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
        while (i < j && nums[i] + nums[j] > sum)
        --j;
        res += j - i;
    }
    return res;
    }
};

   /* 
   //using binarysearch finding upperbound index-lower bound index

   class Solution {
   public:
       long long countFairPairs(vector<int>& nums, int lower, int upper) {
           sort(nums.begin(), nums.end());
           long long count = 0;
           int n = nums.size();
   
           for (int i = 0; i < n; ++i) {
               int low = lowerBound(nums, i + 1, n - 1, lower - nums[i]);
               int high = upperBound(nums, i + 1, n - 1, upper - nums[i]);
               count += (high - low + 1);
           }
   
           return count;
       }
   
   private:
       // Custom lower_bound: First index ≥ target
       int lowerBound(vector<int>& nums, int left, int right, int target) {
           int ans = right + 1;
           while (left <= right) {
               int mid = left + (right - left) / 2;
               if (nums[mid] >= target) {
                   ans = mid;
                   right = mid - 1;
               } else {
                   left = mid + 1;
               }
           }
           return ans;
       }
   
       // Custom upper_bound: Last index ≤ target
       int upperBound(vector<int>& nums, int left, int right, int target) {
           int ans = left - 1;
           while (left <= right) {
               int mid = left + (right - left) / 2;
               if (nums[mid] <= target) {
                   ans = mid;
                   left = mid + 1;
               } else {
                   right = mid - 1;
               }
           }
           return ans;
       }
   };
   */

   
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int lower1 = 5, upper1 = 7;
    cout << "Test case 1 result: " << sol.countFairPairs(nums1, lower1, upper1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 3, 5, 7, 9};
    int lower2 = 6, upper2 = 10;
    cout << "Test case 2 result: " << sol.countFairPairs(nums2, lower2, upper2) << endl;

    // Test case 3
    vector<int> nums3 = {4, 8, 1, 6, 3, 2};
    int lower3 = 5, upper3 = 9;
    cout << "Test case 3 result: " << sol.countFairPairs(nums3, lower3, upper3) << endl;

    return 0;
}
