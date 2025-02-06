#include<iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for(int i=0;i<size;i++)
    {
        int min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    cout<<"The sorted array is: ";
    for(auto &i: arr){
        cout<<i<<" ";
    }
    return 0;
}