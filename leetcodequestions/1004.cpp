//Max Consecutive Ones III(Medium)
//Using sliding window
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxelem = 0;
        if (k >= nums.size()) return nums.size();

        int zeroes = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroes++;

            while (zeroes > k) {
                if (nums[left] == 0) zeroes--;
                left++;
            }
            maxelem = max(maxelem, right - left + 1);
        }

        return maxelem;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1}; // Example input
    int k = 2;

    int result = solution.longestOnes(nums, k);
    cout << "Longest sequence of 1s (with at most " << k << " flips): " << result << endl;

    return 0;
}
//time complexity: O(n)
//space complexity: O(1)


/*
Using binary search
class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int left=0;
        int right=nums.size();
        if(k>=nums.size())return nums.size();

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(check(nums,mid,k))
            {
                left=mid+1;
            }else
            {
                right=mid-1;
            }
        }
        return right;
    }

    bool check(vector<int>& nums,int elem,int k)
    {
        int zeroes = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroes++;

            while (zeroes > k)
            {
                if (nums[left] == 0) zeroes--;
                left++;
            }

            if (right - left + 1 >= elem) return true;
        }

        return false;

    }
};
//time complexity: O(nlogn)
//space complexity: O(1)
*/