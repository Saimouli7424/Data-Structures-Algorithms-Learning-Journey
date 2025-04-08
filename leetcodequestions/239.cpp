//Sliding Window Maximum(Hard)
//using priority queue and using multiset
//Time complexity: O(nlogk)
//Space complexity: O(k)
//optimal is using deque and time complexity of it's O(n) and space complexity of O(k)
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /*
    //using multiset
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;
        multiset<int> window;

        for (int i = 0; i < k; i++)
        {
            window.insert(nums[i]);
        }

        result.emplace_back(*window.rbegin());

        for (int i = k; i < nums.size(); i++)
        {
            int val = nums[i - k];
            window.erase(window.find(val)); // ✅ fix: remove one instance
            window.insert(nums[i]);
            result.emplace_back(*window.rbegin());
        }

        return result;
    }*/

    /*
    //using priority queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        result.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});
            
            
            while (pq.top().second <= i - k) {
                pq.pop();
            }

            result.push_back(pq.top().first);
        }

        return result;
    }*/

    //using deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            // Remove out-of-window indices
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Push current index
            dq.push_back(i);

            // Append result from k-1 onward
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
    int k = 4;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

