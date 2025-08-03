//Rearranging Fruits(Hard)
//Using a greedy approach to maximize the number of fruits in the basket and hashmap
//time complexity: O(n log n)
//space complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp, b1, b2;

        // Smallest element to help in double swap optimization
        int smallest = INT_MAX;

        int n = basket1.size();
        for (int i = 0; i < n; i++) {
            mp[basket1[i]]++;
            mp[basket2[i]]++;
            b1[basket1[i]]++;
            b2[basket2[i]]++;
            smallest = min({smallest, basket1[i], basket2[i]});
        }

        // If any element occurs odd number of times, impossible to make baskets equal
        for (auto &i : mp) {
            if (i.second % 2 != 0) return -1;
        }

        vector<int> required1;
        vector<int> required2;

        // Find extra elements that need to be swapped
        for (auto &it : mp) {
            int val = it.first;
            int target = it.second / 2;

            if (b1[val] > target) {
                for (int k = 0; k < b1[val] - target; k++)
                    required1.push_back(val);
            }
            if (b2[val] > target) {
                for (int k = 0; k < b2[val] - target; k++)
                    required2.push_back(val);
            }
        }

        sort(required1.begin(), required1.end());
        sort(required2.begin(), required2.end(), greater<int>());

        long long cost = 0;
        for (int i = 0; i < required1.size(); i++) {
            cost += min(2LL * smallest, (long long)min(required1[i], required2[i]));
        }
        return cost;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> basket1_1 = {4, 2, 2, 2};
    vector<int> basket2_1 = {1, 4, 1, 2};
    cout << "Test Case 1: " << sol.minCost(basket1_1, basket2_1) << endl;
    // Expected Output: 1 (swap 2 with 1 using smallest element = 1)

    // Test Case 2
    vector<int> basket1_2 = {1, 2, 3};
    vector<int> basket2_2 = {3, 2, 1};
    cout << "Test Case 2: " << sol.minCost(basket1_2, basket2_2) << endl;
    // Expected Output: 0 (already identical multisets)

    // Test Case 3
    vector<int> basket1_3 = {5, 5, 5};
    vector<int> basket2_3 = {5, 5, 5};
    cout << "Test Case 3: " << sol.minCost(basket1_3, basket2_3) << endl;
    // Expected Output: 0 (baskets are already equal)

    return 0;
}
