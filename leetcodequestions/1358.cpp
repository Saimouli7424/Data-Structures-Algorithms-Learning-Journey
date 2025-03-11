//Number of Substrings Containing All Three Characters (Medium level)
/*
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int numberOfSubstrings(string s){
        int n = s.size();
        int r=0;
        int count=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                count+=n-i;
                mp[s[r]]--;
                r++;
            }
        }
        return count;
    }
};

int main(){
    Solution obj;
    string s = "abcabc";
    cout<<obj.numberOfSubstrings(s)<<endl;
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)