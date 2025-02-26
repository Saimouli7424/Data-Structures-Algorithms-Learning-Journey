//leetcode 389
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
    public:
    char findTheDifference(string s, string t)
    {
            if(s.length()==0)return t[0];
            sort(t.begin(),t.end());
            sort(s.begin(),s.end());
            int i=0;
            while(i<s.length())
            {
                if(s[i]!=t[i])
                {
                    return t[i];
                }
                i++;
            }
            return t[i];
        }
    };

int main(){
    Solution sol;
    cout<<sol.findTheDifference("abcd","abcde")<<endl;
    cout<<sol.findTheDifference("","y")<<endl;
    cout<<sol.findTheDifference("dabc","acbde")<<endl;
    return 0;
}