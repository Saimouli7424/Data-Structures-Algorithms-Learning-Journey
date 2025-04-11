//Generate Parentheses(Medium)
//using backtracking to generate all combinations of valid parentheses
//Time complexity: O(4^n/sqrt(n)), Space complexity: O(n)
//The number of valid parentheses combinations is given by the nth Catalan number, which is approximately 4^n/sqrt(n) for large n.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {};
        vector<string> result;
        string temp = "(";
        backtracking(n, result, temp, 1, 0);
        return result;
    }

    void backtracking(int n, vector<string>& result, string& temp, int left, int right) {
        if(right == n) {
            result.emplace_back(temp);
            return;
        }
        /*
        //my code
        if(left < n) {
            temp += '(';
            left++;
            backtracking(n, result, temp, left, right);
            temp.pop_back();
            left--;

            if (right < left) {
                temp += ')';
                right++;
                backtracking(n, result, temp, left, right);
                temp.pop_back();
                right--;
            }
        }

        if(left >= n) {
            temp += ')';
            right++;
            backtracking(n, result, temp, left, right);
            temp.pop_back();
            right--;
        }*/

        //optimized code
        if (left < n) {
            temp += '(';
            backtracking(n, result, temp, left + 1, right);
            temp.pop_back();
        }
        
        if (right < left) {
            temp += ')';
            backtracking(n, result, temp, left, right + 1);
            temp.pop_back();
        }
    }
};

int main() {
    Solution solution;
    int n = 3; // You can change n to test with other values
    vector<string> result = solution.generateParenthesis(n);

    cout << "Valid parentheses combinations for n = " << n << ":\n";
    for(const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
