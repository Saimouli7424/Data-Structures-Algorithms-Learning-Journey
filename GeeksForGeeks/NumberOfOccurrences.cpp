//Number of occurence
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      int countFreq(vector<int>& arr, int target) {
          int left=0;
          int right=arr.size()-1;
          int lower=-1, upper=-1;
          
          while(left<=right)
          {
              int mid=(left+right)/2;
              if(arr[mid]==target)
              {
                  lower=mid;
                  right=mid-1;
              }
              else if(arr[mid]<target)
              {
                  left=mid+1;
              }
              else
              {
                   right=mid-1;
              }
          }
          if (lower == -1) return 0;
          left=0;
          right=arr.size()-1;
          while(left<=right)
          {
              int mid=(left+right)/2;
              if(arr[mid]==target)
              {
                  upper=mid;
                  left=mid+1;
              }
              else if(arr[mid]<target)
              {
                  left=mid+1;
              }
              else
              {
                  right=mid-1;
              }
          }
          
          return (upper-lower+1);
      }
  };

    int main(){
        Solution solution;
        vector<int>nums={5,7,7,8,8,10};
        int target=8;
        int result=solution.countFreq(nums,target);
        cout<<result;
    }