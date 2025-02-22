//BruteForce approach for character MapHashing
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter the word: ";
    cin>>s;
    unordered_map<char,int> hash;
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]++;
    }
    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--)
    {
        char x;
        cout<<"Enter the character to check occurrence: ";
        cin>>x;
        cout<<"For the character: "<<x<<" Occurred is: "<<hash[x]<<endl;
    }
    return 0;
}