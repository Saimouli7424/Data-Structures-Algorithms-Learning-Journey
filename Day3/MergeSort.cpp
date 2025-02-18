#include<bits/stdc++.h>
using namespace std;
void MS(vector<int> &arr,int low,int mid,int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high)
        {
            if(arr[left]<arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low;i<=high;i++)
        {
            arr[i] = temp[i-low];//it's for because temp will be reinitialized so it starts from 0 which can acquire by difference of low
        }
    }
    
    void mergeSort(vector<int>& arr, int low, int high)
    {
        if(low>=high)
        {
            return;
        }
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        MS(arr,low,mid,high);
    }

int main(){
        vector<int> arr = {12, 11, 13, 5, 6, 7};
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        cout << "Sorted array is: ";
        for (int i=0; i<n; ++i)
            cout << arr[i] << " ";
        return 0;
    }