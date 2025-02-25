//leetcode 121
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int minIndex = 0;  
        int maxProfit = 0;  

        for (int right = 1; right < prices.size(); right++) {
            
            if (prices[right] < prices[minIndex]) {
                minIndex = right;
            } 

            else {
                maxProfit = max(maxProfit, prices[right] - prices[minIndex]);
            }
        }

        return maxProfit;
    }
};


int main() {
    vector<int> prices = {7, 2, 6, 3, 1, 4};
    Solution sol;
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
