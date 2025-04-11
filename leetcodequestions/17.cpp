//Letter Combinations of a Phone Number(Medium)
//time complexity O(4^n) where n is the length of digits
//space complexity O(4^n)
//done by using recursion can also use backtracking

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool stop = false;
        unordered_map<char,string>mp = {
                {'2',"abc"},
                {'3',"def"},
                {'4',"ghi"},
                {'5',"jkl"},
                {'6',"mno"},
                {'7',"pqrs"},
                {'8',"tuv"},
                {'9',"wxyz"}
            };
        vector<string> letterCombinations(string digits) 
        {
            vector<string> result;
            if(digits.size()==0)return{};
            string temp="";
            recursion(0,digits,result, temp);
            if(stop)return {};
            return result;
        }
    
        void recursion(int index,string digits,vector<string>& result,string temp)//& temp  //backtrackstep
        {
            if(stop)return;
            if(index==digits.size())
            {
                result.emplace_back(temp);
                return;
            }
    
            char ch = digits[index];
            if(!isdigit(ch) || ch=='0' || ch=='1')
            {
                stop=true;
                return;
            }
    
            for(char letter:mp[ch])
            {
                //temp.push_back(letter); //backtrack step
                recursion(index+1,digits,result,temp+letter);
                // temp.pop_back();  // backtrack step
            }
        }
};

int main() {
    Solution sol;
    string input;
    
    cout << "Enter digit string (2-9 only): ";
    cin >> input;

    vector<string> combinations = sol.letterCombinations(input);

    if (combinations.empty()) {
        cout << "No valid combinations or invalid input." << endl;
    } else {
        cout << "Possible combinations are:\n";
        for (const string& s : combinations) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}