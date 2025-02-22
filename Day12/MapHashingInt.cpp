//prints the occurrence of a number using MapHashing
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    map<int, int> mpp;
    cout<<"Enter the elements of an array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    // map<int, int> mpp;
    // for(int i=0;i<n;i++)
    // {
    //     mpp[arr[i]]++;
    // }

    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--)
    {
        int x;
        cout<<"Enter the number to check occurrence: ";
        cin>>x;
        cout<<"For the number: "<<x<<" Occurred is: "<<mpp[x]<<endl;
    }
    return 0;
}