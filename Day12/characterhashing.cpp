//bruteforce approach for character hashing
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter the word: ";
    cin>>s;
    int hash[26] = {0};
    //or
    //int hash[256] = {0}; for this no need to subtract 'a' or 'A'
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']++;
    }
    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--)
    {
        char x;
        cout<<"Enter the character to check occurrence: ";
        cin>>x;
        cout<<"For the character: "<<x<<" Occurred is: "<<hash[x-'a']<<endl;
    }
    return 0;
}