
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      vector<int> getFloorAndCeil(int x, vector<int> &arr) 
      {
          int val1=floorelem(x,arr);
          int val2=ceilelem(x,arr);
          vector<int>temp = {val1,val2};
          return temp;
      }
      int floorelem(int x, vector<int> &arr)
      {
          int floorelem=-1;
          int left=0;
          int right=arr.size()-1;
          while(left<=right)
          {
              int mid = (left+right)/2;
              // if(arr[mid]==x)return mid;
              if(arr[mid]<=x)
              {
                  floorelem=arr[mid];
                  left=mid+1;
              }else
              {
                  right=mid-1;
              }
          }
          return floorelem;
      }
      
      int ceilelem(int x, vector<int> &arr)
      {
        int ceilelem=-1;
          int left=0;
          int right=arr.size()-1;
          while(left<=right)
          {
              int mid = (left+right)/2;
              // if(arr[mid]==x)return mid;
              if(arr[mid]>=x)
              {
                  ceilelem=arr[mid];
                  right=mid-1;
              }else
              {
                  left=mid+1;
              }
          }
          return ceilelem;
      }
  };
  
  int main() {
    Solution s;
    vector<int> arr = {1, 2, 8, 10, 15};
    int x = 6;
    vector<int> result = s.getFloorAndCeil(x, arr);
    cout << "Floor of " << x << " is " << result[0] << endl;
    cout << "Ceiling of " << x << " is " << result[1] << endl;
    return 0;
  }