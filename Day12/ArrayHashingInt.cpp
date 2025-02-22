//prints the occurrence of a number using ArrayHashing
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int hash[13] = {0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }

    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--)
    {
        int x;
        cout<<"Enter the number to check occurrence: ";
        cin>>x;
        cout<<"For the number: "<<x<<" Occurred is: "<<hash[x]<<endl;
    }
    return 0;
}