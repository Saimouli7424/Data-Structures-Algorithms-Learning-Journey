#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> occurrences;
    int arr[]= {2, 4, 2, 3, 7, 3, 7, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    set<int> counted;
    for(int i=0;i<size;i++)
    {
        int first = arr[i];
        if(counted.find(first)==counted.end()){ //if an element isn't found(counted.find(first)) than it returns counted.end()==counted.end() else it returns and iterator points towards the element
        int second = count(arr,arr+size,first); //count function returns the number of occurrences of the element in the array
            occurrences.push_back(make_pair(first,second));
            counted.insert(first);
        }
    }
    for(auto it: occurrences){
        cout<<it.first<<"occurs "<<it.second<<"times\n";
    }
    return 0;
}