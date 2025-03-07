//Remove OuterMost parenthesis leetcode 1021(easy)

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        //using stack
        /* stack<char>c;
        string result;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='"')
            {
                result+=s[i];
            }
            if(s[i]=='(')
            {
                if(!c.empty())
                {
                    result += s[i];
                }
                c.push(s[i]);
            }
            else if(s[i]==')')
            {
                char a = c.top();
                c.pop();
                if(!c.empty())
                {
                    result+=s[i];
                }
            }
        }
        string result;*/
        int open = 0;
        
        for(char ch : s) {
            if(ch == '(') {
                if(open > 0) {
                    result += ch;
                }
                open++;
            } 
            else if(ch == ')') {
                open--;
                if(open > 0) {
                    result += ch;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string input = "(()())(())(()(()))";
    string result = sol.removeOuterParentheses(input);
    cout << "Result: " << result << endl;
    return 0;
}
