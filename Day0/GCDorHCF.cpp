#include<bits/stdc++.h>
using namespace std;
int main()
{
    int firstnum, secondnum;
    cout<<"Enter two numbers: ";
    cin>>firstnum>>secondnum;
    int minnum = min(firstnum, secondnum);
    int maxnum = max(firstnum, secondnum);
    while(minnum!=0)
    {
        int temp = minnum;
        minnum = maxnum%minnum;
        maxnum = temp;
    }
    cout<<"The GCD or HCF for the given numbers is: "<<maxnum<<endl;
    return 0;
}