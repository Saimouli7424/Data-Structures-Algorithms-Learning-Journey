//Letter Case Permutation(Medium)
//using backtracking
#include <bits/stdc++.h>
using namespace std;


/*
//my aprroach 6ms
class Solution {
    public:
        void backtrack(string& s, string temp, vector<string>& result, int index) {
            if (index == s.size()) {
                result.push_back(temp);  // ✅ Store the current permutation
                return;
            }
    
            for (int i = index; i < s.size(); i++) {
                char ch = s[i];
    
                if (isalpha(ch)) {
                    temp += toupper(ch);
                    backtrack(s, temp, result, i + 1);  // ✅ Recur with uppercase
                    temp.pop_back();  // 🔄 Backtrack
    
                    temp += tolower(ch);
                    backtrack(s, temp, result, i + 1);  // ✅ Recur with lowercase
                    temp.pop_back();  // 🔄 Backtrack
                } else {
                    temp += ch;
                    backtrack(s, temp, result, i + 1);  // ✅ Continue without modification
                    // No need to pop_back() here since it doesn't alter case
                }
            }
        }
    
        vector<string> letterCasePermutation(string s) 
        {
            vector<string> result;
            backtrack(s, "", result, 0);
            return result;
    }
};  */  

//optimal approach

class Solution {
    public:
        vector<string> letterCasePermutation(string s) {
            vector<string>result;
            backtrack(s,result,0);
            return result;
        }
    
        void backtrack(string s,vector<string>& result,int index)
        {
            if(index==s.length())
            {
                result.emplace_back(s);
                return;
            }
            backtrack(s,result,index+1);
            if(isalpha(s[index]))
                {
                    s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]); 
                    backtrack(s, result, index + 1);
                    s[index] = islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
                }
        }
    };

int main() {
    Solution solution;
    string s = "a1b2";
    vector<string> result = solution.letterCasePermutation(s);
    for (const auto& str : result) 
    {
        cout << str << endl;
    }
    return 0;
}
        /*
        Output:
        a1B2
        A1b2
        a1B2
        A1B2
        */