//GeeksForGeeks
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
  
      int findFloor(vector<int>& arr, int x) {
          // Your code here
          int left = 0, right = arr.size() - 1;
          int floorIndex = -1;  // Store the index of the floor
      
          while (left <= right)
          {
              int mid = left + (right - left) / 2;
      
              if (arr[mid] <= x)
              {  
                  floorIndex = mid; // Store the current valid index
                  left = mid + 1;    // Search for a larger floor in the right half
              }
              else
              {
                  right = mid - 1;   // Search in the left half
              }
          }
      
      return floorIndex;
      }
  };
int main(){
    Solution obj;
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    cout<<obj.findFloor(arr, x);
    return 0;
}