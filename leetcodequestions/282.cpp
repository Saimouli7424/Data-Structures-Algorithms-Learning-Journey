//Expression Add Operators(Hard)
//using backtracking
//time complexity: O(4^n) where n is the length of the input string
//space complexity: O(n) for the recursion stack

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        backtracking(num, target, 0, 0, 0, "", result);
        return result;
    }

    void backtracking(string& num, int target, int pos, long long sum, long long prev_operand, string temp, vector<string>& result) {
        // If we've processed all digits
        if (pos == num.size()) {
            if (sum == target) {
                result.push_back(temp);
            }
            return;
        }

        // Iterate over the digits to create multi-digit numbers
        for (int i = pos; i < num.size(); i++) {
            // Skip leading zero numbers (e.g., "012" is invalid)
            if (i != pos && num[pos] == '0') break;

            //starting pos,length to take from starting
            string str = num.substr(pos, i - pos + 1);
            long long val = stoll(str); // Convert the substring to a long long

            // If we're at the first position, we directly add the number without any operator
            if (pos == 0) {
                backtracking(num, target, i + 1, val, val, str, result);
            } else {
                // Addition
                backtracking(num, target, i + 1, sum + val, val, temp + "+" + str, result);

                // Subtraction
                backtracking(num, target, i + 1, sum - val, -val, temp + "-" + str, result);

                // Multiplication
                backtracking(num, target, i + 1, sum - prev_operand + (prev_operand * val), prev_operand * val, temp + "*" + str, result);
            }
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string num1 = "232";
    int target1 = 8;
    vector<string> result1 = solution.addOperators(num1, target1);
    cout << "Test Case 1: " << endl;
    for (const string& expr : result1) {
        cout << expr << endl;
    }

    // Test case 2
    string num2 = "123";
    int target2 = 6;
    vector<string> result2 = solution.addOperators(num2, target2);
    cout << "\nTest Case 2: " << endl;
    for (const string& expr : result2) {
        cout << expr << endl;
    }

    // Test case 3
    string num3 = "105";
    int target3 = 5;
    vector<string> result3 = solution.addOperators(num3, target3);
    cout << "\nTest Case 3: " << endl;
    for (const string& expr : result3) {
        cout << expr << endl;
    }

    return 0;
}
