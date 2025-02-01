#include<bits/stdc++.h>
using namespace std;
int maxvalue(vector<int> p)
{
    vector<int> q;
    vector<int> sorted_p = p;
    sort(sorted_p.begin(),sorted_p.end());

    int size = sorted_p.size();


    for(int i=0;i<size;i++){
        q.push_back((size-i));
    }
    

    vector<int> modified_p;
    for(int i=0;i<size;i++)
    {
        int value = sorted_p[i]+q[i];
        modified_p.push_back(value);
    }

    for(auto i: modified_p)
    {
        cout<<i;
    }

    vector<pair<int,int>> occurrences;
    set<int> counted;
    for(int i=0;i<size;i++)
    {
        if(counted.find(i)==counted.end())
        {
            counted.insert(i);
            occurrences.push_back({i,count(modified_p.begin(),modified_p.end(),i)});
        }
    }

    int maxi = 0;
    for(auto i: occurrences){
        maxi = max(maxi,i.second);
    }
    return maxi;
}


int main()
{
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    vector<int> p;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        p.push_back(x);
    }
    int max = maxvalue(p);
    cout<<"The maximum element of occurrences is: "<<max;
    return 0;
}