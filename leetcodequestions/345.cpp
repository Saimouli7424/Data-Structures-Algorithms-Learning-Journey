//Reverse Vowels of a String(Medium)
//Two pointers
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        bool check(char ch){
            ch=tolower(ch);
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        }
        string reverseVowels(string s)
        {
            int left = 0, right = s.length() - 1;
    
            while (left < right) {
                if (check(s[left])) {
                    while (right > left && !check(s[right])) {
                        right--;
                    }
                    swap(s[left], s[right]);
                    right--;
                }
                left++;
            }
            return s;
        }
    };

int main(){
    Solution s;
    string str="IceCreAm";//AceCreIm
    cout<<s.reverseVowels(str);
    return 0;
}
