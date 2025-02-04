#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> permutations;
    sort(arr.begin(), arr.end());
    permutations.push_back(arr);
    while(next_permutation(arr.begin(), arr.end()))
    {
        permutations.push_back(arr);
    }
    for(const auto& i: permutations)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}