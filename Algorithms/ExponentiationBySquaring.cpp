//Pow(x, n)(Medium)
//TIME COMPLEXITY(O(log n))
//SPACE COMPLEXITY(O(1))
#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            long long N = n;
            if (n < 0) {
                N = -1*N;
            }
            double ans=1;
            while(N!=0)
            {
                if(N%2==1)
                {
                    ans=ans*x;
                    N=N-1;
                }
                else
                {
                    x=x*x;
                    N=N/2;
                }
            }
            if(n<0)
            {
                ans = (double)(1.0)/ans;
            }
            return ans;
        }
    };
    

int main() {
    Solution sol;

    // Sample test cases
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = sol.myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
