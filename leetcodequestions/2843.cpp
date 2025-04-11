//Count Symmetric Integers(Medium)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            int len = s.length();
            if (len % 2 != 0) continue;

            int mid = len / 2;
            int sum1 = 0, sum2 = 0;

            for (int i = 0; i < mid; ++i)
                sum1 += s[i] - '0';
            for (int i = mid; i < len; ++i)
                sum2 += s[i] - '0';

            if (sum1 == sum2)
                ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int low = 1, high = 1000;

    cout << "Number of symmetric integers between " << low << " and " << high << " is: ";
    cout << sol.countSymmetricIntegers(low, high) << endl;

    return 0;
}
