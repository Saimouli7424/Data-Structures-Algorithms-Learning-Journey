//Count All Valid Pickup and Delivery Options(Medium)
//time complexity O(n)
//space complexity O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % mod;             // Ways to arrange pickups
            ans = (ans * (2 * i - 1)) % mod;    // Ways to arrange deliveries after pickups
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4;

    int result = sol.countOrders(n);
    cout << "Number of valid pickup and delivery sequences: " << result << endl;

    return 0;
}
