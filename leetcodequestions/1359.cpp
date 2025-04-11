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

        for(int i=1;i<=n;i++)
        {
            ans = (ans * (i + i-1)* i)%mod;
            //ans will be the total no.of combinations of previous to add
            //(i + i-1)*i gives the no.of ways to arrange the d for all the combinations of pickup added
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
