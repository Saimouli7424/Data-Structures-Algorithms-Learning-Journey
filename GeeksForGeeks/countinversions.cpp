//medium level

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to count inversions in the array.
      int inversionCount(vector<int> &arr) {
          return Sortfun(arr,0,arr.size()-1);
      }
      
      int Sortfun(vector<int>& arr,int low,int high){
          if(low>=high)return 0;
          int mid=(low+high)/2;
          int count=0;
          count+=Sortfun(arr,low,mid); //counting lowerbound inversions seperately
          count+=Sortfun(arr,mid+1,high);//couting upper bound inversions seperately
          count+=Mergesort(arr,low,mid,high);//couting while merging  inversions seperately
          //the inversions count only returns the first recursive call function count


          /*
            Why Not Just Use count += mergesort(arr1, low, mid, high);?
    If we only count during merging (mergesort), we will miss the inversions that are present inside each half before merging.

    🔹 Example: arr = {8, 4, 2, 1}
    Left half {8, 4} has 1 inversion: (8, 4)
    Right half {2, 1} has 1 inversion: (2, 1)
    Merging {4, 8} with {1, 2} finds 4 new inversions: (8,1), (8,2), (4,1), (4,2)
    Total inversions = 1 (left) + 1 (right) + 4 (merge) = 6
    If we only counted during the merge step, we'd miss the (8,4) and (2,1) inversions.
          */
          return count;
      }
      
      int Mergesort(vector<int>& arr,int low,int mid,int high)
      {
          vector<int> temp;
          int count=0;
          int left=low;
          int right=mid+1;
          while(left<=mid && right<=high)
          {
              if(arr[left]<=arr[right])
              {
                  temp.emplace_back(arr[left]);
                  left++;
              }else
              {
                  count+=(mid-left +1); //+1 for counting the index itself
                  temp.emplace_back(arr[right]);
                  right++;
              }
          }
          
          while(left<=mid)
          {
              temp.emplace_back(arr[left]);
              left++;
          }
          
          while(right<=high)
          {
              temp.emplace_back(arr[right]);
              right++;
          }
          
          for(int i=0;i<temp.size();i++)
          {
            arr[i+low]=temp[i];
          }
        
        return count;
      }
  };
int main() {
    Solution s;
    vector<int> arr = {8, 4, 2, 1};
    int result = s.inversionCount(arr);
    cout << "Total Inversions: " << result << endl;
    return 0;
}
